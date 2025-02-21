#pragma once

#include <string>

class Channel {
    public:
        explicit Channel(const std::string& server_ip, int port);
        bool Send(const std::string& data);
        bool Recevive(std::string* data);
        ~Channel();

    private:
        int sock_fd_;
};
