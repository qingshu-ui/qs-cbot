//
// Created by 17186 on 2/24/2023.
//

#include "WebsocketController.h"
#include "../../pbf/built/cqhttp_event.pb.h"
#include "google/protobuf/util/json_util.h"
#include "../bot/Bot.h"
#include "../event/eventhandler.h"
#include <map>

using namespace google::protobuf::util;

std::map<int64_t, std::shared_ptr<Bot>> bot_map;
BaseResp m_resp;
std::queue<BaseResp> m_queue;
google::protobuf::util::JsonPrintOptions print_options;
google::protobuf::util::JsonParseOptions parse_options;

void WebsocketController::handleNewMessage(const drogon::WebSocketConnectionPtr &ptr, std::string &&message,
                                           const drogon::WebSocketMessageType &messageType) {
    if (messageType != drogon::WebSocketMessageType::Text) {
        return;
    }

    Json::Reader r;
    Json::Value v;
    if (r.parse(message, v) && !v["echo"].empty()) {
        BaseResp resp{message};
        m_queue.push(resp);
    }

    // Use multithreading.
    std::thread([=]() {
        JsonParseOptions options;
        options.ignore_unknown_fields = true;

        cqhttp::BaseEvent base_event;
        status_internal::Status status;
        if ((status = JsonStringToMessage(message, &base_event, options)).ok()) {

            // Handle message events.
            switch (base_event.message_type()) {
                case cqhttp::group: {
                    std::shared_ptr<cqhttp::GroupMessageEvent> event(new cqhttp::GroupMessageEvent());
                    if (JsonStringToMessage(message, event.get(), options).ok()) {
                        EventHandler::handleGroupMessage(bot_map.at(event->self_id()), event);
                    } else {
                        LOG_INFO << "Failed to parse into group message event.";
                    }
                    break;
                }
                case cqhttp::private_: {
                    std::shared_ptr<cqhttp::PrivateMessageEvent> event(new cqhttp::PrivateMessageEvent());
                    if (JsonStringToMessage(message, event.get(), options).ok()) {
                        EventHandler::handlePrivateMessage(bot_map.at(event->self_id()), event);
                    } else {
                        LOG_INFO << "Failed to parse into private message event.";
                    }
                    break;
                }
                default:
                    break;
            }

            // Handle notice events.
            switch (base_event.notice_type()) {
                case cqhttp::friend_recall: {
                    std::shared_ptr<cqhttp::FriendRecallEvent> event(new cqhttp::FriendRecallEvent());
                    if (JsonStringToMessage(message, event.get(), options).ok()) {
                        EventHandler::handleFriendRecall(bot_map.at(event->self_id()), event);
                    } else {
                        LOG_INFO << "Failed to parse the reported content as a friend recall event.";
                    }
                    break;
                }
                case cqhttp::group_recall: {
                    std::shared_ptr<cqhttp::GroupRecallEvent> event(new cqhttp::GroupRecallEvent());
                    if (JsonStringToMessage(message, event.get(), options).ok()) {
                        EventHandler::handleGroupRecall(bot_map.at(event->self_id()), event);
                    } else {
                        LOG_INFO << "Failed to parse the reported content as a group recall event.";
                    }
                    break;
                }
                case cqhttp::group_increase: {
                    std::shared_ptr<cqhttp::GroupIncreaseEvent> event(new cqhttp::GroupIncreaseEvent());
                    if (JsonStringToMessage(message, event.get(), options).ok()) {
                        EventHandler::handleGroupIncrease(bot_map.at(event->self_id()), event);
                    } else {
                        LOG_INFO << "Failed to parse the reported content as a group increase event.";
                    }
                    break;
                }
                case cqhttp::group_decrease: {
                    std::shared_ptr<cqhttp::GroupDecreaseEvent> event(new cqhttp::GroupDecreaseEvent());
                    if (JsonStringToMessage(message, event.get(), options).ok()) {
                        EventHandler::handleGroupDecrease(bot_map.at(event->self_id()), event);
                    } else {
                        LOG_INFO << "Failed to parse the reported content as a group decrease event.";
                    }
                    break;
                }
                case cqhttp::group_admin: {
                    std::shared_ptr<cqhttp::GroupAdminChangeEvent> event(new cqhttp::GroupAdminChangeEvent());
                    if (JsonStringToMessage(message, event.get(), options).ok()) {
                        EventHandler::handleGroupAdminChanged(bot_map.at(event->self_id()), event);
                    } else {
                        LOG_INFO << "Failed to parse the reported content as a group admin changed event.";
                    }
                    break;
                }
                case cqhttp::group_upload: {
                    std::shared_ptr<cqhttp::GroupFileUploadEvent> event(new cqhttp::GroupFileUploadEvent());
                    if (JsonStringToMessage(message, event.get(), options).ok()) {
                        EventHandler::handleGroupFileUploaded(bot_map.at(event->self_id()), event);
                    } else {
                        LOG_INFO << "Failed to parse the reported content as a group file uploaded event.";
                    }
                    break;
                }
                case cqhttp::group_ban: {
                    std::shared_ptr<cqhttp::GroupBanEvent> event(new cqhttp::GroupBanEvent());
                    if (JsonStringToMessage(message, event.get(), options).ok()) {
                        EventHandler::handleGroupBan(bot_map.at(event->self_id()), event);
                    } else {
                        LOG_INFO << "Failed to parse the reported content as a group ban event.";
                    }
                    break;
                }
                case cqhttp::friend_add: {
                    std::shared_ptr<cqhttp::FriendAddEvent> event(new cqhttp::FriendAddEvent());
                    if (JsonStringToMessage(message, event.get(), options).ok()) {
                        EventHandler::handleFriendAdd(bot_map.at(event->self_id()), event);
                    } else {
                        LOG_INFO << "Failed to parse the reported content as a friend add event.";
                    }
                    break;
                }
                case cqhttp::notify: {
                    std::shared_ptr<cqhttp::NotifyEvent> event(new cqhttp::NotifyEvent());
                    if (JsonStringToMessage(message, event.get(), options).ok()) {
                        EventHandler::handleNotify(bot_map.at(event->self_id()), event);
                    } else {
                        LOG_INFO << "Failed to parse the reported content as a notify event.";
                    }
                    break;
                }
                case cqhttp::group_card: {
                    std::shared_ptr<cqhttp::GroupCardChangedEvent> event(new cqhttp::GroupCardChangedEvent());
                    if (JsonStringToMessage(message, event.get(), options).ok()) {
                        EventHandler::handleGroupCardChanged(bot_map.at(event->self_id()), event);
                    } else {
                        LOG_INFO << "Failed to parse the reported content as a group card changed event.";
                    }
                    break;
                }
                case cqhttp::offline_file: {
                    std::shared_ptr<cqhttp::ReceviedOfflineFileEvent> event(new cqhttp::ReceviedOfflineFileEvent());
                    if (JsonStringToMessage(message, event.get(), options).ok()) {
                        EventHandler::handleReceivedOfflineFile(bot_map.at(event->self_id()), event);
                    } else {
                        LOG_INFO << "Failed to parse the reported content as a received offline file event.";
                    }
                    break;
                }
                case cqhttp::client_status: {
                    std::shared_ptr<cqhttp::ClientChangedEvent> event(new cqhttp::ClientChangedEvent());
                    if (JsonStringToMessage(message, event.get(), options).ok()) {
                        EventHandler::handleClientStatusChanged(std::make_shared<Bot>(ptr), event);
                    } else {
                        LOG_INFO << "Failed to parse the reported content as a client changed event.";
                    }
                    break;
                }
                case cqhttp::essence: {
                    std::shared_ptr<cqhttp::EssenceMsgChangedEvent> event(new cqhttp::EssenceMsgChangedEvent());
                    if (JsonStringToMessage(message, event.get(), options).ok()) {
                        EventHandler::handleEssenceChanged(std::make_shared<Bot>(ptr), event);
                    } else {
                        LOG_INFO << "Failed to parse the reported content as a essence changed event.";
                    }
                    break;
                }
                default:
                    break;
            }

            // Handle request events.
            switch (base_event.request_type()) {
                case cqhttp::friend_: {
                    std::shared_ptr<cqhttp::FriendAddRequestEvent> event(new cqhttp::FriendAddRequestEvent());
                    if (JsonStringToMessage(message, event.get(), options).ok()) {
                        EventHandler::handleFriendAddRequest(bot_map.at(event->self_id()), event);
                    } else {
                        LOG_INFO << "Failed to parse the reported content as a friend add request event.";
                    }
                    break;
                }
                case cqhttp::group: {
                    std::shared_ptr<cqhttp::GroupAddRequestEvent> event(new cqhttp::GroupAddRequestEvent());
                    if (JsonStringToMessage(message, event.get(), options).ok()) {
                        EventHandler::handleGroupAddRequest(bot_map.at(event->self_id()), event);
                    } else {
                        LOG_INFO << "Failed to parse the reported content as a group add request event.";
                    }
                    break;
                }
                default:
                    break;
            }

            // Handle meta events.
            switch (base_event.meta_event_type()) {
                case cqhttp::heartbeat:
                    break;
                case cqhttp::lifecycle: {
                    cqhttp::LifecycleEvent event;
                    if (JsonStringToMessage(message, &event, options).ok()) {
                        if (event.sub_type() == cqhttp::connect) {
                            bot_map.insert(std::make_pair(event.self_id(), std::make_shared<Bot>(ptr)));
                            LOG_INFO << "New connection from " << event.self_id();
                        }
                        if (event.sub_type() == cqhttp::disable) {
                            bot_map.erase(event.self_id());
                            LOG_INFO << event.self_id() << " is disconnected.";
                        }
                    } else {
                        LOG_INFO << "Failed to parse into lifecycle event message.";
                    }
                    break;
                }
                default:
                    break;
            }
        } else {
            LOG_INFO << status.message().ToString();
        }
    }).detach();

}

void WebsocketController::handleNewConnection(const drogon::HttpRequestPtr &ptr,
                                              const drogon::WebSocketConnectionPtr &connectionPtr) {

}

void WebsocketController::handleConnectionClosed(const drogon::WebSocketConnectionPtr &ptr) {
    std::map<int64_t, std::shared_ptr<Bot>>::iterator it = bot_map.begin();
    for (; it != bot_map.end();) {
        if (it->second->bot->disconnected()) {
            LOG_INFO << it->first << " is disconnected.";
            bot_map.erase(it++);
            continue;
        }
        it++;
    }
}
