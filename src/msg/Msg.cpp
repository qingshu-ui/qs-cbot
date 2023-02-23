//
// Created by 17186 on 2/22/2023.
//

#include "Msg.h"

void Msg::setAction(const std::string &action) {
    this->raw_message["action"] = action;
}

void Msg::setUserId(int64_t user_id) {
    this->raw_message["params"]["user_id"] = user_id;
}

void Msg::setGroupId(int64_t group_id) {
    this->raw_message["params"]["group_id"] = group_id;
}

void Msg::setMessage(const std::string &message) {
    this->raw_message["params"]["message"] = message;
}

void Msg::setMessages(const std::string &messages) {
    this->raw_message["params"]["messages"] = messages;
}

void Msg::setAutoEscape(bool auto_escape) {
    this->raw_message["params"]["auto_escape"] = auto_escape;
}

void Msg::setMessageId(int32_t message_id) {
    this->raw_message["params"]["message_id"] = message_id;
}

std::string Msg::getEcho() const {
    return this->raw_message["echo"].asString();
}

std::string Msg::to_string() const {
    Json::FastWriter w;
    return w.write(this->raw_message);
}

std::string Msg::build() const {
    return this->to_string();
}

void Msg::setRejectAddRequest(bool reject) {
    this->raw_message["params"]["reject_add_request"] = reject;
}

void Msg::setDuration(int32_t duration) {
    this->raw_message["params"]["duration"] = duration;
}

void Msg::setAnonymous(const std::string &anonymous) {
    this->raw_message["params"]["anonymous"] = anonymous;
}

void Msg::setAnonymousFlag(const std::string &flag) {
    this->raw_message["params"]["anonymous_flag"] = flag;
}

void Msg::setEnable(bool enable) {
    this->raw_message["params"]["enable"] = enable;
}

void Msg::setCard(const std::string &card) {
    this->raw_message["params"]["card"] = card;
}

void Msg::setGroupName(const std::string &group_name) {
    this->raw_message["params"]["group_name"] = group_name;
}

void Msg::setIsDismiss(bool is_dismiss) {
    this->raw_message["params"]["is_dismiss"] = is_dismiss;
}

void Msg::setSpecialTitle(const std::string &title) {
    this->raw_message["params"]["special_title"] = title;
}

void Msg::setApprove(bool approve) {
    this->raw_message["params"]["approve"] = approve;
}

void Msg::setRemark(const std::string &remark) {
    this->raw_message["params"]["remark"] = remark;
}

void Msg::setFlag(const std::string &flag) {
    this->raw_message["params"]["flag"] = flag;
}

void Msg::setReason(const std::string &reason) {
    this->raw_message["params"]["reason"] = reason;
}

void Msg::setType(const std::string &type) {
    this->raw_message["params"]["type"] = type;
}

void Msg::setParams(const Json::Value &params) {
    this->raw_message["params"] = params;
}

void Msg::setNoCache(bool no_cache) {
    this->raw_message["params"]["no-cache"] = no_cache;
}

void Msg::setEcho(const std::string &echo) {
    this->raw_message["echo"] = echo;
}

void Msg::setMessageType(const char *type) {
    this->raw_message["params"]["message-type"] = type;
}

void Msg::setMessageId(const std::string &message_id) {
    this->raw_message["params"]["message_id"] = message_id;
}

void Msg::setFile(const std::string &file) {
    this->raw_message["params"]["file"] = file;
}
