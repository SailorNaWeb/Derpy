cmake_minimum_required(VERSION 3.10)

project(Derpy)

add_executable(Derpy src/main.cpp)

target_include_directories(Derpy PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")

target_link_libraries(Derpy PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/bin/discord-rpc.dll")

if (WIN32)
    target_link_libraries(Derpy PRIVATE "ws2_32")
endif()
