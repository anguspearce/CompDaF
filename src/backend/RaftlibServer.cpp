#include <uWebSockets/App.h>

#include <string_view>

#include <carta-protobuf/register_viewer.pb.h>
#include <carta-protobuf/enums.pb.h>
#include "Session.h"

#include "EventHeader.h"
#include "Raftlib.h"

class RaftlibServer
{
public:
    /* ws->getUserData returns one of these */
    
    Session* s;
    void run()
    {
        uWS::App().ws<PerSocketData>("/*", {/* Settings */
            .compression = uWS::DEDICATED_COMPRESSOR_256KB,
            .maxPayloadLength = 16 * 1024 * 1024,
            .open = [&](uWS::WebSocket<false, true, PerSocketData>* ws)
            {
                OnConnect(ws);

            /* Open event here, you may access ws->getUserData() which points to a PerSocketData struct */ },
            .message = [&](uWS::WebSocket<false, true, PerSocketData>* ws, std::string_view message, uWS::OpCode opCode)
            {
                OnMessage(ws, message, opCode);
            },                                            
            .close = [](auto * /*ws*/, int /*code*/, std::string_view /*message*/)
            {
            /* You may access ws->getUserData() here */ }})
            .listen(9001, [](auto *listen_socket)
                    {
                        if (listen_socket)
                        {
                            std::cout << "Listening on port " << 9001 << std::endl;
                        }
                    })
            .run();
    }
    
    void OnConnect(uWS::WebSocket<false, true, PerSocketData>* ws){
    auto socket_data = ws->getUserData();

        uint32_t session_id = socket_data->session_id;
        std::string address = socket_data->address;
        s = new Session(ws);

    }

    void OnMessage(uWS::WebSocket<false, true, PerSocketData>* ws, std::string_view message, uWS::OpCode opCode){
        if (message.length() >= sizeof(carta::EventHeader))
        {
            carta::EventHeader head = *reinterpret_cast<const carta::EventHeader *>(message.data());
            const char *event_buf = message.data() + sizeof(carta::EventHeader);
            int event_length = message.length() - sizeof(carta::EventHeader);
            CARTA::EventType event_type = static_cast<CARTA::EventType>(head.type);
            std::cout << event_type << "!\n";

            switch (head.type)
            {
            case CARTA::EventType::REGISTER_VIEWER:
            {
                CARTA::RegisterViewer message;

                if (message.ParseFromArray(event_buf, event_length))
                {
                    s->OnRegisterViewer(message,head.icd_version, head.request_id);
                    // session->OnRegisterViewer(message, head.icd_version, head.request_id);
                }
                else
                {
                    std::cout<<"BAD" << std::endl;

                }
                break;
            }
            }
        }
        ws->send(message, opCode, true);
    }
};

int main()
{
    RaftlibServer server;
    server.run();
}
