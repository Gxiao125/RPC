#include <unordered_map>
#include <google/protobuf/service.h>

class RpcServer {
    public:
        void RegisterService(google::protobuf::Service* service);
        void Start(int port);

    private:
        void HandleConnection(int client_fd);
        std::unordered_map<std::string, google::protobuf::Service*> services_;
};