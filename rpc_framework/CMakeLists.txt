cmake_minimum_required(VERSION 3.10)
project(RpcFramework)

set(CMAKE_CXX_STANDARD  17)

#set protobuf
find_package(Protobuf REQUIRED)
include_directories(${PROTOBUF_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/generated)

#build
file(GLOB PROTO_FILES proto/*.proto)
protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS $(PROTO_FILES))

#lib
add_library(rpc_framework
        src/channel.cpp
        src/rpc_server.cpp
        ${PROTO_SRCS}
        )

#exec
add_executable(server examples/server_demo.cpp)
target_link_libraries(server rpc_framework ${PROTOBUF_LIBRARIES} pthread)

add_executable(client examples/client_demo.cpp)
target_link_libraries(client rpc_framework ${PROTOBUF_LIBRARIES} pthread)


