// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: aiq_server.proto
#ifndef GRPC_aiq_5fserver_2eproto__INCLUDED
#define GRPC_aiq_5fserver_2eproto__INCLUDED

#include "aiq_server.pb.h"

#include <functional>
#include <grpcpp/impl/codegen/async_generic_service.h>
#include <grpcpp/impl/codegen/async_stream.h>
#include <grpcpp/impl/codegen/async_unary_call.h>
#include <grpcpp/impl/codegen/client_callback.h>
#include <grpcpp/impl/codegen/method_handler_impl.h>
#include <grpcpp/impl/codegen/proto_utils.h>
#include <grpcpp/impl/codegen/rpc_method.h>
#include <grpcpp/impl/codegen/server_callback.h>
#include <grpcpp/impl/codegen/service_type.h>
#include <grpcpp/impl/codegen/status.h>
#include <grpcpp/impl/codegen/stub_options.h>
#include <grpcpp/impl/codegen/sync_stream.h>

namespace grpc {
class CompletionQueue;
class Channel;
class ServerCompletionQueue;
class ServerContext;
}  // namespace grpc

class AiqTranslationServer final {
 public:
  static constexpr char const* service_full_name() {
    return "AiqTranslationServer";
  }
  class StubInterface {
   public:
    virtual ~StubInterface() {}
    virtual ::grpc::Status Translate(::grpc::ClientContext* context, const ::Translatable& request, ::Translation* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::Translation>> AsyncTranslate(::grpc::ClientContext* context, const ::Translatable& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::Translation>>(AsyncTranslateRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::Translation>> PrepareAsyncTranslate(::grpc::ClientContext* context, const ::Translatable& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::Translation>>(PrepareAsyncTranslateRaw(context, request, cq));
    }
    virtual ::grpc::Status SourceLanguage(::grpc::ClientContext* context, const ::Source& request, ::Language* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::Language>> AsyncSourceLanguage(::grpc::ClientContext* context, const ::Source& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::Language>>(AsyncSourceLanguageRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::Language>> PrepareAsyncSourceLanguage(::grpc::ClientContext* context, const ::Source& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::Language>>(PrepareAsyncSourceLanguageRaw(context, request, cq));
    }
    class experimental_async_interface {
     public:
      virtual ~experimental_async_interface() {}
      virtual void Translate(::grpc::ClientContext* context, const ::Translatable* request, ::Translation* response, std::function<void(::grpc::Status)>) = 0;
      virtual void SourceLanguage(::grpc::ClientContext* context, const ::Source* request, ::Language* response, std::function<void(::grpc::Status)>) = 0;
    };
    virtual class experimental_async_interface* experimental_async() { return nullptr; }
  private:
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::Translation>* AsyncTranslateRaw(::grpc::ClientContext* context, const ::Translatable& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::Translation>* PrepareAsyncTranslateRaw(::grpc::ClientContext* context, const ::Translatable& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::Language>* AsyncSourceLanguageRaw(::grpc::ClientContext* context, const ::Source& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::Language>* PrepareAsyncSourceLanguageRaw(::grpc::ClientContext* context, const ::Source& request, ::grpc::CompletionQueue* cq) = 0;
  };
  class Stub final : public StubInterface {
   public:
    Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel);
    ::grpc::Status Translate(::grpc::ClientContext* context, const ::Translatable& request, ::Translation* response) override;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::Translation>> AsyncTranslate(::grpc::ClientContext* context, const ::Translatable& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::Translation>>(AsyncTranslateRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::Translation>> PrepareAsyncTranslate(::grpc::ClientContext* context, const ::Translatable& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::Translation>>(PrepareAsyncTranslateRaw(context, request, cq));
    }
    ::grpc::Status SourceLanguage(::grpc::ClientContext* context, const ::Source& request, ::Language* response) override;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::Language>> AsyncSourceLanguage(::grpc::ClientContext* context, const ::Source& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::Language>>(AsyncSourceLanguageRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::Language>> PrepareAsyncSourceLanguage(::grpc::ClientContext* context, const ::Source& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::Language>>(PrepareAsyncSourceLanguageRaw(context, request, cq));
    }
    class experimental_async final :
      public StubInterface::experimental_async_interface {
     public:
      void Translate(::grpc::ClientContext* context, const ::Translatable* request, ::Translation* response, std::function<void(::grpc::Status)>) override;
      void SourceLanguage(::grpc::ClientContext* context, const ::Source* request, ::Language* response, std::function<void(::grpc::Status)>) override;
     private:
      friend class Stub;
      explicit experimental_async(Stub* stub): stub_(stub) { }
      Stub* stub() { return stub_; }
      Stub* stub_;
    };
    class experimental_async_interface* experimental_async() override { return &async_stub_; }

   private:
    std::shared_ptr< ::grpc::ChannelInterface> channel_;
    class experimental_async async_stub_{this};
    ::grpc::ClientAsyncResponseReader< ::Translation>* AsyncTranslateRaw(::grpc::ClientContext* context, const ::Translatable& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientAsyncResponseReader< ::Translation>* PrepareAsyncTranslateRaw(::grpc::ClientContext* context, const ::Translatable& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientAsyncResponseReader< ::Language>* AsyncSourceLanguageRaw(::grpc::ClientContext* context, const ::Source& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientAsyncResponseReader< ::Language>* PrepareAsyncSourceLanguageRaw(::grpc::ClientContext* context, const ::Source& request, ::grpc::CompletionQueue* cq) override;
    const ::grpc::internal::RpcMethod rpcmethod_Translate_;
    const ::grpc::internal::RpcMethod rpcmethod_SourceLanguage_;
  };
  static std::unique_ptr<Stub> NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options = ::grpc::StubOptions());

  class Service : public ::grpc::Service {
   public:
    Service();
    virtual ~Service();
    virtual ::grpc::Status Translate(::grpc::ServerContext* context, const ::Translatable* request, ::Translation* response);
    virtual ::grpc::Status SourceLanguage(::grpc::ServerContext* context, const ::Source* request, ::Language* response);
  };
  template <class BaseClass>
  class WithAsyncMethod_Translate : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithAsyncMethod_Translate() {
      ::grpc::Service::MarkMethodAsync(0);
    }
    ~WithAsyncMethod_Translate() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status Translate(::grpc::ServerContext* context, const ::Translatable* request, ::Translation* response) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestTranslate(::grpc::ServerContext* context, ::Translatable* request, ::grpc::ServerAsyncResponseWriter< ::Translation>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(0, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithAsyncMethod_SourceLanguage : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithAsyncMethod_SourceLanguage() {
      ::grpc::Service::MarkMethodAsync(1);
    }
    ~WithAsyncMethod_SourceLanguage() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status SourceLanguage(::grpc::ServerContext* context, const ::Source* request, ::Language* response) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestSourceLanguage(::grpc::ServerContext* context, ::Source* request, ::grpc::ServerAsyncResponseWriter< ::Language>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(1, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  typedef WithAsyncMethod_Translate<WithAsyncMethod_SourceLanguage<Service > > AsyncService;
  template <class BaseClass>
  class ExperimentalWithCallbackMethod_Translate : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    ExperimentalWithCallbackMethod_Translate() {
      ::grpc::Service::experimental().MarkMethodCallback(0,
        new ::grpc::internal::CallbackUnaryHandler< ::Translatable, ::Translation>(
          [this](::grpc::ServerContext* context,
                 const ::Translatable* request,
                 ::Translation* response,
                 ::grpc::experimental::ServerCallbackRpcController* controller) {
                   return this->Translate(context, request, response, controller);
                 }));
    }
    ~ExperimentalWithCallbackMethod_Translate() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status Translate(::grpc::ServerContext* context, const ::Translatable* request, ::Translation* response) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual void Translate(::grpc::ServerContext* context, const ::Translatable* request, ::Translation* response, ::grpc::experimental::ServerCallbackRpcController* controller) { controller->Finish(::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "")); }
  };
  template <class BaseClass>
  class ExperimentalWithCallbackMethod_SourceLanguage : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    ExperimentalWithCallbackMethod_SourceLanguage() {
      ::grpc::Service::experimental().MarkMethodCallback(1,
        new ::grpc::internal::CallbackUnaryHandler< ::Source, ::Language>(
          [this](::grpc::ServerContext* context,
                 const ::Source* request,
                 ::Language* response,
                 ::grpc::experimental::ServerCallbackRpcController* controller) {
                   return this->SourceLanguage(context, request, response, controller);
                 }));
    }
    ~ExperimentalWithCallbackMethod_SourceLanguage() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status SourceLanguage(::grpc::ServerContext* context, const ::Source* request, ::Language* response) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual void SourceLanguage(::grpc::ServerContext* context, const ::Source* request, ::Language* response, ::grpc::experimental::ServerCallbackRpcController* controller) { controller->Finish(::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "")); }
  };
  typedef ExperimentalWithCallbackMethod_Translate<ExperimentalWithCallbackMethod_SourceLanguage<Service > > ExperimentalCallbackService;
  template <class BaseClass>
  class WithGenericMethod_Translate : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithGenericMethod_Translate() {
      ::grpc::Service::MarkMethodGeneric(0);
    }
    ~WithGenericMethod_Translate() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status Translate(::grpc::ServerContext* context, const ::Translatable* request, ::Translation* response) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithGenericMethod_SourceLanguage : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithGenericMethod_SourceLanguage() {
      ::grpc::Service::MarkMethodGeneric(1);
    }
    ~WithGenericMethod_SourceLanguage() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status SourceLanguage(::grpc::ServerContext* context, const ::Source* request, ::Language* response) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithRawMethod_Translate : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithRawMethod_Translate() {
      ::grpc::Service::MarkMethodRaw(0);
    }
    ~WithRawMethod_Translate() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status Translate(::grpc::ServerContext* context, const ::Translatable* request, ::Translation* response) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestTranslate(::grpc::ServerContext* context, ::grpc::ByteBuffer* request, ::grpc::ServerAsyncResponseWriter< ::grpc::ByteBuffer>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(0, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithRawMethod_SourceLanguage : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithRawMethod_SourceLanguage() {
      ::grpc::Service::MarkMethodRaw(1);
    }
    ~WithRawMethod_SourceLanguage() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status SourceLanguage(::grpc::ServerContext* context, const ::Source* request, ::Language* response) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestSourceLanguage(::grpc::ServerContext* context, ::grpc::ByteBuffer* request, ::grpc::ServerAsyncResponseWriter< ::grpc::ByteBuffer>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(1, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class ExperimentalWithRawCallbackMethod_Translate : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    ExperimentalWithRawCallbackMethod_Translate() {
      ::grpc::Service::experimental().MarkMethodRawCallback(0,
        new ::grpc::internal::CallbackUnaryHandler< ::grpc::ByteBuffer, ::grpc::ByteBuffer>(
          [this](::grpc::ServerContext* context,
                 const ::grpc::ByteBuffer* request,
                 ::grpc::ByteBuffer* response,
                 ::grpc::experimental::ServerCallbackRpcController* controller) {
                   this->Translate(context, request, response, controller);
                 }));
    }
    ~ExperimentalWithRawCallbackMethod_Translate() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status Translate(::grpc::ServerContext* context, const ::Translatable* request, ::Translation* response) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual void Translate(::grpc::ServerContext* context, const ::grpc::ByteBuffer* request, ::grpc::ByteBuffer* response, ::grpc::experimental::ServerCallbackRpcController* controller) { controller->Finish(::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "")); }
  };
  template <class BaseClass>
  class ExperimentalWithRawCallbackMethod_SourceLanguage : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    ExperimentalWithRawCallbackMethod_SourceLanguage() {
      ::grpc::Service::experimental().MarkMethodRawCallback(1,
        new ::grpc::internal::CallbackUnaryHandler< ::grpc::ByteBuffer, ::grpc::ByteBuffer>(
          [this](::grpc::ServerContext* context,
                 const ::grpc::ByteBuffer* request,
                 ::grpc::ByteBuffer* response,
                 ::grpc::experimental::ServerCallbackRpcController* controller) {
                   this->SourceLanguage(context, request, response, controller);
                 }));
    }
    ~ExperimentalWithRawCallbackMethod_SourceLanguage() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status SourceLanguage(::grpc::ServerContext* context, const ::Source* request, ::Language* response) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual void SourceLanguage(::grpc::ServerContext* context, const ::grpc::ByteBuffer* request, ::grpc::ByteBuffer* response, ::grpc::experimental::ServerCallbackRpcController* controller) { controller->Finish(::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "")); }
  };
  template <class BaseClass>
  class WithStreamedUnaryMethod_Translate : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithStreamedUnaryMethod_Translate() {
      ::grpc::Service::MarkMethodStreamed(0,
        new ::grpc::internal::StreamedUnaryHandler< ::Translatable, ::Translation>(std::bind(&WithStreamedUnaryMethod_Translate<BaseClass>::StreamedTranslate, this, std::placeholders::_1, std::placeholders::_2)));
    }
    ~WithStreamedUnaryMethod_Translate() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable regular version of this method
    ::grpc::Status Translate(::grpc::ServerContext* context, const ::Translatable* request, ::Translation* response) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    // replace default version of method with streamed unary
    virtual ::grpc::Status StreamedTranslate(::grpc::ServerContext* context, ::grpc::ServerUnaryStreamer< ::Translatable,::Translation>* server_unary_streamer) = 0;
  };
  template <class BaseClass>
  class WithStreamedUnaryMethod_SourceLanguage : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithStreamedUnaryMethod_SourceLanguage() {
      ::grpc::Service::MarkMethodStreamed(1,
        new ::grpc::internal::StreamedUnaryHandler< ::Source, ::Language>(std::bind(&WithStreamedUnaryMethod_SourceLanguage<BaseClass>::StreamedSourceLanguage, this, std::placeholders::_1, std::placeholders::_2)));
    }
    ~WithStreamedUnaryMethod_SourceLanguage() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable regular version of this method
    ::grpc::Status SourceLanguage(::grpc::ServerContext* context, const ::Source* request, ::Language* response) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    // replace default version of method with streamed unary
    virtual ::grpc::Status StreamedSourceLanguage(::grpc::ServerContext* context, ::grpc::ServerUnaryStreamer< ::Source,::Language>* server_unary_streamer) = 0;
  };
  typedef WithStreamedUnaryMethod_Translate<WithStreamedUnaryMethod_SourceLanguage<Service > > StreamedUnaryService;
  typedef Service SplitStreamedService;
  typedef WithStreamedUnaryMethod_Translate<WithStreamedUnaryMethod_SourceLanguage<Service > > StreamedService;
};


#endif  // GRPC_aiq_5fserver_2eproto__INCLUDED
