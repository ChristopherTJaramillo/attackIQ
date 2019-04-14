//
// Created by Christopher Jaramillo on 2019-04-12.
//

#include <iostream>
#include <boost/filesystem.hpp>
#include <cstdlib>

#include <grpcpp/server.h>
#include <grpcpp/server_builder.h>
#include <grpcpp/security/server_credentials.h>

#include "AiqTranslationServer.h"

void runServer()
{
    std::string serverAddress("0.0.0.0:12345");
    AIQ::AiqTranslationServerImpl service;
    grpc::ServerBuilder builder;

    builder.AddListeningPort(serverAddress, grpc::InsecureServerCredentials());
    builder.RegisterService(&service);

    std::unique_ptr<grpc::Server> server(builder.BuildAndStart());
    std::cout << "Server running, listening on: " << serverAddress << std::endl;
    server->Wait();
}

auto foo(int i){
    return i + 5;
}

int main(int argc, char *argv[])
{
    std::cout << "Hello World" << std::endl;
    boost::filesystem::path aPath = boost::filesystem::current_path();
    boost::filesystem::directory_iterator it(aPath);
    while(it != boost::filesystem::directory_iterator())
    {
        std::cout << *it++ << std::endl;
    }
    std::cout << "foo(5) = " << foo(5) << std::endl;
    runServer();
    return EXIT_SUCCESS;
}
