//
// Created by 17186 on 2/22/2023.
//

#ifndef CQ_WEBSOCKET_SERVER_GROUPBANEVENT_H
#define CQ_WEBSOCKET_SERVER_GROUPBANEVENT_H


#include "NoticeEvent.h"

class GroupBanEvent: public NoticeEvent{
public:
    using NoticeEvent::NoticeEvent;
};


#endif //CQ_WEBSOCKET_SERVER_GROUPBANEVENT_H
