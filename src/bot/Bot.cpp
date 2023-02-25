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
    auto *params = new SendPrivateMsg_Params();

    params->set_message(msg);
    params->set_user_id(user_id);
    params->set_auto_escape(auto_escape);
    builder.set_action(Action::send_private_msg);
    builder.set_allocated_params(params);

    auto resp = this->sendAndWaitResp<SendPrivateMsgResp>(builder);
    return resp ? resp : nullptr;
}

template<typename T, typename T2>
std::shared_ptr<T> Bot::sendAndWaitResp(T2 builder) {
    time_t echo;
    std::string echo_str = Action_Name(builder.action()) + "_" + std::to_string(time(&echo));
    builder.set_echo(echo_str);

    std::string builder_str;
    if (MessageToJsonString(builder, &builder_str, print_options).ok()) {
        this->m_mutex.lock();
        this->bot->send(builder_str);
        this->m_mutex.unlock();
    } else {
        return nullptr;
    }

    // Wait resp.
    time_t start_time;
    time_t end_time;
    time(&start_time);
    while (m_queue.empty()) {
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
        time(&end_time);
        if (end_time - start_time > 15) {
            return nullptr;
        }
    }
    BaseResp resp_s = m_queue.front();
    Json::Value resp_j;
    Json::FastWriter w;
    if (Json::Reader().parse(resp_s.resp, resp_j)) {
        if (resp_j["echo"] == builder.echo()) {
            auto resp_str = resp_s.resp;
            std::shared_ptr<SendPrivateMsgResp> resp_m(new SendPrivateMsgResp());
            m_queue.pop();
            return JsonStringToMessage(w.write(resp_j["data"]), resp_m.get(), parse_options).ok() ? resp_m : nullptr;
        }
    }
    return nullptr;
}
