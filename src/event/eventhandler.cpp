//
// Created by 17186 on 2/22/2023.
//

#include "eventhandler.h"
#include "trantor/utils/Logger.h"

void EventHandler::handlePrivateMessage(const std::shared_ptr<Bot> &bot,
                                        const std::shared_ptr<PrivateMessageEvent> &e) {
    LOG_INFO << "收到来自：" << e->user_id() << " 的消息：" << e->message();
    if (e->user_id() == 1718692748) {
        Msg builder;
        builder.setMessage("宝，晚上好！");
        auto resp = bot->sendPrivateMsg(builder, e->user_id());
        if (nullptr != resp) {
            LOG_INFO << "发送私聊消息成功，消息ID: " << resp->message_id();
        }
    }
}

void
EventHandler::handleGroupMessage(const std::shared_ptr<Bot> &bot, const std::shared_ptr<GroupMessageEvent> &e) {
    LOG_INFO << "收到来自群(" << e->group_id() << ")(" << e->user_id() << ")的消息：" << e->message();
    auto message_info = bot->getMsg(e->message_id());
    if (nullptr != message_info) {

        // Print for group message.
        std::ostringstream info;
        info << "发送者: " << message_info->sender().user_id() << std::endl
             << "昵称: " << message_info->sender().nickname() << std::endl
             << "消息内容: " << message_info->message();

        // Send group message to private.
        Msg builder;
        builder.setMessage(info.str());
        auto p_resp = bot->sendPrivateMsg(builder, 1718692748);
        if (nullptr != p_resp) {
            LOG_INFO << "发送私聊消息成功，消息ID: " << p_resp->message_id();
        }
    }

}

void
EventHandler::handleFriendRequest(const std::shared_ptr<Bot> &bot, const std::shared_ptr<FriendRequestEvent> &e) {

}

void
EventHandler::handleGroupRequest(const std::shared_ptr<Bot> &bot, const std::shared_ptr<GroupRequestEvent> &e) {

}

void EventHandler::handleFriendRecall(const std::shared_ptr<Bot> &bot, const std::shared_ptr<FriendRecallEvent> &e) {

}

void EventHandler::handleGroupRecall(const std::shared_ptr<Bot> &bot, const std::shared_ptr<GroupRecallEvent> &e) {

}

void EventHandler::handleGroupIncrease(const std::shared_ptr<Bot> &bot, const std::shared_ptr<GroupIncreaseEvent> &e) {

}

void EventHandler::handleGroupDecrease(const std::shared_ptr<Bot> &bot, const std::shared_ptr<GroupDecreaseEvent> &e) {

}

void EventHandler::handleGroupAdmin(const std::shared_ptr<Bot> &bot, const std::shared_ptr<GroupAdminEvent> &e) {

}

void EventHandler::handleGroupUpload(const std::shared_ptr<Bot> &bot, const std::shared_ptr<GroupUploadEvent> &e) {

}

void EventHandler::handleGroupBan(const std::shared_ptr<Bot> &bot, const std::shared_ptr<GroupBanEvent> &e) {

}

void EventHandler::handleFriendAdd(const std::shared_ptr<Bot> &bot, const std::shared_ptr<FriendAddEvent> &e) {

}

void EventHandler::handleNotify(const std::shared_ptr<Bot> &bot, const std::shared_ptr<NotifyEvent> &e) {

}

void EventHandler::handleGroupCard(const std::shared_ptr<Bot> &bot, const std::shared_ptr<GroupCardEvent> &e) {

}

void EventHandler::handleOfflineFile(const std::shared_ptr<Bot> &bot, const std::shared_ptr<OfflineFileEvent> &e) {

}

void EventHandler::handleClientStatus(const std::shared_ptr<Bot> &bot, const std::shared_ptr<ClientStatusEvent> &e) {

}

void EventHandler::handleEssence(const std::shared_ptr<Bot> &bot, const std::shared_ptr<EssenceEvent> &e) {

}
