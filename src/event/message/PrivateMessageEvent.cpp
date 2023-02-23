//
// Created by 17186 on 2/22/2023.
//

#include "PrivateMessageEvent.h"

int PrivateMessageEvent::temp_source() const {
    return this->raw_msg["temp_source"].asInt();
}

Sender PrivateMessageEvent::sender() const {
    return Sender(this->raw_msg["sender"]);
}
