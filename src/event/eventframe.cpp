//
// Created by 17186 on 2/22/2023.
//

#include "eventframe.h"
#include "../server.h"
#include "eventhandler.h"
#include "notice/FriendRecallEvent.h"
#include "notice/GroupRecallEvent.h"
#include "notice/GroupIncreaseEvent.h"
#include "notice/GroupDecreaseEvent.h"
#include "notice/GroupBanEvent.h"
#include "notice/GroupUploadEvent.h"
#include "notice/FriendAddEvent.h"
#include "notice/NotifyEvent.h"
#include "notice/OfflineFileEvent.h"
#include "notice/ClientStatusEvent.h"
#include "notice/EssenceEvent.h"
#include "notice/GroupCardEvent.h"

void EventClassification::eventClassification(const Json::Value &event) {
    if (event["post_type"] == PostType::MESSAGE) {
        EventClassification::messageClassification(event);
    }
    if (event["post_type"] == PostType::NOTICE) {
        EventClassification::noticeClassification(event);
    }
    if (event["post_type"] == PostType::META_EVENT) {
        EventClassification::metaEventClassification(event);
    }
    if (event["post_type"] == PostType::REQUEST) {
        EventClassification::requestClassification(event);
    }
}

void EventClassification::messageClassification(const Json::Value &event) {
    if (event["message_type"] == MessageType::GROUP) {
        std::shared_ptr<GroupMessageEvent> p_event = std::make_shared<GroupMessageEvent>(event);
        std::shared_ptr<Bot> p_bot = bots[event["self_id"].asInt64()];
        EventHandler::handleGroupMessage(p_bot, p_event);
    }
    if (event["message_type"] == MessageType::PRIVATE) {
        std::shared_ptr<PrivateMessageEvent> p_event = std::make_shared<PrivateMessageEvent>(event);
        std::shared_ptr<Bot> p_bot = bots[event["self_id"].asInt64()];
        EventHandler::handlePrivateMessage(p_bot, p_event);
    }
}

void EventClassification::requestClassification(const Json::Value &event) {
    if (event["request_type"].asString() == RequestType::GROUP) {
        std::shared_ptr<GroupRequestEvent> p_event = std::make_shared<GroupRequestEvent>(event);
        std::shared_ptr<Bot> p_bot = bots[event["self_id"].asInt64()];
        EventHandler::handleGroupRequest(p_bot, p_event);
    }
    if (event["request_type"].asString() == RequestType::FRIEND) {
        std::shared_ptr<FriendRequestEvent> p_event = std::make_shared<FriendRequestEvent>(event);
        std::shared_ptr<Bot> p_bot = bots[event["self_id"].asInt64()];
        EventHandler::handleFriendRequest(p_bot, p_event);
    }
}

void EventClassification::noticeClassification(const Json::Value &event) {
    std::string n_type = event["notice_type"].asString();
    if (n_type == NoticeType::FRIEND_RECALL) {
        std::shared_ptr<FriendRecallEvent> p_event = std::make_shared<FriendRecallEvent>(event);
        std::shared_ptr<Bot> p_bot = bots[p_event->self_id()];
        EventHandler::handleFriendRecall(p_bot, p_event);
    }
    if (n_type == NoticeType::GROUP_RECALL) {
        std::shared_ptr<GroupRecallEvent> p_event = std::make_shared<GroupRecallEvent>(event);
        std::shared_ptr<Bot> p_bot = bots[p_event->self_id()];
        EventHandler::handleGroupRecall(p_bot, p_event);
    }
    if (n_type == NoticeType::GROUP_INCREASE) {
        std::shared_ptr<GroupIncreaseEvent> p_event = std::make_shared<GroupIncreaseEvent>(event);
        std::shared_ptr<Bot> p_bot = bots[p_event->self_id()];
        EventHandler::handleGroupIncrease(p_bot, p_event);
    }
    if (n_type == NoticeType::GROUP_DECREASE) {
        std::shared_ptr<GroupDecreaseEvent> p_event = std::make_shared<GroupDecreaseEvent>(event);
        std::shared_ptr<Bot> p_bot = bots[p_event->self_id()];
        EventHandler::handleGroupDecrease(p_bot, p_event);
    }
    if (n_type == NoticeType::GROUP_ADMIN) {
        std::shared_ptr<GroupAdminEvent> p_event = std::make_shared<GroupAdminEvent>(event);
        std::shared_ptr<Bot> p_bot = bots[p_event->self_id()];
        EventHandler::handleGroupAdmin(p_bot, p_event);
    }
    if (n_type == NoticeType::GROUP_UPLOAD) {
        std::shared_ptr<GroupUploadEvent> p_event = std::make_shared<GroupUploadEvent>(event);
        std::shared_ptr<Bot> p_bot = bots[p_event->self_id()];
        EventHandler::handleGroupUpload(p_bot, p_event);
    }
    if (n_type == NoticeType::GROUP_BAN) {
        std::shared_ptr<GroupBanEvent> p_event = std::make_shared<GroupBanEvent>(event);
        std::shared_ptr<Bot> p_bot = bots[p_event->self_id()];
        EventHandler::handleGroupBan(p_bot, p_event);
    }
    if (n_type == NoticeType::FRIEND_ADD) {
        std::shared_ptr<FriendAddEvent> p_event = std::make_shared<FriendAddEvent>(event);
        std::shared_ptr<Bot> p_bot = bots[p_event->self_id()];
        EventHandler::handleFriendAdd(p_bot, p_event);
    }
    if (n_type == NoticeType::NOTIFY) {
        std::shared_ptr<NotifyEvent> p_event = std::make_shared<NotifyEvent>(event);
        std::shared_ptr<Bot> p_bot = bots[p_event->self_id()];
        EventHandler::handleNotify(p_bot, p_event);
    }
    if (n_type == NoticeType::OFFLINE_FILE) {
        std::shared_ptr<OfflineFileEvent> p_event = std::make_shared<OfflineFileEvent>(event);
        std::shared_ptr<Bot> p_bot = bots[p_event->self_id()];
        EventHandler::handleOfflineFile(p_bot, p_event);
    }
    if (n_type == NoticeType::CLIENT_STATUS) {
        std::shared_ptr<ClientStatusEvent> p_event = std::make_shared<ClientStatusEvent>(event);
        std::shared_ptr<Bot> p_bot = bots[p_event->self_id()];
        EventHandler::handleClientStatus(p_bot, p_event);
    }
    if (n_type == NoticeType::ESSENCE) {
        std::shared_ptr<EssenceEvent> p_event = std::make_shared<EssenceEvent>(event);
        std::shared_ptr<Bot> p_bot = bots[p_event->self_id()];
        EventHandler::handleEssence(p_bot, p_event);
    }
    if (n_type == NoticeType::GROUP_CARD) {
        std::shared_ptr<GroupCardEvent> p_event = std::make_shared<GroupCardEvent>(event);
        std::shared_ptr<Bot> p_bot = bots[p_event->self_id()];
        EventHandler::handleGroupCard(p_bot, p_event);
    }
}

void EventClassification::metaEventClassification(const Json::Value &event) {}

const std::string MessageType::GROUP = "group";
const std::string MessageType::PRIVATE = "private";
const std::string MessageType::SubType::FRIEND = "friend";
const std::string MessageType::SubType::NORMAL = "normal";
const std::string MessageType::SubType::ANONYMOUS = "anonymous";
const std::string MessageType::SubType::GROUP_SELF = "group_self";
const std::string MessageType::SubType::GROUP = "group";
const std::string MessageType::SubType::NOTICE = "notice";

const std::string NoticeType::FRIEND_RECALL = "friend_recall";
const std::string NoticeType::GROUP_RECALL = "group_recall";
const std::string NoticeType::GROUP_INCREASE = "group_increase";
const std::string NoticeType::GROUP_DECREASE = "group_decrease";
const std::string NoticeType::GROUP_ADMIN = "group_admin";
const std::string NoticeType::GROUP_UPLOAD = "group_upload";
const std::string NoticeType::GROUP_BAN = "group_ban";
const std::string NoticeType::FRIEND_ADD = "friend_add";
const std::string NoticeType::NOTIFY = "notify";
const std::string NoticeType::GROUP_CARD = "group_card";
const std::string NoticeType::OFFLINE_FILE = "offline_file";
const std::string NoticeType::CLIENT_STATUS = "client_status";
const std::string NoticeType::ESSENCE = "essence";

const std::string RequestType::FRIEND = "friend";
const std::string RequestType::GROUP = "group";