//
// Created by 17186 on 2/24/2023.
//

#include "WebsocketController.h"

void WebsocketController::handleNewMessage(const drogon::WebSocketConnectionPtr &ptr, std::string &&string,
                                           const drogon::WebSocketMessageType &messageType) {
    if (messageType != drogon::WebSocketMessageType::Text) {
        return;
    }

    // Use multithreading.
    std::thread([=]() {

    }).detach();

}

void WebsocketController::handleNewConnection(const drogon::HttpRequestPtr &ptr,
                                              const drogon::WebSocketConnectionPtr &connectionPtr) {

}

void WebsocketController::handleConnectionClosed(const drogon::WebSocketConnectionPtr &ptr) {

}
