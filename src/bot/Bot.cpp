//
// Created by 17186 on 2/25/2023.
//

#include "Bot.h"
#include "google/protobuf/util/json_util.h"
#include "../ws/WebsocketController.h"

using namespace google::protobuf::util;


Bot::Bot(const drogon::WebSocketConnectionPtr &bot) {
    this->bot = bot;
}

std::shared_ptr<SendPrivateMsgResp>
Bot::sendPrivateMsg(const std::string &msg, const int64_t &user_id, bool auto_escape) {
    SendPrivateMsg builder;
    builder.set_action(Action::send_private_msg);

    auto *params = new SendPrivateMsg_Params();
    params->set_message(msg);
    params->set_user_id(user_id);
    params->set_auto_escape(auto_escape);
    builder.set_allocated_params(params);

    auto resp = this->sendAndWaitResp<SendPrivateMsgResp, SendPrivateMsg>(builder);
    return resp;
}

template<typename T, typename T2>
std::shared_ptr<T> Bot::sendAndWaitResp(T2 builder) {
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

std::shared_ptr<SendGroupMsgResp> Bot::sendGroupMsg(const std::string &msg, const int64_t &group_id, bool auto_escape) {
    SendGroupMsg builder;
    builder.set_action(cqhttp::send_group_msg);
    auto *params = new SendGroupMsg_Params();
    params->set_message(msg);
    params->set_group_id(group_id);
    params->set_auto_escape(auto_escape);
    builder.set_allocated_params(params);

    std::shared_ptr<SendGroupMsgResp> resp = this->sendAndWaitResp<SendGroupMsgResp, SendGroupMsg>(builder);
    return resp;
}
