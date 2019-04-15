cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(attackIQ LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
list(APPEND flags "-L$ENV{GRPC_HOME}/libs/opt" "-L$ENV{GRPC_HOME}/libs/opt/protobuf")

find_package(Boost 1.54 REQUIRED COMPONENTS filesystem)

add_library(aiq-grpc
        SHARED
        generated/aiq_server.grpc.pb.h
        generated/aiq_server.grpc.pb.cc
        generated/aiq_server.pb.h
        generated/aiq_server.pb.cc)

target_include_directories(aiq-grpc PRIVATE "$ENV{GRPC_HOME}/include")
target_include_directories(aiq-grpc PRIVATE "$ENV{GRPC_HOME}/third_party/protobuf/src")

link_directories("$ENV{GRPC_HOME}/libs/opt")
link_directories("$ENV{GRPC_HOME}/libs/opt/protobuf")

add_library(aiq-translation-server
        SHARED
        AiqTranslationServer.h
        AiqTranslationServer.cpp)

target_include_directories(aiq-translation-server PRIVATE "$ENV{GRPC_HOME}/include")
target_include_directories(aiq-translation-server PRIVATE "$ENV{GRPC_HOME}/third_party/protobuf/src")


target_link_libraries(aiq-translation-server
        PUBLIC
        aiq-grpc)

target_link_libraries(aiq-translation-server
        PUBLIC
        protobuf
        grpc++
        grpc++_reflection
        dl)
target_compile_options(aiq-translation-server
  PRIVATE
    ${flags}
  )

add_executable(attackIQ main.cpp)

target_include_directories(attackIQ PRIVATE "$ENV{GRPC_HOME}/include")
target_include_directories(attackIQ PRIVATE "$ENV{GRPC_HOME}/third_party/protobuf/src")

target_link_libraries(attackIQ
        PUBLIC
        Boost::filesystem)

target_link_libraries(attackIQ
        PUBLIC
        aiq-translation-server)
