/*
 *  Copyright (c) 2017-present, Facebook, Inc.
 *
 *  This source code is licensed under the MIT license found in the LICENSE
 *  file in the root directory of this source tree.
 *
 */

/*
 *  THIS FILE IS AUTOGENERATED. DO NOT MODIFY IT; ALL CHANGES WILL BE LOST IN
 *  VAIN.
 *
 *  @generated
 */
#pragma once

#include <exception>
#include <memory>

#include <mcrouter/lib/network/RpcStatsContext.h>
#include <mcrouter/lib/network/ThriftTransport.h>
#include <mcrouter/McrouterFiberContext.h>
#include <thrift/lib/cpp/TApplicationException.h>
#include <thrift/lib/cpp/transport/TTransportException.h>
#include <thrift/lib/cpp2/async/RequestChannel.h>

#include "mcrouter/lib/carbon/example/gen/gen-cpp2/HelloGoodbyeAsyncClient.h"

namespace facebook {
namespace memcache {

template <>
class ThriftTransportMethods<hellogoodbye::HelloGoodbyeRouterInfo> : public ThriftTransportUtil {
 public:
  ThriftTransportMethods() = default;
  virtual ~ThriftTransportMethods() override = default;

void sendSyncHelper(
    typename hellogoodbye::HelloGoodbyeRouterInfo::RouteHandleAsyncClient* thriftClient,
    const hellogoodbye::GoodbyeRequest& request,
    apache::thrift::RpcOptions& rpcOptions,
    folly::Try<apache::thrift::RpcResponseComplete<hellogoodbye::GoodbyeReply>>& reply,
    RpcStatsContext* rpcStatsContext = nullptr) {
  bool needServerLoad = mcrouter::fiber_local<hellogoodbye::HelloGoodbyeRouterInfo>::getThriftServerLoadEnabled();
  if (UNLIKELY(needServerLoad)) {
    rpcOptions.setWriteHeader(kLoadHeader, kDefaultLoadCounter);
  }
  const auto& cryptoAuthToken = request.getCryptoAuthToken();
  if (UNLIKELY(cryptoAuthToken.has_value())) {
    rpcOptions.setWriteHeader(
        std::string{carbon::MessageCommon::kCryptoAuthTokenHeader}, cryptoAuthToken.value());
  }

#ifndef LIBMC_FBTRACE_DISABLE
  traceRequest(request, rpcOptions);
#endif
  reply = thriftClient->sync_complete_goodbye(
      rpcOptions, request);
  if (rpcStatsContext && reply.hasValue()) {
      auto& stats = reply->responseContext.rpcSizeStats;
      rpcStatsContext->requestBodySize = stats.requestSerializedSizeBytes;
      rpcStatsContext->replySizeBeforeCompression = stats.responseSerializedSizeBytes;
      rpcStatsContext->replySizeAfterCompression = stats.responseWireSizeBytes;
      if (needServerLoad && reply->responseContext.serverLoad) {
        rpcStatsContext->serverLoad = ServerLoad(
            static_cast<int32_t>(*reply->responseContext.serverLoad));
      }
  }
#ifndef LIBMC_FBTRACE_DISABLE
  traceResponse(request, reply);
#endif
}

void sendSyncHelper(
    typename hellogoodbye::HelloGoodbyeRouterInfo::RouteHandleAsyncClient* thriftClient,
    const hellogoodbye::HelloRequest& request,
    apache::thrift::RpcOptions& rpcOptions,
    folly::Try<apache::thrift::RpcResponseComplete<hellogoodbye::HelloReply>>& reply,
    RpcStatsContext* rpcStatsContext = nullptr) {
  bool needServerLoad = mcrouter::fiber_local<hellogoodbye::HelloGoodbyeRouterInfo>::getThriftServerLoadEnabled();
  if (UNLIKELY(needServerLoad)) {
    rpcOptions.setWriteHeader(kLoadHeader, kDefaultLoadCounter);
  }
  const auto& cryptoAuthToken = request.getCryptoAuthToken();
  if (UNLIKELY(cryptoAuthToken.has_value())) {
    rpcOptions.setWriteHeader(
        std::string{carbon::MessageCommon::kCryptoAuthTokenHeader}, cryptoAuthToken.value());
  }

#ifndef LIBMC_FBTRACE_DISABLE
  traceRequest(request, rpcOptions);
#endif
        rpcOptions.setWriteHeader("shardId", folly::to<std::string>(*request.shardId_ref()));
        rpcOptions.setWriteHeader("message", folly::to<std::string>(*request.message_ref()));
        rpcOptions.setWriteHeader("priority", folly::to<std::string>(*request.priority_ref()));
  reply = thriftClient->sync_complete_hello(
      rpcOptions, request);
  if (rpcStatsContext && reply.hasValue()) {
      auto& stats = reply->responseContext.rpcSizeStats;
      rpcStatsContext->requestBodySize = stats.requestSerializedSizeBytes;
      rpcStatsContext->replySizeBeforeCompression = stats.responseSerializedSizeBytes;
      rpcStatsContext->replySizeAfterCompression = stats.responseWireSizeBytes;
      if (needServerLoad && reply->responseContext.serverLoad) {
        rpcStatsContext->serverLoad = ServerLoad(
            static_cast<int32_t>(*reply->responseContext.serverLoad));
      }
  }
#ifndef LIBMC_FBTRACE_DISABLE
  traceResponse(request, reply);
#endif
}

void sendSyncHelper(
    typename hellogoodbye::HelloGoodbyeRouterInfo::RouteHandleAsyncClient* thriftClient,
    const McVersionRequest& request,
    apache::thrift::RpcOptions& rpcOptions,
    folly::Try<apache::thrift::RpcResponseComplete<McVersionReply>>& reply,
    RpcStatsContext* rpcStatsContext = nullptr) {
  bool needServerLoad = mcrouter::fiber_local<hellogoodbye::HelloGoodbyeRouterInfo>::getThriftServerLoadEnabled();
  if (UNLIKELY(needServerLoad)) {
    rpcOptions.setWriteHeader(kLoadHeader, kDefaultLoadCounter);
  }
  const auto& cryptoAuthToken = request.getCryptoAuthToken();
  if (UNLIKELY(cryptoAuthToken.has_value())) {
    rpcOptions.setWriteHeader(
        std::string{carbon::MessageCommon::kCryptoAuthTokenHeader}, cryptoAuthToken.value());
  }

#ifndef LIBMC_FBTRACE_DISABLE
  traceRequest(request, rpcOptions);
#endif
  reply = thriftClient->sync_complete_mcVersion(
      rpcOptions, request);
  if (rpcStatsContext && reply.hasValue()) {
      auto& stats = reply->responseContext.rpcSizeStats;
      rpcStatsContext->requestBodySize = stats.requestSerializedSizeBytes;
      rpcStatsContext->replySizeBeforeCompression = stats.responseSerializedSizeBytes;
      rpcStatsContext->replySizeAfterCompression = stats.responseWireSizeBytes;
      if (needServerLoad && reply->responseContext.serverLoad) {
        rpcStatsContext->serverLoad = ServerLoad(
            static_cast<int32_t>(*reply->responseContext.serverLoad));
      }
  }
#ifndef LIBMC_FBTRACE_DISABLE
  traceResponse(request, reply);
#endif
}

};

template <>
class ThriftTransport<hellogoodbye::HelloGoodbyeRouterInfo> : public ThriftTransportMethods<hellogoodbye::HelloGoodbyeRouterInfo>,
                                       public ThriftTransportBase {
 public:
  ThriftTransport(folly::EventBase& eventBase, ConnectionOptions options)
      : ThriftTransportBase(eventBase, std::move(options)) {}
  ThriftTransport(folly::VirtualEventBase& eventBase, ConnectionOptions options)
      : ThriftTransportBase(eventBase.getEventBase(), std::move(options)) {}
  ~ThriftTransport() override {
    resetClient();
  }

  void setFlushList(FlushList* flushList) override final {
    flushList_ = flushList;
    if (thriftClient_) {
      auto* channel = static_cast<apache::thrift::RocketClientChannel*>(
          thriftClient_->getChannel());
      channel->setFlushList(flushList_);
    }
  }

  hellogoodbye::GoodbyeReply sendSync(
      const hellogoodbye::GoodbyeRequest& request,
      std::chrono::milliseconds timeout,
      RpcStatsContext* rpcStatsContext = nullptr) {
    DestructorGuard dg(this);

    return sendSyncImpl([this, &request, timeout, rpcStatsContext] {
      folly::Try<apache::thrift::RpcResponseComplete<hellogoodbye::GoodbyeReply>> reply;
      if (auto* thriftClient = getThriftClient()) {
        auto rpcOptions = getRpcOptions(timeout);
        sendSyncHelper(thriftClient, request, rpcOptions, reply, rpcStatsContext);
      } else {
        reply.emplaceException(
            folly::make_exception_wrapper<apache::thrift::transport::TTransportException>(
              apache::thrift::transport::TTransportException::NOT_OPEN,
              "Error creating thrift client."));
      }
      return reply;
    });
  }

  hellogoodbye::HelloReply sendSync(
      const hellogoodbye::HelloRequest& request,
      std::chrono::milliseconds timeout,
      RpcStatsContext* rpcStatsContext = nullptr) {
    DestructorGuard dg(this);

    return sendSyncImpl([this, &request, timeout, rpcStatsContext] {
      folly::Try<apache::thrift::RpcResponseComplete<hellogoodbye::HelloReply>> reply;
      if (auto* thriftClient = getThriftClient()) {
        auto rpcOptions = getRpcOptions(timeout);
        sendSyncHelper(thriftClient, request, rpcOptions, reply, rpcStatsContext);
      } else {
        reply.emplaceException(
            folly::make_exception_wrapper<apache::thrift::transport::TTransportException>(
              apache::thrift::transport::TTransportException::NOT_OPEN,
              "Error creating thrift client."));
      }
      return reply;
    });
  }

  McVersionReply sendSync(
      const McVersionRequest& request,
      std::chrono::milliseconds timeout,
      RpcStatsContext* rpcStatsContext = nullptr) {
    DestructorGuard dg(this);

    return sendSyncImpl([this, &request, timeout, rpcStatsContext] {
      folly::Try<apache::thrift::RpcResponseComplete<McVersionReply>> reply;
      if (auto* thriftClient = getThriftClient()) {
        auto rpcOptions = getRpcOptions(timeout);
        sendSyncHelper(thriftClient, request, rpcOptions, reply, rpcStatsContext);
      } else {
        reply.emplaceException(
            folly::make_exception_wrapper<apache::thrift::transport::TTransportException>(
              apache::thrift::transport::TTransportException::NOT_OPEN,
              "Error creating thrift client."));
      }
      return reply;
    });
  }

 private:
  std::unique_ptr<hellogoodbye::thrift::HelloGoodbyeAsyncClient> thriftClient_;
  FlushList* flushList_{nullptr};

  hellogoodbye::thrift::HelloGoodbyeAsyncClient* getThriftClient() {
    if (UNLIKELY(!thriftClient_)) {
      thriftClient_ = createThriftClient<hellogoodbye::thrift::HelloGoodbyeAsyncClient>();
      if (flushList_) {
        auto* channel = static_cast<apache::thrift::RocketClientChannel*>(
            thriftClient_->getChannel());
        channel->setFlushList(flushList_);
      }
    }
    return thriftClient_.get();
  }

  void resetClient() override final {
    if (thriftClient_) {
      if (auto channel = thriftClient_->getChannel()) {
        // Reset the callback to avoid the following cycle:
        //  ~ThriftAsyncClient() -> ~RocketClientChannel() ->
        //  channelClosed() -> ~ThriftAsyncClient()
        channel->setCloseCallback(nullptr);
      }
      thriftClient_.reset();
    }
  }
};

} // namespace memcache
} // namespace facebook