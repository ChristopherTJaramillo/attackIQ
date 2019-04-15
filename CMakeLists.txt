cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(attackIQ LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(Boost 1.54 REQUIRED COMPONENTS filesystem)
find_package(CURL REQUIRED)

link_directories("$ENV{GRPC_HOME}/libs/opt")
link_directories("$ENV{GRPC_HOME}/libs/opt/protobuf")

add_library(aiq-curl-wrapper
        SHARED
        AiqCurlWrapper.h
        AiqCurlWrapper.cpp)
target_link_libraries(aiq-curl-wrapper
        PUBLIC
        curl)

add_library(aiq-grpc
        SHARED
        generated/aiq_server.grpc.pb.h
        generated/aiq_server.grpc.pb.cc
        generated/aiq_server.pb.h
        generated/aiq_server.pb.cc)
target_link_libraries(aiq-grpc
        PUBLIC
        protobuf
        grpc++
        grpc++_reflection)

target_include_directories(aiq-grpc PRIVATE "$ENV{GRPC_HOME}/include")
target_include_directories(aiq-grpc PRIVATE "$ENV{GRPC_HOME}/third_party/protobuf/src")


add_library(aiq-translation-server
        SHARED
        AiqTranslationServer.h
        AiqTranslationServer.cpp)

target_include_directories(aiq-translation-server PRIVATE "$ENV{GRPC_HOME}/include")
target_include_directories(aiq-translation-server PRIVATE "$ENV{GRPC_HOME}/third_party/protobuf/src")


target_link_libraries(aiq-translation-server
        PUBLIC
        aiq-grpc
        aiq-curl-wrapper
        protobuf
        grpc++
        grpc++_reflection
        dl)

add_executable(attackIQ main.cpp)

target_include_directories(attackIQ PRIVATE "$ENV{GRPC_HOME}/include")
target_include_directories(attackIQ PRIVATE "$ENV{GRPC_HOME}/third_party/protobuf/src")

target_link_libraries(attackIQ
        PUBLIC
        Boost::filesystem
        curl
        aiq-translation-server)
