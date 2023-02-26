//
// Created by 17186 on 2/25/2023.
//

#include "Bot.h"
#include "google/protobuf/util/json_util.h"
#include "../ws/WebsocketController.h"

using namespace google::protobuf::util;
using namespace cqhttp;


Bot::Bot(const drogon::WebSocketConnectionPtr &bot) {
    this->bot = bot;
}

std::shared_ptr<SendPrivateMsgResp>
Bot::sendPrivateMsg(const std::string &msg, const int64_t &user_id, bool auto_escape) {
    auto resp = this->sendMessage<SendPrivateMsgResp, SendMsg>(msg, user_id,
                                                               CQHTTP_TYPE::private_,
                                                               auto_escape);
    return resp;
}

template<typename T, typename T2>
std::shared_ptr<T> Bot::sendAndWaitResp(T2 &builder) {
    time_t echo;
    std::string echo_str = Action_Name(builder.action()) + "_" + std::to_string(time(&echo));
    builder.set_echo(echo_str);

    std::string builder_str;
    status_internal::Status status;
    status = MessageToJsonString(builder, &builder_str, print_options);
    if (!status.ok()) return nullptr;
    m_mutex.lock();
    bot->send(builder_str);
    m_mutex.unlock();

    std::shared_ptr<std::promise<std::string>> promisePtr = std::make_shared<std::promise<std::string>>();
    (*promiseMap)[echo_str] = promisePtr;
    std::future<std::string> future = promisePtr->get_future();
    future.wait_for(std::chrono::seconds(15));
    promiseMap->erase(echo_str);

    std::string resp = future.get();
    std::shared_ptr<T> msgResp = std::make_shared<T>();
    JsonStringToMessage(resp, msgResp.get(), parse_options);

    return msgResp;
}

std::shared_ptr<SendGroupMsgResp>
Bot::sendGroupMsg(const std::string &msg, const int64_t &group_id, bool auto_escape) {
    auto resp = this->sendMessage<SendGroupMsgResp, SendMsg>(msg, group_id,
                                                             CQHTTP_TYPE::group,
                                                             auto_escape);
    return resp;
}

template<typename T, typename T2>
std::shared_ptr<T>
Bot::sendMessage(const std::string &msg, const int64_t &receiver_id, const CQHTTP_TYPE &message_type,
                 bool auto_escape) {
    SendMsg builder;
    builder.set_action(Action::send_msg);

    auto *params = new SendMsg_Params();
    params->set_message(msg);
    if (message_type == CQHTTP_TYPE::group) params->set_group_id(receiver_id);
    if (message_type == CQHTTP_TYPE::private_) params->set_user_id(receiver_id);
    params->set_auto_escape(auto_escape);
    builder.set_allocated_params(params);

    auto resp = this->sendAndWaitResp<T, T2>(builder);
    return resp;
}

std::shared_ptr<cqhttp::GetMsgResp> Bot::getMessage(const int32_t &message_id) {
    GetMsg builder;
    builder.set_action(cqhttp::Action::get_msg);
    auto *params = new GetMsg_Params; // 不用手动 delete, 由 protobuf 为我们 delete
    params->set_message_id(message_id);
    builder.set_allocated_params(params);

    return this->sendAndWaitResp<GetMsgResp, GetMsg>(builder);
}

void Bot::deleteMsg(const int32_t &message_id) {
    DeleteMsg builder;
    builder.set_action(cqhttp::Action::delete_msg);
    DeleteMsg_Params *params = builder.mutable_params();
    params->set_message_id(message_id);

    this->sendOnly<DeleteMsg>(builder);
}

template<typename T>
void Bot::sendOnly(T &builder) {
    std::string builder_str;
    status_internal::Status status;
    status = MessageToJsonString(builder, &builder_str, print_options);

    if (!status.ok()) {
        LOG_INFO << "Failed to parse the message as string.";
        return;
    }
    m_mutex.lock();
    this->bot->send(builder_str);
    m_mutex.unlock();
}
