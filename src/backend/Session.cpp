#include "Session.h"

#include <carta-protobuf/defs.pb.h>
#include "EventHeader.h"

Session::Session(uWS::WebSocket<false, true, PerSocketData>* ws) : _socket(ws){
    _connected = true;

}

void Session::OnRegisterViewer(const CARTA::RegisterViewer& message, uint16_t icd_version, uint32_t request_id) {
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
void Session::SendEvent(CARTA::EventType event_type, uint32_t event_id, const google::protobuf::MessageLite& message, bool compress) {
    size_t message_length = message.ByteSizeLong();
    size_t required_size = message_length + sizeof(carta::EventHeader);
    std::pair<std::vector<char>, bool> msg_vs_compress;
    std::vector<char>& msg = msg_vs_compress.first;
    msg.resize(required_size, 0);
    carta::EventHeader* head = (carta::EventHeader*)msg.data();

    head->type = event_type;
    head->icd_version = carta::ICD_VERSION;
    head->request_id = event_id;
    message.SerializeToArray(msg.data() + sizeof(carta::EventHeader), message_length);
    
    // Skip compression on files smaller than 1 kB
    msg_vs_compress.second = compress && required_size > 1024;
    _out_msgs.push(msg_vs_compress);
    
    if(true){
    std::pair<std::vector<char>, bool> msg;
    if (_connected) {
            while (_out_msgs.try_pop(msg)) {
                std::string_view sv(msg.first.data(), msg.first.size());
                auto status = _socket->send(sv, uWS::OpCode::BINARY, msg.second);
                if (status == uWS::WebSocket<false, true, PerSocketData>::DROPPED) {
                    std::cout << "Failed to send message of size {} kB" << sv.size() / 1024.0 << "!\n";

                }
            }
        }
    }
}