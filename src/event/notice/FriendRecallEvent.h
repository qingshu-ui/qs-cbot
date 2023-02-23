//
// Created by 17186 on 2/22/2023.
//

#ifndef CQ_WEBSOCKET_SERVER_FRIENDRECALLEVENT_H
#define CQ_WEBSOCKET_SERVER_FRIENDRECALLEVENT_H


#include "NoticeEvent.h"

class FriendRecallEvent : public NoticeEvent {
public:
    using NoticeEvent::NoticeEvent;

    int64_t user_id() const;

    int64_t message_id() const;

};


#endif //CQ_WEBSOCKET_SERVER_FRIENDRECALLEVENT_H
