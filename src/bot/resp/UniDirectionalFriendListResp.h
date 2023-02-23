//
// Created by 17186 on 2/22/2023.
//

#ifndef CQ_WEBSOCKET_SERVER_UNIDIRECTIONALFRIENDLISTRESP_H
#define CQ_WEBSOCKET_SERVER_UNIDIRECTIONALFRIENDLISTRESP_H


#include "RespBody.h"

class UniDirectionalFriendListResp : public RespBody {
public:
    using RespBody::RespBody;

    int64_t user_id() const;

    std::string nickname() const;

    std::string source() const;

};


#endif //CQ_WEBSOCKET_SERVER_UNIDIRECTIONALFRIENDLISTRESP_H
