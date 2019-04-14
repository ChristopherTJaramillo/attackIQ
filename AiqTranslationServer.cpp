//
// Created by Christopher Jaramillo on 2019-04-14.
//

#include "AiqTranslationServer.h"

#include <grpc/grpc.h>
#include <grpcpp/server.h>



grpc::Status
AIQ::AiqTranslationServerImpl::Translate(grpc::ServerContext *context,
                                     const Translatable *aTranslatable,
                                     Translation *aTranslation)
{
    aTranslation->set_messageid("1");
    aTranslation->set_sourcemessageid(aTranslatable->messageid());
    aTranslation->set_receiver("3");
    aTranslation->set_sourcemessage(aTranslatable->message());
    aTranslation->set_translatedmessage("4");
    return grpc::Status::OK;
}

grpc::Status
AIQ::AiqTranslationServerImpl::SourceLanguage(grpc::ServerContext *context,
                                          const Source *aSource,
                                          Language *aLanguage)
{
    aLanguage->set_messageid("1");
    aLanguage->set_sourcemessageid("2");
    aLanguage->set_receiver("4");
    aLanguage->set_sourcelanguage("5");
    return grpc::Status::OK;
}