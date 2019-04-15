//
// Created by Christopher Jaramillo on 2019-04-14.
//

#ifndef ATTACKIQ_AIQTRANSLATIONSERVERIMPL_H
#define ATTACKIQ_AIQTRANSLATIONSERVERIMPL_H

#include <grpcpp/server_context.h>

#include "generated/aiq_server.grpc.pb.h"

namespace AIQ {
class AiqTranslationServerImpl final : public AiqTranslationServer::Service {
    public:
	AiqTranslationServerImpl();

        grpc::Status Translate(grpc::ServerContext *,
                               const Translatable *,
                               Translation *);

        grpc::Status SourceLanguage(grpc::ServerContext *,
                                    const Source *,
                                    Language *);
    };
}

#endif //ATTACKIQ_AIQTRANSLATIONSERVERIMPL_H
