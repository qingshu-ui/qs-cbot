//
// Created by 17186 on 2/22/2023.
//

#ifndef CQ_WEBSOCKET_SERVER_FRIENDREQUESTEVENT_H
#define CQ_WEBSOCKET_SERVER_FRIENDREQUESTEVENT_H


#include "RequestEvent.h"

class FriendRequestEvent : public RequestEvent {
public:
    using RequestEvent::RequestEvent;

    int64_t user_id() const;

    std::string comment() const;

    std::string flag() const;
};


#endif //CQ_WEBSOCKET_SERVER_FRIENDREQUESTEVENT_H
