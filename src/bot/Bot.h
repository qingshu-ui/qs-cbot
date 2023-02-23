//
// Created by 17186 on 2/22/2023.
//

#ifndef CQHTTP_BOT_H
#define CQHTTP_BOT_H

#include <drogon/WebSocketConnection.h>
#include "resp/PrivateMessageResp.h"
#include "resp/GroupMessageResp.h"
#include "resp/GroupForwardMsgResp.h"
#include "resp/MessageResp.h"
#include "resp/Message.h"
#include "resp/AccountInfo.h"
#include "resp/QidAccountInfo.h"
#include "resp/StrangerInfoResp.h"
#include "resp/FriendListResp.h"
#include "resp/UniDirectionalFriendListResp.h"
#include "resp/GroupInfoResp.h"
#include "resp/GroupListInfoResp.h"
#include "../msg/Msg.h"
#include "resp/RespBody.h"
#include "resp/ForwardMessageResp.h"
#include "resp/ImageInfoResp.h"

class Bot {
private:
    drogon::WebSocketConnectionPtr p_bot;

    template<typename T>
    std::shared_ptr<T> sendAndWaitResp(Msg &msg);

    void build(Msg &builder, const std::string& action);



public:
    Bot(const drogon::WebSocketConnectionPtr &bot);

    drogon::WebSocketConnectionPtr &getRawBot();


    // 发送私聊消息
    std::shared_ptr<PrivateMessageResp>
    sendPrivateMsg(Msg &m, const int64_t &user_id, bool auto_escape = false);

    // 发送群消息
    std::shared_ptr<GroupMessageResp> sendGroupMsg(Msg &m, const int64_t &group_id, bool auto_escape = false);

    // 发送合并转发 ( 群 )(暂时不能用，原因未知)
    std::shared_ptr<GroupForwardMsgResp>
    sendGroupForwardMsg(Msg &m, const int64_t &group_id, bool auto_escape = false);

    // 发送消息
    std::shared_ptr<MessageResp>
    sendMsg(Msg &m, const int64_t &receive_id, const char *msgType, bool auto_escape = false);

    // 撤回消息
    void deleteMsg(const int32_t &message_id);

    // 获取消息
    std::shared_ptr<Message> getMsg(const int32_t &message_id);

    // 因为 sendGroupForwardMsg 不可用，此 api 也暂时不可用
    std::shared_ptr<ForwardMessageResp> getForwardMsg(const std::string &message_id);

    // 获取图片信息
    std::shared_ptr<ImageInfoResp> getImage(const std::string &filename);

    // 标记消息已读
    void markMsgAsRead(const int32_t &message_id);

    // 群组踢人
    void setGroupKick(const int64_t &group_id, const int64_t &user_id, bool reject_add_request = false);

    // 群组单人禁言
    void setGroupBan(const int64_t &group_id, const int64_t &user_id, const int32_t &duration);

    // 群组匿名用户禁言
    void setGroupAnonymousBan(const int64_t &group_id, const std::string &anonymous, const std::string &flag, const int32_t &duration);

    // 群组全员禁言
    void setGroupWholeBan(const int64_t &group_id, bool enable = true);

    // 群组设置管理员
    void setGroupAdmin(const int64_t &group_id, const int64_t &user_id, bool enable = true);

    //  群组匿名, 该 API 暂未被 go-cqhttp 支持, 您可以提交 pr 以使该 API 被支持
    void setGroupAnonymous(const int64_t &group_id, bool enable = true);

    //  设置群名片 ( 群备注 )
    void setGroupCard(const int64_t &group_id, const int64_t &user_id, const std::string &card = "");

    // 设置群名
    void setGroupName(const int64_t &group_id, const std::string &name);

    // 退出群组
    void setGroupLeave(const int64_t &group_id, bool is_dismiss = false);

    // 设置群组专属头衔
    void setGroupSpecialTitle(const int64_t &group_id, const int64_t &user_id, const std::string &title, const int32_t &duration = -1);

    // 群打卡
    void sendGroupSign(const int64_t &group_id);

    // 处理加好友请求
    void setFriendAddRequest(const std::string &flag, bool approve = true, const std::string &remark = "");

    // 处理加群请求／邀请
    void setGroupAddRequest(const std::string &flag, const std::string &type, bool approve = true,
                            const std::string &reason = "");

    // 获取登录号信息
    std::shared_ptr<AccountInfo> getLoginInfo();

    // 获取企点账号信息, 该API只有企点协议可用
    std::shared_ptr<QidAccountInfo> getQiDianAccountInfo();

    // 设置登录号资料
    // 经调试后发现此API不可用，原因未知
    void setQQProfile(const std::string &nickname,
                      const std::string &company,
                      const std::string &email,
                      const std::string &college,
                      const std::string &personal_note);

    // 获取陌生人信息
    std::shared_ptr<StrangerInfoResp> getStrangerInfo(const int64_t &user_id, bool no_cache = false);

    // 获取好友列表
    std::shared_ptr<FriendListResp> getFriendList();

    // 获取单向好友列表
    std::shared_ptr<UniDirectionalFriendListResp> getUnidirectionalFriendList();

    // 删除好友
    void deleteFriend(const int64_t &user_id);

    // 获取群信息
    std::shared_ptr<GroupInfoResp> getGroupInfo(const int64_t &group_id, bool no_cache = false);

    // 获取群列表
    std::shared_ptr<GroupListInfoResp> getGroupList(bool no_cache = false);

    // get_group_member_info
    void getGroupMemberInfo(int64_t group_id, int64_t user_id, bool no_cache = false);

    // get_group_member_list
    void getGroupMemberList(int64_t group_id, bool no_cache = false);

    // get_group_honor_info
    void getGroupHonorInfo(int64_t group_id, std::string type);

    // get_cookies
    void getCookies(std::string domain);

    // get_csrf_token
    void getCsrfToken();

    // get_credentials
    void getCredentials(std::string domain);

    // get_record
    void getRecord(std::string filename, std::string out_format);

    // can_send_image
    void canSendImage();

    // can_send_record
    void canSendRecord();

    // get_version_info
    void getVersionInfo();

    // set_restart
    void setRestart(int32_t delay);

    // clean_cache
    void cleanCache();

    // set_group_portrait
    void setGroupPortrait(int64_t group_id, std::string filename, int cache);

    // .get_word_slices
    void _getWordSlices(std::string content);

    // ocr_image
    void ocrImage(std::string image_id);

    // get_group_system_msg
    void getGroupSystemMsg(std::string invited_requests,
                           std::string join_requests);

    // upload_private_file
    void uploadPrivateFile(int64_t user_id, std::string file_path, std::string file_name);

    // upload_group_file
    void uploadGroupFile(int64_t group_id, std::string file_path, std::string file_name, std::string folder);

    // get_group_file_system_info
    void getGroupFileSystemInfo(int64_t group_id);

    // get_group_root_files
    void getGroupRootFiles(int64_t group_id);

    // get_group_files_by_folder
    void getGroupFilesByFolder(int64_t group_id, std::string folder_id);

    // create_group_file_folder
    void createGroupFileFolder(int64_t group_id, std::string name, std::string parent_id);

    // delete_group_folder
    void deleteGroupFolder(int64_t group_id, std::string folder_id);

    // delete_group_file
    void deleteGroupFile(int64_t group_id, std::string file_id, int32_t busid);

    // get_group_file_url
    void getGroupFileUrl(int64_t group_id, std::string file_id, int32_t busid);

    // get_status
    void getStatus();

    // get_group_at_all_remain
    void getGroupAtAllRemain(int64_t group_id);

    // .handle_quick_operation
    void _handleQuickOperation(std::string context, std::string operation);

    // _send_group_notice
    void _sendGroupNotice(int64_t group_id, std::string content, std::string image_path);

    // _get_group_notice
    void _getGroupNotice(int64_t group_id);

    // reload_event_filter
    void reloadEventFilter(std::string file_path);

    // download file
    void downloadFile(std::string url, int32_t thread_count, std::string headers);

    // get_online_clients
    void getOnlineClients(bool no_cache);

    // get_group_msg_history
    void getGroupMsgHistory(int64_t message_seq, int64_t group_id);

    // set_essence_msg
    void setEssenceMsg(int32_t message_id);

    // delete_essence_msg
    void deleteEssenceMsg(int32_t message_id);

    // get_essence_msg_list
    void getEssenceMsgList(int64_t group_id);

    // check_url_safely
    void checkUrlSafely(std::string url);

    // _get_model_show
    void _getModelShow(std::string model);

    // _set_model_show
    void _setModelShow(std::string model, std::string model_show);

    // delete_unidirectional_friend
    void deleteUnidirectionalFriend(int64_t user_id);

    // send_private_forward_msg
    void sendPrivateForwardMsg(int64_t user_id, std::string message);

};


#endif //CQHTTP_BOT_H
