//
// Created by 17186 on 2/22/2023.
//

#ifndef CQ_WEBSOCKET_SERVER_ACCOUNTINFO_H
#define CQ_WEBSOCKET_SERVER_ACCOUNTINFO_H


#include "RespBody.h"

class AccountInfo : public RespBody {
public:
    using RespBody::RespBody;

    int64_t user_id() const;
    std::string nickname() const;
};


#endif //CQ_WEBSOCKET_SERVER_ACCOUNTINFO_H
