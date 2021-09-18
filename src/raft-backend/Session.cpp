#include "Session.h"
#include "EventHeader.h"

// Constructor for session class
Session::Session(uWS::WebSocket<false, true, PerSocketData> *ws) : _socket(ws)
{
    _connected = true;
}

/* 
    RegisterViewer ICD
    Respondes with a register viewer acknowledgement
*/
void Session::OnRegisterViewer(const CARTA::RegisterViewer &message, uint16_t icd_version, uint32_t request_id)
{
    auto session_id = message.session_id();
    bool success(true);
    std::string status;

    // response
    CARTA::RegisterViewerAck ack_message;
    ack_message.set_session_id(session_id);
    ack_message.set_success(success);
    ack_message.set_message(status);

    // Send protobuf message to client
    SendEvent(CARTA::EventType::REGISTER_VIEWER_ACK, request_id, ack_message);
}

/*
    Open file ICD
    This method gets the fields required in the open file acknowledge.
    It will create an instance of FitsReader if the requested file is found the search directory.    
*/
void Session::OnOpenFile(const CARTA::OpenFile &message, uint32_t request_id)
{
    const auto &directory = message.directory();
    const auto &fileName = message.file();
    auto file_id(message.file_id());
    std::string filePath = directory + fileName;
    CARTA::FileInfo file_info;
    CARTA::FileInfoExtended file_info_ext;

    //check if file exists
    bool success(false);
    std::ifstream f(filePath.c_str());
    if (f.good())
    {
        success = true;

        std::vector<std::string> hdu_list;
        std::string fName;
        int64_t fSize;
        int naxis, width, height, depth;
        long naxes[3] = {1, 1, 1};

        std::string messageOut;
        std::vector<CARTA::HeaderEntry> headerEntries;
        fitsFile = new FitsReader(filePath);

        //Getting file_info
        fitsFile->FillFileInfo(hdu_list, fName, fSize, naxis, naxes, headerEntries, messageOut);
        width = naxes[0];
        height = naxes[1];
        depth = naxes[2];
        //File info

        file_info.set_name(fName);
        file_info.set_size(fSize);
        file_info.set_type(CARTA::FileType::FITS);
        file_info.add_hdu_list(hdu_list[0]);

        //File info extended
        file_info_ext.set_dimensions(naxis);
        file_info_ext.set_width(width);
        file_info_ext.set_height(height);
        file_info_ext.set_depth(depth);
        for (int i = 0; i < headerEntries.size(); i++)
        {
            auto header_entry = file_info_ext.add_header_entries();
            header_entry->set_name(headerEntries[i].name());
            header_entry->set_value(headerEntries[i].value());
            header_entry->set_comment(headerEntries[i].comment());
        }
        fitsFile->readImagePixels();
    }
    CARTA::OpenFileAck ack_message;
    ack_message.set_success(success);
    ack_message.set_file_id(file_id);
    *ack_message.mutable_file_info() = file_info;
    *ack_message.mutable_file_info_extended() = file_info_ext;

    
    // Send protobuf message to client
    SendEvent(CARTA::EventType::OPEN_FILE_ACK, request_id, ack_message);

    //Reading image pixels for region_histogram_data
    CARTA::RegionHistogramData &regionHistoData = fitsFile->getRegionHistoData();
    regionHistoData.set_file_id(file_id);
    regionHistoData.set_region_id(-1);

    SendEvent(CARTA::EventType::REGION_HISTOGRAM_DATA, request_id, regionHistoData);
}
/*
    CARTA ICD that will return region histogram data 
*/
void Session::OnSetRegionHistogramRequirements(const CARTA::SetHistogramRequirements &message, uint32_t request_id)
{

    auto file_id(message.file_id());
    //Reading image pixels for region_histogram_data
    CARTA::RegionHistogramData &regionHistoData = fitsFile->getRegionHistoData();
    regionHistoData.set_file_id(file_id);
    regionHistoData.set_region_id(-1);

    SendEvent(CARTA::EventType::REGION_HISTOGRAM_DATA, request_id, regionHistoData);
}
/*
    CARTA ICD that will return region statistics data 
*/
void Session::OnSetRegionStatsRequirements(const CARTA::SetStatsRequirements &message, uint32_t request_id)
{
    auto file_id(message.file_id());
    //Region statistics data
    CARTA::RegionStatsData &regionStatsData = fitsFile->getRegionStatsData();
    regionStatsData.set_file_id(file_id);
    regionStatsData.set_region_id(-1);

    SendEvent(CARTA::EventType::REGION_STATS_DATA, request_id, regionStatsData);
}
/*
    Sending an event through a socket
*/
void Session::SendEvent(CARTA::EventType event_type, uint32_t event_id, const google::protobuf::MessageLite &message, bool compress)
{
    size_t message_length = message.ByteSizeLong();
    size_t required_size = message_length + sizeof(carta::EventHeader);
    std::pair<std::vector<char>, bool> msg_vs_compress;
    std::vector<char> &msg = msg_vs_compress.first;
    msg.resize(required_size, 0);
    carta::EventHeader *head = (carta::EventHeader *)msg.data();
    head->type = event_type;
    head->icd_version = carta::ICD_VERSION;
    head->request_id = event_id;
    message.SerializeToArray(msg.data() + sizeof(carta::EventHeader), message_length);

    // Skip compression on files smaller than 1 kB
    msg_vs_compress.second = compress && required_size > 1024;
    _out_msgs.push(msg_vs_compress);

    if (true)
    {
        std::pair<std::vector<char>, bool> msg;
        if (_connected)
        {
            while (_out_msgs.try_pop(msg))
            {
                std::string_view sv(msg.first.data(), msg.first.size());
                auto status = _socket->send(sv, uWS::OpCode::BINARY, msg.second);
                if (status == uWS::WebSocket<false, true, PerSocketData>::DROPPED)
                {
                    std::cout << "Failed to send message of size {} kB" << sv.size() / 1024.0 << "!\n";
                }
            }
        }
    }
}