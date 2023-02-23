//
// Created by 17186 on 2/22/2023.
//

#ifndef CQ_WEBSOCKET_SERVER_MESSAGEEVENT_H
#define CQ_WEBSOCKET_SERVER_MESSAGEEVENT_H

#include <json/json.h>

class Sender {
public:
    Json::Value raw_sender;

    Sender(const Json::Value &sender);

    virtual int64_t user_id() const;

    virtual std::string nickname() const;

    virtual std::string sex() const;

    virtual int32_t age() const;

    virtual int64_t group_id() const;
};

class GroupMessageSender : public Sender {
public:
    GroupMessageSender(const Json::Value &sender);

    virtual std::string card() const;

    virtual std::string area() const;

    virtual std::string level() const;

    virtual std::string role() const;

    virtual std::string title() const;
};

class MessageEvent {
public:
    Json::Value raw_msg;

    MessageEvent(const Json::Value &msg);

    virtual std::string message_type() const;

    virtual std::string sub_type() const;

    virtual int32_t message_id() const;

    virtual int64_t user_id() const;

    virtual std::string message() const;

    virtual std::string raw_message() const;

    virtual int font() const;

    virtual std::string to_string() const;

};


#endif //CQ_WEBSOCKET_SERVER_MESSAGEEVENT_H
