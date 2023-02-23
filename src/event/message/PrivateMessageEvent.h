//
// Created by 17186 on 2/22/2023.
//

#ifndef CQHTTP_PRIVATEMESSAGEEVENT_H
#define CQHTTP_PRIVATEMESSAGEEVENT_H

#include "MessageEvent.h"

class PrivateMessageEvent : public MessageEvent {
public:
    using MessageEvent::MessageEvent;

    Sender sender() const;

    int temp_source() const;
};


#endif //CQHTTP_PRIVATEMESSAGEEVENT_H
