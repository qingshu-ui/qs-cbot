//
// Created by 17186 on 2/22/2023.
//

#ifndef CQ_WEBSOCKET_SERVER_MSG_H
#define CQ_WEBSOCKET_SERVER_MSG_H

#include <json/json.h>

class Msg {
public:
    Json::Value raw_message;

    void setAction(const std::string &action);

    void setUserId(int64_t user_id);

    void setGroupId(int64_t group_id);

    void setMessage(const std::string &message);

    void setMessages(const std::string &messages);

    void setAutoEscape(bool auto_escape);

    void setMessageId(int32_t message_id);

    void setMessageId(const std::string &message_id);

    void setEcho(const std::string &echo);

    std::string getEcho() const;

    std::string to_string() const;

    std::string build() const;

    void setRejectAddRequest(bool reject = false);

    void setDuration(int32_t duration);

    void setAnonymous(const std::string &anonymous);

    void setAnonymousFlag(const std::string &flag);

    void setEnable(bool enable);

    void setCard(const std::string &card);

    void setGroupName(const std::string &group_name);

    void setIsDismiss(bool is_dismiss = false);

    void setSpecialTitle(const std::string &title);

    void setApprove(bool approve = true);

    void setRemark(const std::string &remark = "");

    void setFlag(const std::string &flag);

    void setReason(const std::string &reason);

    void setType(const std::string &type);

    void setParams(const Json::Value &params);

    void setNoCache(bool no_cache = false);

    void setMessageType(const char *type);

    void setFile(const std::string &file);

};


#endif //CQ_WEBSOCKET_SERVER_MSG_H
