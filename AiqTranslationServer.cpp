//
// Created by Christopher Jaramillo on 2019-04-14.
//

#include "AiqTranslationServer.h"

#include <sstream>

#include <grpc/grpc.h>
#include <grpcpp/server.h>

#include "AiqCurlWrapper.h"

AIQ::AiqTranslationServerImpl::AiqTranslationServerImpl()
{
    AIQ::AiqCurlWrapper::instance().init();
}

grpc::Status
AIQ::AiqTranslationServerImpl::Translate(grpc::ServerContext *context,
                                     const Translatable *aTranslatable,
                                     Translation *aTranslation)
{
    std::string readBuffer;
    std::stringstream ss;
    ss << "https://translation.googleapis.com/language/translate/v2?target=es&key=";
    ss << aTranslatable->apikey();
    ss << "&q=" << aTranslatable->message();
    AIQ::AiqCurlWrapper::instance().post(ss.str(), "", readBuffer);
    aTranslation->set_messageid("1");
    aTranslation->set_sourcemessageid(aTranslatable->messageid());
    aTranslation->set_receiver("3");
    aTranslation->set_sourcemessage(aTranslatable->message());
    aTranslation->set_translatedmessage(readBuffer);
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
