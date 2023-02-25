//
// Created by 17186 on 2/25/2023.
//

#ifndef CQ_WEBSOCKET_SERVER_BOT_H
#define CQ_WEBSOCKET_SERVER_BOT_H

#include "drogon/WebSocketConnection.h"
#include "../../pbf/built/cqhttp_api.pb.h"
#include "google/protobuf/util/json_util.h"

class Bot {
public:
    drogon::WebSocketConnectionPtr bot;

    explicit Bot(const drogon::WebSocketConnectionPtr &bot);

    /**
     * @brief 发送私聊信息
     * @param msg 消息内容
     * @param user_id 对方QQ号
     * @param auto_escape 消息内容是否作为纯文本发送 ( 即不解析 CQ 码 )
     * @return 成功响应消息ID
     */
    std::shared_ptr<cqhttp::SendPrivateMsgResp>
    sendPrivateMsg(const std::string &msg, const int64_t &user_id, bool auto_escape = false);

    /**
     * @brief 发送群聊消息
     * @param msg 要发送的内容
     * @param group_id 群号
     * @param auto_escape 消息内容是否作为纯文本发送 ( 即不解析 CQ 码 )
     * @return 成功响应消息ID
     */
    std::shared_ptr<cqhttp::SendGroupMsgResp>
    sendGroupMsg(const std::string &msg, const int64_t &group_id, bool auto_escape = false);


    template<typename T, typename T2>
    std::shared_ptr<T>
    sendMessage(const std::string &msg, const int64_t &receiver_id, const cqhttp::CQHTTP_TYPE &message_type,
                bool auto_escape = false);


private:
    std::mutex m_mutex;

    template<typename T, typename T2>
    std::shared_ptr<T> sendAndWaitResp(T2);
};


#endif //CQ_WEBSOCKET_SERVER_BOT_H
