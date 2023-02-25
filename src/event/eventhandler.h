//
// Created by 17186 on 2/25/2023.
//

#ifndef CQ_WEBSOCKET_SERVER_EVENTHANDLER_H
#define CQ_WEBSOCKET_SERVER_EVENTHANDLER_H

#include <memory>
#include "../bot/Bot.h"
#include "../../pbf/built/cqhttp_event.pb.h"

using namespace cqhttp;

namespace EventHandler {

    void handlePrivateMessage(const std::shared_ptr<Bot> &bot, const std::shared_ptr<PrivateMessageEvent> &e);

    void handleGroupMessage(const std::shared_ptr<Bot> &bot, const std::shared_ptr<GroupMessageEvent> &e);

    void handleFriendAddRequest(const std::shared_ptr<Bot> &bot, const std::shared_ptr<FriendAddRequestEvent> &e);

    void handleGroupAddRequest(const std::shared_ptr<Bot> &bot, const std::shared_ptr<GroupAddRequestEvent> &e);

    void handleFriendRecall(const std::shared_ptr<Bot> &bot, const std::shared_ptr<FriendRecallEvent> &e);

    void handleGroupRecall(const std::shared_ptr<Bot> &bot, const std::shared_ptr<GroupRecallEvent> &e);

    void handleGroupIncrease(const std::shared_ptr<Bot> &bot, const std::shared_ptr<GroupIncreaseEvent> &e);

    void handleGroupDecrease(const std::shared_ptr<Bot> &bot, const std::shared_ptr<GroupDecreaseEvent> &e);

    void handleGroupAdminChanged(const std::shared_ptr<Bot> &bot, const std::shared_ptr<GroupAdminChangeEvent> &e);

    void handleGroupFileUploaded(const std::shared_ptr<Bot> &bot, const std::shared_ptr<GroupFileUploadEvent> &e);

    void handleGroupBan(const std::shared_ptr<Bot> &bot, const std::shared_ptr<GroupBanEvent> &e);

    void handleFriendAdd(const std::shared_ptr<Bot> &bot, const std::shared_ptr<FriendAddEvent> &e);

    void handleNotify(const std::shared_ptr<Bot> &bot, const std::shared_ptr<NotifyEvent> &e);

    void handleGroupCardChanged(const std::shared_ptr<Bot> &bot, const std::shared_ptr<GroupCardChangedEvent> &e);

    void handleReceivedOfflineFile(const std::shared_ptr<Bot> &bot, const std::shared_ptr<ReceviedOfflineFileEvent> &e);

    void handleClientStatusChanged(const std::shared_ptr<Bot> &bot, const std::shared_ptr<ClientChangedEvent> &e);

    void handleEssenceChanged(const std::shared_ptr<Bot> &bot, const std::shared_ptr<EssenceMsgChangedEvent> &e);
}



#endif //CQ_WEBSOCKET_SERVER_EVENTHANDLER_H
