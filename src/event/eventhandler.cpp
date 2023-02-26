//
// Created by 17186 on 2/25/2023.
//

#include "eventhandler.h"
#include <trantor/utils/Logger.h>
#include <sstream>
#include "../ws/WebsocketController.h"

using namespace google::protobuf::util;


void
EventHandler::handlePrivateMessage(const std::shared_ptr<Bot> &bot, const std::shared_ptr<PrivateMessageEvent> &e) {
    std::ostringstream out;
    out << "Received a new private message: \n"
        << "Nick_Name: " << e->sender().nickname() << "\n"
        << "QQ_Id: " << e->sender().user_id() << "\n"
        << "Content: " << e->message();
    LOG_INFO << out.str();
    auto resp = bot->sendPrivateMsg(out.str(), e->user_id());
    if (nullptr != resp) {
        LOG_INFO << "Send private msg is successfully. id: " << resp->message_id();
    }
}

void EventHandler::handleGroupMessage(const std::shared_ptr<Bot> &bot, const std::shared_ptr<GroupMessageEvent> &e) {
    std::ostringstream out;
    out << "Received a new group message: \n"
        << "Nick_Name: " << e->sender().nickname() << "\n"
        << "QQ_Id: " << e->sender().user_id() << "\n"
        << "Content: " << e->message();
    LOG_INFO << out.str();

    auto relay_resp = bot->sendPrivateMsg(out.str(), 1718692748);
    LOG_INFO << (relay_resp ? "Relay the message is OK, id: " + std::to_string(relay_resp->message_id()) : "");


    if (e->user_id() == 1718692748) {

        if (e->message() == "宝，撤回我这条消息吧！") {
            bot->deleteMsg(e->message_id());
            return;
        }

        auto resp = bot->sendGroupMsg("宝，当海王真不好，当海王事不少，天天都有人找，好烦恼好烦恼~", e->group_id());
        if (nullptr != resp) {
            LOG_INFO << "Send group message is successfully, id: " << resp->message_id();
        }
    }
}

void
EventHandler::handleFriendAddRequest(const std::shared_ptr<Bot> &bot, const std::shared_ptr<FriendAddRequestEvent> &e) {

}

void
EventHandler::handleGroupAddRequest(const std::shared_ptr<Bot> &bot, const std::shared_ptr<GroupAddRequestEvent> &e) {

}

void EventHandler::handleFriendRecall(const std::shared_ptr<Bot> &bot, const std::shared_ptr<FriendRecallEvent> &e) {

}

void EventHandler::handleGroupRecall(const std::shared_ptr<Bot> &bot, const std::shared_ptr<GroupRecallEvent> &e) {
    std::ostringstream msg;
    auto message_info = bot->getMessage((int32_t) e->message_id());

    struct tm info{};
    time_t t = message_info->time();
    char buffer[80];
    localtime_s(&info, &t);
    strftime(buffer, sizeof buffer, "%H:%M:%S", &info);

    msg << "Message recall detected." << std::endl << std::endl
        << "Sender_ID: " << message_info->sender().user_id() << std::endl
        << "Sender_Name: " << message_info->sender().nickname() << std::endl
        << "Message_Text: " << message_info->message() << std::endl << std::endl
        << "Recall_Time: " << buffer;


    bot->sendGroupMsg(msg.str(), e->group_id());
}

void EventHandler::handleGroupIncrease(const std::shared_ptr<Bot> &bot, const std::shared_ptr<GroupIncreaseEvent> &e) {

}

void EventHandler::handleGroupDecrease(const std::shared_ptr<Bot> &bot, const std::shared_ptr<GroupDecreaseEvent> &e) {

}

void EventHandler::handleGroupAdminChanged(const std::shared_ptr<Bot> &bot,
                                           const std::shared_ptr<GroupAdminChangeEvent> &e) {

}

void
EventHandler::handleGroupFileUploaded(const std::shared_ptr<Bot> &bot, const std::shared_ptr<GroupFileUploadEvent> &e) {

}

void EventHandler::handleGroupBan(const std::shared_ptr<Bot> &bot, const std::shared_ptr<GroupBanEvent> &e) {

}

void EventHandler::handleFriendAdd(const std::shared_ptr<Bot> &bot, const std::shared_ptr<FriendAddEvent> &e) {

}

void EventHandler::handleNotify(const std::shared_ptr<Bot> &bot, const std::shared_ptr<NotifyEvent> &e) {

}

void
EventHandler::handleGroupCardChanged(const std::shared_ptr<Bot> &bot, const std::shared_ptr<GroupCardChangedEvent> &e) {

}

void EventHandler::handleReceivedOfflineFile(const std::shared_ptr<Bot> &bot,
                                             const std::shared_ptr<ReceviedOfflineFileEvent> &e) {

}

void
EventHandler::handleClientStatusChanged(const std::shared_ptr<Bot> &bot, const std::shared_ptr<ClientChangedEvent> &e) {

}

void
EventHandler::handleEssenceChanged(const std::shared_ptr<Bot> &bot, const std::shared_ptr<EssenceMsgChangedEvent> &e) {

}
