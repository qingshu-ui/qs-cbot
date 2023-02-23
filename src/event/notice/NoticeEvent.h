//
// Created by 17186 on 2/22/2023.
//

#ifndef CQ_WEBSOCKET_SERVER_NOTICEEVENT_H
#define CQ_WEBSOCKET_SERVER_NOTICEEVENT_H


#include "json/value.h"

class NoticeEvent {
public:
    Json::Value raw_notice;

    explicit NoticeEvent(const Json::Value &rawNotice);

    virtual int64_t time() const;

    virtual int64_t self_id() const;

    virtual std::string post_type() const;

    virtual std::string notice_type() const;
};


#endif //CQ_WEBSOCKET_SERVER_NOTICEEVENT_H
