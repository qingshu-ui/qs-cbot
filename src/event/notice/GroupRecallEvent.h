//
// Created by 17186 on 2/22/2023.
//

#ifndef CQ_WEBSOCKET_SERVER_GROUPRECALLEVENT_H
#define CQ_WEBSOCKET_SERVER_GROUPRECALLEVENT_H


#include "NoticeEvent.h"

class GroupRecallEvent : public NoticeEvent{
public:
    using NoticeEvent::NoticeEvent;
};


#endif //CQ_WEBSOCKET_SERVER_GROUPRECALLEVENT_H
