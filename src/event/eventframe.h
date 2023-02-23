//
// Created by 17186 on 2/22/2023.
//

#ifndef CQHTTP_EVENTFRAME_H
#define CQHTTP_EVENTFRAME_H

#include <json/json.h>

namespace EventClassification {
    void eventClassification(const Json::Value &event);

    void messageClassification(const Json::Value &event);

    void requestClassification(const Json::Value &event);

    void noticeClassification(const Json::Value &event);

    void metaEventClassification(const Json::Value &event);
}

namespace MessageType {
    extern const std::string GROUP;
    extern const std::string PRIVATE;

    namespace SubType {
        extern const std::string FRIEND;
        extern const std::string NORMAL;
        extern const std::string ANONYMOUS;
        extern const std::string GROUP_SELF;
        extern const std::string GROUP;
        extern const std::string NOTICE;
    }
}

namespace NoticeType {
    extern const std::string FRIEND_RECALL;
    extern const std::string GROUP_RECALL;
    extern const std::string GROUP_INCREASE;
    extern const std::string GROUP_DECREASE;
    extern const std::string GROUP_ADMIN;
    extern const std::string GROUP_UPLOAD;
    extern const std::string GROUP_BAN;
    extern const std::string FRIEND_ADD;
    extern const std::string NOTIFY;
    extern const std::string GROUP_CARD;
    extern const std::string OFFLINE_FILE;
    extern const std::string CLIENT_STATUS;
    extern const std::string ESSENCE;
}

namespace RequestType {
    extern const std::string FRIEND;
    extern const std::string GROUP;
}


#endif //CQHTTP_EVENTFRAME_H
