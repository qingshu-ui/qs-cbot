//
// Created by 17186 on 2/22/2023.
//

#ifndef CQHTTP_EVENTHANDLER_H
#define CQHTTP_EVENTHANDLER_H

#include <memory>
#include "../bot/Bot.h"
#include "message/PrivateMessageEvent.h"
#include "message/GroupMessageEvent.h"
#include "request/FriendRequestEvent.h"
#include "request/GroupRequestEvent.h"
#include "notice/FriendRecallEvent.h"
#include "notice/GroupRecallEvent.h"
#include "notice/GroupIncreaseEvent.h"
#include "notice/GroupDecreaseEvent.h"
#include "notice/GroupAdminEvent.h"
#include "notice/GroupUploadEvent.h"
#include "notice/GroupBanEvent.h"
#include "notice/FriendAddEvent.h"
#include "notice/NotifyEvent.h"
#include "notice/OfflineFileEvent.h"
#include "notice/ClientStatusEvent.h"
#include "notice/EssenceEvent.h"
#include "notice/GroupCardEvent.h"

namespace EventHandler {
    void handlePrivateMessage(const std::shared_ptr<Bot> &bot, const std::shared_ptr<PrivateMessageEvent> &e);

    void handleGroupMessage(const std::shared_ptr<Bot> &bot, const std::shared_ptr<GroupMessageEvent> &e);

    void handleFriendRequest(const std::shared_ptr<Bot> &bot, const std::shared_ptr<FriendRequestEvent> &e);

    void handleGroupRequest(const std::shared_ptr<Bot> &bot, const std::shared_ptr<GroupRequestEvent> &e);

    void handleFriendRecall(const std::shared_ptr<Bot> &bot, const std::shared_ptr<FriendRecallEvent> &e);

    void handleGroupRecall(const std::shared_ptr<Bot> &bot, const std::shared_ptr<GroupRecallEvent> &e);

    void handleGroupIncrease(const std::shared_ptr<Bot> &bot, const std::shared_ptr<GroupIncreaseEvent> &e);

    void handleGroupDecrease(const std::shared_ptr<Bot> &bot, const std::shared_ptr<GroupDecreaseEvent> &e);

    void handleGroupAdmin(const std::shared_ptr<Bot> &bot, const std::shared_ptr<GroupAdminEvent> &e);

    void handleGroupUpload(const std::shared_ptr<Bot> &bot, const std::shared_ptr<GroupUploadEvent> &e);

    void handleGroupBan(const std::shared_ptr<Bot> &bot, const std::shared_ptr<GroupBanEvent> &e);

    void handleFriendAdd(const std::shared_ptr<Bot> &bot, const std::shared_ptr<FriendAddEvent> &e);

    void handleNotify(const std::shared_ptr<Bot> &bot, const std::shared_ptr<NotifyEvent> &e);

    void handleGroupCard(const std::shared_ptr<Bot> &bot, const std::shared_ptr<GroupCardEvent> &e);

    void handleOfflineFile(const std::shared_ptr<Bot> &bot, const std::shared_ptr<OfflineFileEvent> &e);

    void handleClientStatus(const std::shared_ptr<Bot> &bot, const std::shared_ptr<ClientStatusEvent> &e);

    void handleEssence(const std::shared_ptr<Bot> &bot, const std::shared_ptr<EssenceEvent> &e);
}

#endif //CQHTTP_EVENTHANDLER_H
