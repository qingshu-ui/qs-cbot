//
// Created by 17186 on 2/22/2023.
//

#ifndef CQ_WEBSOCKET_SERVER_FRIENDADDEVENT_H
#define CQ_WEBSOCKET_SERVER_FRIENDADDEVENT_H


#include "NoticeEvent.h"

class FriendAddEvent: public NoticeEvent{
public:
    using NoticeEvent::NoticeEvent;
};


#endif //CQ_WEBSOCKET_SERVER_FRIENDADDEVENT_H
