//
// Created by 17186 on 2/25/2023.
//

#ifndef CQ_WEBSOCKET_SERVER_BOT_H
#define CQ_WEBSOCKET_SERVER_BOT_H

#include "drogon/WebSocketConnection.h"
#include "../../pbf/built/cqhttp_api.pb.h"
#include "google/protobuf/util/json_util.h"

using namespace cqhttp;

class Bot {
public:
    drogon::WebSocketConnectionPtr bot;

    explicit Bot(const drogon::WebSocketConnectionPtr &bot);

    std::shared_ptr<SendPrivateMsgResp>
    sendPrivateMsg(const std::string &msg, const int64_t &user_id, bool auto_escape = false);

private:
    std::mutex m_mutex;

    template<typename T, typename T2>
    std::shared_ptr<T> sendAndWaitResp(T2);
};


#endif //CQ_WEBSOCKET_SERVER_BOT_H
