cmake_minimum_required(VERSION 3.3)
project(boost_asio)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        connection.cpp
        connection.h
        connection_manager.cpp
        connection_manager.h
        header.h
        main.cpp
        mime_types.cpp
        mime_types.h
        reply.cpp
        reply.h
        request.h
        request_handler.cpp
        request_handler.h
        request_parser.cpp
        request_parser.h
        server.cpp
        server.h
        )

find_package(Boost)
if (Boost_FOUND)
    set(Boost_LIBRARY_DIR /usr/local/lib)
    include_directories(${Boost_INCLUDE_DIR})
    add_executable(http_server ${SOURCE_FILES})
    target_link_libraries(http_server /usr/local/lib/libboost_system.a)
endif ()