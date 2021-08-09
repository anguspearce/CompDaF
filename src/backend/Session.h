/* This file is part of the CARTA Image Viewer: https://github.com/CARTAvis/carta-backend
   Copyright 2018, 2019, 2020, 2021 Academia Sinica Institute of Astronomy and Astrophysics (ASIAA),
   Associated Universities, Inc. (AUI) and the Inter-University Institute for Data Intensive Astronomy (IDIA)
   SPDX-License-Identifier: GPL-3.0-or-later
*/

//# Session.h: representation of a client connected to a server; processes requests from frontend
//This is an eddited version of the original Session.h file for the CompDaF project

#include <tbb/concurrent_queue.h>
#include <tbb/concurrent_unordered_map.h>
#include <tbb/task.h>
#include <uWebSockets/App.h>
#include <carta-protobuf/register_viewer.pb.h>
#include <carta-protobuf/open_file.pb.h>
#include <carta-protobuf/tiles.pb.h>

struct PerSocketData {
    uint32_t session_id;
    std::string address;
};
class Session {
public:
    Session(uWS::WebSocket<false, true, PerSocketData>* ws);
    ~Session();

    // CARTA ICD
    void OnRegisterViewer(const CARTA::RegisterViewer& message, uint16_t icd_version, uint32_t request_id);
    void OnOpenFile(const CARTA::OpenFile& message, uint32_t request_id);

    // Sending Protobuf Messages
    void SendEvent(CARTA::EventType event_type, u_int32_t event_id, const google::protobuf::MessageLite& message, bool compress = true);

    // Task handling
    uWS::WebSocket<false, true, PerSocketData>* _socket;

    // message queue <msg, compress>
    tbb::concurrent_queue<std::pair<std::vector<char>, bool>> _out_msgs;
    
    bool _connected;

};