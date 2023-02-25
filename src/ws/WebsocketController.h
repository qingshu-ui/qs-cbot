//
// Created by 17186 on 2/24/2023.
//

#ifndef CQ_WEBSOCKET_SERVER_WEBSOCKETCONTROLLER_H
#define CQ_WEBSOCKET_SERVER_WEBSOCKETCONTROLLER_H

#include "drogon/WebSocketController.h"
#include "google/protobuf/util/json_util.h"
#include <queue>

struct BaseResp {
    std::string resp;
};

extern BaseResp m_resp;
extern std::queue<BaseResp> m_queue;
extern google::protobuf::util::JsonPrintOptions print_options;
extern google::protobuf::util::JsonParseOptions parse_options;

class WebsocketController : public drogon::WebSocketController<WebsocketController> {
public:
    void handleNewMessage(const drogon::WebSocketConnectionPtr &ptr, std::string &&string,
                          const drogon::WebSocketMessageType &messageType) override;

    void handleNewConnection(const drogon::HttpRequestPtr &ptr,
                             const drogon::WebSocketConnectionPtr &connectionPtr) override;

    void handleConnectionClosed(const drogon::WebSocketConnectionPtr &ptr) override;

    static void initPathRouting() {
        registerSelf__("/", {});
    }
};


#endif //CQ_WEBSOCKET_SERVER_WEBSOCKETCONTROLLER_H
