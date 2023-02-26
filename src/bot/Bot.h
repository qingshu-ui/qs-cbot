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

    /**
     * 发送消息
     * @tparam T 返回类型
     * @tparam T2 传入参数类型
     * @param msg 要发送的内容
     * @param receiver_id 对方 QQ 号 ( 消息类型为 private 时需要 )
     * @param message_type 消息类型, 支持 private、group , 分别对应私聊、群组, 如不传入, 则根据传入的 *_id 参数判断
     * @param auto_escape 消息内容是否作为纯文本发送 ( 即不解析 CQ 码 )
     * @return
     */
    template<typename T, typename T2>
    std::shared_ptr<T>
    sendMessage(const std::string &msg, const int64_t &receiver_id, const cqhttp::CQHTTP_TYPE &message_type,
                bool auto_escape = false);

    /**
     * @brief 获取消息
     * @param message_id 消息id
     * @return cqhttp::GetMsgResp
     */
    std::shared_ptr<cqhttp::GetMsgResp> getMessage(const int32_t &message_id);

    /**
     * @brief 撤回消息
     * @param message_id 消息 ID
     */
    void deleteMsg(const int32_t &message_id);


private:
    std::mutex m_mutex;

    template<typename T, typename T2>
    std::shared_ptr<T> sendAndWaitResp(T2 &);

    template<typename T>
    void sendOnly(T &builder);
};


#endif //CQ_WEBSOCKET_SERVER_BOT_H
