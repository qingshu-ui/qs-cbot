//
// Created by 17186 on 2/22/2023.
//

#ifndef CQ_WEBSOCKET_SERVER_GROUPREQUESTEVENT_H
#define CQ_WEBSOCKET_SERVER_GROUPREQUESTEVENT_H


#include "RequestEvent.h"

class GroupRequestEvent : public RequestEvent {
public:
    using RequestEvent::RequestEvent;

    std::string sub_type() const;

    int64_t group_id() const;

    int64_t user_id() const;

    std::string comment() const;

    std::string flag() const;
};


#endif //CQ_WEBSOCKET_SERVER_GROUPREQUESTEVENT_H
