//
// Created by 17186 on 2/22/2023.
//

#include "NoticeEvent.h"

NoticeEvent::NoticeEvent(const Json::Value &rawNotice) : raw_notice(rawNotice) { this->raw_notice = rawNotice; }

int64_t NoticeEvent::time() const {
    return this->raw_notice["time"].asInt64();
}

int64_t NoticeEvent::self_id() const {
    return this->raw_notice["self_id"].asInt64();
}

std::string NoticeEvent::post_type() const {
    return this->raw_notice["post_type"].asString();
}

std::string NoticeEvent::notice_type() const {
    return this->raw_notice["notice_type"].asString();
}
