//
// Created by 17186 on 2/22/2023.
//

#ifndef CQ_WEBSOCKET_SERVER_GROUPMESSAGEEVENT_H
#define CQ_WEBSOCKET_SERVER_GROUPMESSAGEEVENT_H

#include "MessageEvent.h"

class Anonymous {
public:
    Json::Value raw_anonymous;

    Anonymous(const Json::Value &nonymous);

    int64_t id() const;

    std::string name() const;

    std::string flag() const;
};

class GroupMessageEvent : public MessageEvent {
public:
    using MessageEvent::MessageEvent;

    GroupMessageSender sender() const;

    int64_t group_id() const;

    Anonymous anonymous() const;
};


#endif //CQ_WEBSOCKET_SERVER_GROUPMESSAGEEVENT_H
