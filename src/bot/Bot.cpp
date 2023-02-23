//
// Created by 17186 on 2/22/2023.
//

#include "Bot.h"

#include <memory>
#include "../server.h"
#include "actions/Actions.h"
#include "../msg/Msg.h"
#include "../event/eventframe.h"
#include "resp/ImageInfoResp.h"

Bot::Bot(const drogon::WebSocketConnectionPtr &bot) {
    this->p_bot = bot;
}

drogon::WebSocketConnectionPtr &Bot::getRawBot() {
    return this->p_bot;
}

std::shared_ptr<PrivateMessageResp> Bot::sendPrivateMsg(Msg &m, const int64_t &user_id, bool auto_escape) {
    this->build(m, Action::SEND_PRIVATE_MSG);
    m.setUserId(user_id);
    m.setAutoEscape(auto_escape);
    std::shared_ptr<PrivateMessageResp> p_resp = this->sendAndWaitResp<PrivateMessageResp>(m);
    return p_resp ? p_resp : nullptr;
}

std::shared_ptr<GroupMessageResp> Bot::sendGroupMsg(Msg &m, const int64_t &group_id, bool auto_escape) {
    this->build(m, Action::SEND_GROUP_MSG);
    m.setGroupId(group_id);
    m.setAutoEscape(auto_escape);
    std::shared_ptr<GroupMessageResp> p_resp = this->sendAndWaitResp<GroupMessageResp>(m);
    return p_resp ? p_resp : nullptr;
}

std::shared_ptr<GroupForwardMsgResp>
Bot::sendGroupForwardMsg(Msg &m, const int64_t &group_id, bool auto_escape) {
    this->build(m, Action::SEND_GROUP_FORWARD_MSG);
    m.setGroupId(group_id);
    std::shared_ptr<GroupForwardMsgResp> p_resp = this->sendAndWaitResp<GroupForwardMsgResp>(m);
    return p_resp ? p_resp : nullptr;
}

std::shared_ptr<MessageResp>
Bot::sendMsg(Msg &m, const int64_t &receive_id, const char *msgType, bool auto_escape) {
    this->build(m, Action::SEND_MSG);
    m.setMessageType(msgType);
    m.setAutoEscape(auto_escape);
    if (msgType == MessageType::GROUP) {
        m.setGroupId(receive_id);
    }
    if (msgType == MessageType::PRIVATE) {
        m.setUserId(receive_id);
    }
    std::shared_ptr<MessageResp> p_resp = this->sendAndWaitResp<MessageResp>(m);
    return p_resp ? p_resp : nullptr;
}

void Bot::deleteMsg(const int32_t &message_id) {
    Msg builder;
    builder.setAction(Action::DELETE_MSG);
    builder.setMessageId(message_id);
    this->p_bot->send(builder.build());
}

std::shared_ptr<Message> Bot::getMsg(const int32_t &message_id) {
    Msg builder;
    builder.setMessageId(message_id);
    this->build(builder, Action::GET_MSG);
    std::shared_ptr<Message> p_resp = this->sendAndWaitResp<Message>(builder);
    return p_resp ? p_resp : nullptr;
}

std::shared_ptr<ForwardMessageResp> Bot::getForwardMsg(const std::string &message_id) {
    Msg builder;
    builder.setMessageId(message_id);
    this->build(builder, Action::GET_FORWARD_MSG);
    std::shared_ptr<ForwardMessageResp> p_resp = this->sendAndWaitResp<ForwardMessageResp>(builder);
    return p_resp ? p_resp : nullptr;
}

std::shared_ptr<ImageInfoResp> Bot::getImage(const std::string &filename) {
    Msg builder;
    builder.setFile(filename);
    this->build(builder, Action::GET_IMAGE);
    std::shared_ptr<ImageInfoResp> p_resp = this->sendAndWaitResp<ImageInfoResp>(builder);
    return p_resp ? p_resp : nullptr;
}

void Bot::markMsgAsRead(const int32_t &message_id) {
    Msg builder;
    builder.setMessageId(message_id);
    builder.setAction(Action::MARK_MSG_AS_READ);
    this->p_bot->send(builder.build());
}

void Bot::setGroupKick(const int64_t &group_id, const int64_t &user_id, bool reject_add_request) {
    Msg builder;
    builder.setGroupId(group_id);
    builder.setUserId(user_id);
    builder.setRejectAddRequest(reject_add_request);
    builder.setAction(Action::SET_GROUP_KICK);
    this->p_bot->send(builder.build());
}

void Bot::setGroupBan(const int64_t &group_id, const int64_t &user_id, const int32_t &duration) {
    Msg builder;
    builder.setGroupId(group_id);
    builder.setUserId(user_id);
    builder.setDuration(duration);
    builder.setAction(Action::SET_GROUP_BAN);
    this->p_bot->send(builder.build());
}

void Bot::setGroupAnonymousBan(const int64_t &group_id, const std::string &anonymous, const std::string &flag,
                               const int32_t &duration) {
    Msg builder;
    builder.setGroupId(group_id);
    builder.setAnonymous(anonymous);
    builder.setAnonymousFlag(flag);
    builder.setDuration(duration);
    builder.setAction(Action::SET_GROUP_ANONYMOUS_BAN);
    this->p_bot->send(builder.build());
}

void Bot::setGroupWholeBan(const int64_t &group_id, bool enable) {
    Msg builder;
    builder.setGroupId(group_id);
    builder.setEnable(enable);
    builder.setAction(Action::SET_GROUP_WHOLE_BAN);
    this->p_bot->send(builder.build());
}

void Bot::setGroupAdmin(const int64_t &group_id, const int64_t &user_id, bool enable) {
    Msg builder;
    builder.setGroupId(group_id);
    builder.setUserId(user_id);
    builder.setEnable(enable);
    builder.setAction(Action::SET_GROUP_ADMIN);
    this->p_bot->send(builder.build());
}

void Bot::setGroupAnonymous(const int64_t &group_id, bool enable) {
    // TODO: 该 API 暂未被 go-cqhttp 支持, 您可以提交 pr 以使该 API 被支持
}

void Bot::setGroupCard(const int64_t &group_id, const int64_t &user_id, const std::string &card) {
    Msg builder;
    builder.setGroupId(group_id);
    builder.setUserId(user_id);
    builder.setCard(card);
    builder.setAction(Action::SET_GROUP_CARD);
    this->p_bot->send(builder.build());
}

void Bot::setGroupName(const int64_t &group_id, const std::string &name) {
    Msg builder;
    builder.setGroupId(group_id);
    builder.setGroupName(name);
    builder.setAction(Action::SET_GROUP_NAME);
    this->p_bot->send(builder.build());
}

void Bot::setGroupLeave(const int64_t &group_id, bool is_dismiss) {
    Msg builder;
    builder.setGroupId(group_id);
    builder.setIsDismiss(is_dismiss);
    builder.setAction(Action::SET_GROUP_LEAVE);
    this->p_bot->send(builder.build());
}

void Bot::setGroupSpecialTitle(const int64_t &group_id, const int64_t &user_id, const std::string &title,
                               const int32_t &duration) {
    Msg builder;
    builder.setGroupId(group_id);
    builder.setUserId(user_id);
    builder.setSpecialTitle(title);
    builder.setDuration(duration);
    builder.setAction(Action::SET_GROUP_SPECIAL_TITLE);
    this->p_bot->send(builder.build());
}

void Bot::sendGroupSign(const int64_t &group_id) {
    Msg builder;
    builder.setGroupId(group_id);
    builder.setAction(Action::SEND_GROUP_SIGN);
    this->p_bot->send(builder.build());
}

void Bot::setFriendAddRequest(const std::string &flag, bool approve, const std::string &remark) {
    Msg builder;
    builder.setFlag(flag);
    builder.setApprove(approve);
    builder.setRemark(remark);
    builder.setAction(Action::SET_FRIEND_ADD_REQUEST);
    this->p_bot->send(builder.build());
}

void
Bot::setGroupAddRequest(const std::string &flag, const std::string &type, bool approve, const std::string &reason) {
    Msg builder;
    builder.setFlag(flag);
    builder.setType(type);
    builder.setApprove(approve);
    builder.setReason(reason);
    builder.setAction(Action::SET_GROUP_ADD_REQUEST);
    this->p_bot->send(builder.build());
}

std::shared_ptr<AccountInfo> Bot::getLoginInfo() {
    Msg builder;
    this->build(builder, Action::GET_LOGIN_INFO);
    std::shared_ptr<AccountInfo> p_resp = this->sendAndWaitResp<AccountInfo>(builder);
    return p_resp ? p_resp : nullptr;
}

std::shared_ptr<QidAccountInfo> Bot::getQiDianAccountInfo() {
    Msg builder;
    this->build(builder, Action::QIDIAN_GET_ACCOUNT_INFO);
    std::shared_ptr<QidAccountInfo> p_resp = this->sendAndWaitResp<QidAccountInfo>(builder);
    return p_resp ? p_resp : nullptr;
}

void Bot::setQQProfile(const std::string &nickname, const std::string &company, const std::string &email,
                       const std::string &college,
                       const std::string &personal_note) {
    Msg builder;
    Json::Value profile(Json::ValueType::objectValue);
    profile["nickname"] = nickname;
    profile["company"] = company;
    profile["email"] = email;
    profile["college"] = college;
    profile["personal_note"] = personal_note;
    builder.setParams(profile);
    builder.setAction(Action::SET_QQ_PROFILE);
    this->p_bot->send(builder.build());
}

std::shared_ptr<StrangerInfoResp> Bot::getStrangerInfo(const int64_t &user_id, bool no_cache) {
    Msg builder;
    builder.setUserId(user_id);
    builder.setNoCache(no_cache);
    this->build(builder, Action::GET_STRANGER_INFO);
    std::shared_ptr<StrangerInfoResp> p_resp = this->sendAndWaitResp<StrangerInfoResp>(builder);
    return p_resp ? p_resp : nullptr;
}

std::shared_ptr<FriendListResp> Bot::getFriendList() {
    Msg builder;
    this->build(builder, Action::GET_FRIEND_LIST);
    std::shared_ptr<FriendListResp> p_resp = this->sendAndWaitResp<FriendListResp>(builder);
    return p_resp ? p_resp : nullptr;
}

std::shared_ptr<UniDirectionalFriendListResp> Bot::getUnidirectionalFriendList() {
    Msg builder;
    this->build(builder, Action::GET_UNIDIRECTIONAL_FIREND_LIST);
    std::shared_ptr<UniDirectionalFriendListResp> p_resp = this->sendAndWaitResp<UniDirectionalFriendListResp>(builder);
    return p_resp ? p_resp : nullptr;
}

void Bot::deleteFriend(const int64_t &user_id) {
    Msg builder;
    builder.setAction(Action::DELETE_FRIEND);
    builder.setUserId(user_id);
    this->p_bot->send(builder.build());
}

std::shared_ptr<GroupInfoResp> Bot::getGroupInfo(const int64_t &group_id, bool no_cache) {
    Msg builder;
    this->build(builder, Action::GET_GROUP_INFO);
    builder.setGroupId(group_id);
    builder.setNoCache(no_cache);
    std::shared_ptr<GroupInfoResp> p_resp = this->sendAndWaitResp<GroupInfoResp>(builder);
    return p_resp ? p_resp : nullptr;
}

std::shared_ptr<GroupListInfoResp> Bot::getGroupList(bool no_cache) {
    Msg builder;
    this->build(builder, Action::GET_GROUP_LIST);
    builder.setNoCache(no_cache);
    std::shared_ptr<GroupListInfoResp> p_resp = this->sendAndWaitResp<GroupListInfoResp>(builder);
    return p_resp ? p_resp : nullptr;
}

void Bot::getGroupMemberInfo(int64_t group_id, int64_t user_id, bool no_cache) {

}

void Bot::getGroupMemberList(int64_t group_id, bool no_cache) {

}

void Bot::getGroupHonorInfo(int64_t group_id, std::string type) {

}

void Bot::getCookies(std::string domain) {

}

void Bot::getCsrfToken() {

}

void Bot::getCredentials(std::string domain) {

}

void Bot::getRecord(std::string filename, std::string out_format) {

}

void Bot::canSendImage() {

}

void Bot::canSendRecord() {

}

void Bot::getVersionInfo() {

}

void Bot::setRestart(int32_t delay) {

}

void Bot::cleanCache() {

}

void Bot::setGroupPortrait(int64_t group_id, std::string filename, int cache) {

}

void Bot::_getWordSlices(std::string content) {

}

void Bot::ocrImage(std::string image_id) {

}

void Bot::getGroupSystemMsg(std::string invited_requests, std::string join_requests) {

}

void Bot::uploadPrivateFile(int64_t user_id, std::string file_path, std::string file_name) {

}

void Bot::uploadGroupFile(int64_t group_id, std::string file_path, std::string file_name, std::string folder) {

}

void Bot::getGroupFileSystemInfo(int64_t group_id) {

}

void Bot::getGroupRootFiles(int64_t group_id) {

}

void Bot::getGroupFilesByFolder(int64_t group_id, std::string folder_id) {

}

void Bot::createGroupFileFolder(int64_t group_id, std::string name, std::string parent_id) {

}

void Bot::deleteGroupFolder(int64_t group_id, std::string folder_id) {

}

void Bot::deleteGroupFile(int64_t group_id, std::string file_id, int32_t busid) {

}

void Bot::getGroupFileUrl(int64_t group_id, std::string file_id, int32_t busid) {

}

void Bot::getStatus() {

}

void Bot::getGroupAtAllRemain(int64_t group_id) {

}

void Bot::_handleQuickOperation(std::string context, std::string operation) {

}

void Bot::_sendGroupNotice(int64_t group_id, std::string content, std::string image_path) {

}

void Bot::_getGroupNotice(int64_t group_id) {

}

void Bot::reloadEventFilter(std::string file_path) {

}

void Bot::downloadFile(std::string url, int32_t thread_count, std::string headers) {

}

void Bot::getOnlineClients(bool no_cache) {

}

void Bot::getGroupMsgHistory(int64_t message_seq, int64_t group_id) {

}

void Bot::setEssenceMsg(int32_t message_id) {

}

void Bot::deleteEssenceMsg(int32_t message_id) {

}

void Bot::getEssenceMsgList(int64_t group_id) {

}

void Bot::checkUrlSafely(std::string url) {

}

void Bot::_getModelShow(std::string model) {

}

void Bot::_setModelShow(std::string model, std::string model_show) {

}

void Bot::deleteUnidirectionalFriend(int64_t user_id) {

}

void Bot::sendPrivateForwardMsg(int64_t user_id, std::string message) {

}

template<typename T>
std::shared_ptr<T> Bot::sendAndWaitResp(Msg &msg) {
    this->p_bot->send(msg.build());
    time_t start_time, end_time;
    time(&start_time);
    for (time(&end_time); end_time - start_time < 15; time(&end_time)) {
        m_mutex.lock();
        Json::Value new_resp = m_resp;
        m_mutex.unlock();
        if (new_resp.get("echo", "") == msg.getEcho()) {
            return std::shared_ptr<T>(new T(new_resp));
        }
    }
    return nullptr;
}

void Bot::build(Msg &builder, const std::string &action) {
    builder.setAction(action);
    time_t echo;
    std::string echo_str = std::to_string(time(&echo));
    builder.setEcho(action + "_" + echo_str);
}
