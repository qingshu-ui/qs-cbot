//
// Created by 17186 on 2/22/2023.
//

#ifndef CQ_WEBSOCKET_SERVER_GROUPADMINEVENT_H
#define CQ_WEBSOCKET_SERVER_GROUPADMINEVENT_H


#include "NoticeEvent.h"

class GroupAdminEvent : public NoticeEvent{
public:
    using NoticeEvent::NoticeEvent;
};


#endif //CQ_WEBSOCKET_SERVER_GROUPADMINEVENT_H
