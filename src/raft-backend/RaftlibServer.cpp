#include <uWebSockets/App.h>

#include <string_view>

#include <carta-protobuf/register_viewer.pb.h>
#include <carta-protobuf/open_file.pb.h>
#include <carta-protobuf/region_requirements.pb.h>
#include <carta-protobuf/enums.pb.h>
#include "Session.h"

#include "EventHeader.h"

//#include "Raftlib.tcc"

class RaftlibServer
{
public:
    /* ws->getUserData returns one of these */

    Session *s;
    int numThreads;
    int portNumber;
    RaftlibServer(int portNum,int numt){
        numThreads=numt;
        portNumber=portNum;
    }
    /**
     * Method creates uWebSocket App with declared settings and calls the relevant handler functions.
     * 
     * 
     */
    void run()
    {
        uWS::App().ws<PerSocketData>("/*", {/* Settings */
                                            .compression = uWS::DEDICATED_COMPRESSOR_256KB,
                                            .maxPayloadLength = 16 * 1024 * 1024,
                                            .open = [&](uWS::WebSocket<false, true, PerSocketData> *ws)
                                            {
                                                OnConnect(ws);
                                                /* Open event here, you may access ws->getUserData() which points to a PerSocketData struct */
                                            },
                                            .message = [&](uWS::WebSocket<false, true, PerSocketData> *ws, std::string_view message, uWS::OpCode opCode)
                                            { OnMessage(ws, message, opCode); },
                                            .close = [](auto * /*ws*/, int /*code*/, std::string_view /*message*/)
                                            {
            /* You may access ws->getUserData() here */ }})
            .listen(portNumber, [&](auto *listen_socket)
                    {
                        if (listen_socket)
                        {
                            std::cout << "Listening on port " << portNumber << std::endl;
                        }
                    })
            .run();
    }

    /**
     * Sets up session when a new client connects.
     * 
     * 
     * @param ws The websocket of the new connection
     */
    void OnConnect(uWS::WebSocket<false, true, PerSocketData> *ws)
    {
        auto socket_data = ws->getUserData();

        uint32_t session_id = socket_data->session_id;
        std::string address = socket_data->address;
        s = new Session(ws,numThreads);
    }

    /**
     * Receives every message incoming from the websocket and handles it accordingly.
     * Will call the methods to handle protobuffers that are passed through.
     * 
     * @param ws The websocket 
     * @param message The message received
     * @param opCode 
     */
    void OnMessage(uWS::WebSocket<false, true, PerSocketData> *ws, std::string_view message, uWS::OpCode opCode)
    {
        if (message.length() >= sizeof(carta::EventHeader))
        {
            carta::EventHeader head = *reinterpret_cast<const carta::EventHeader *>(message.data());
            const char *event_buf = message.data() + sizeof(carta::EventHeader);
            int event_length = message.length() - sizeof(carta::EventHeader);
            CARTA::EventType event_type = static_cast<CARTA::EventType>(head.type);
            //std::cout << event_type << "!\n";

            switch (head.type)
            {
            case CARTA::EventType::REGISTER_VIEWER:
            {
                CARTA::RegisterViewer message;

                if (message.ParseFromArray(event_buf, event_length))
                {
                    s->OnRegisterViewer(message, head.icd_version, head.request_id);
                    // session->OnRegisterViewer(message, head.icd_version, head.request_id);
                }
                else
                {
                    std::cout << "BAD" << std::endl;
                }
                break;
            }
            case CARTA::EventType::OPEN_FILE:
            {
                CARTA::OpenFile message;

                if (message.ParseFromArray(event_buf, event_length))
                {
                    s->OnOpenFile(message, head.request_id);
                }
                break;
            }
            case CARTA::EventType::SET_HISTOGRAM_REQUIREMENTS:
            {
                CARTA::SetHistogramRequirements message;
                if (message.ParseFromArray(event_buf, event_length))
                {
                    s->OnSetRegionHistogramRequirements(message, head.request_id);
                }
                break;
            }
            case CARTA::EventType::SET_STATS_REQUIREMENTS:
            {
                CARTA::SetStatsRequirements message;
                if (message.ParseFromArray(event_buf, event_length))
                {
                    s->OnSetRegionStatsRequirements(message, head.request_id);
                }
                break;
            }
            }
        }
        //ws->send(message, opCode, true);
    }
};

/**
 * Simple main method to create a server object and start it.
 */
int main(int argc, char* argv[])
{
    if(argc < 3){
        std::cout<<"Please specify the port number and number of threads \n./raftlib-server PORTNUMBER NUMTHREADS\nExample : ./raftlib-server 9001 5"<<std::endl;
        return 1;
    }
    else if(argc > 3){
        std::cout<<"Invalid arguments \n./raftlib-server PORTNUMBER NUMTHREADS\nExample : ./raftlib-server 9001 5"<<std::endl;
        return 1;
    }
    RaftlibServer server(atoi(argv[1]),atoi(argv[2]));
    server.run();
}
