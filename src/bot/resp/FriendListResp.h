//
// Created by 17186 on 2/22/2023.
//

#ifndef CQ_WEBSOCKET_SERVER_FRIENDLISTRESP_H
#define CQ_WEBSOCKET_SERVER_FRIENDLISTRESP_H


#include "RespBody.h"

class Friend {
public:
    Json::Value raw_friend;

    int64_t user_id() const;

    std::string nickname() const;

    std::string remark() const;
};


class FriendListResp : public RespBody {
public:
    using RespBody::RespBody;

    Friend get_friend(const int32_t &index) const;

    int32_t size() const;

};


#endif //CQ_WEBSOCKET_SERVER_FRIENDLISTRESP_H
