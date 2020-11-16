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

#include <chrono>
#include <functional>
#include <unordered_map>

#include <folly/Range.h>

#include <mcrouter/lib/carbon/Stats.h>

#include "mcrouter/lib/carbon/test/gen/CarbonTestRouteHandleIf.h"
#include "mcrouter/lib/carbon/test/gen/CarbonTestRouterStats.h"

// Forward declarations
namespace folly {
struct dynamic;
class VirtualEventBase;
} // namespace folly

namespace facebook {
namespace memcache {
template <class RouteHandleIf>
class RouteHandleFactory;
namespace mcrouter {
template <class RouterInfo>
class ExtraRouteHandleProviderIf;
class ProxyBase;
} // namespace mcrouter
} // namespace memcache
} // namespace facebook

namespace carbon {
namespace test {

namespace detail {

using CarbonTestRoutableRequests = carbon::List<
    AnotherRequest,
    TestRequest,
    TestRequestStringKey,
    test2::util::YetAnotherRequest>;
} // namespace detail

struct CarbonTestRouterInfo {
  using RouteHandleIf = CarbonTestRouteHandleIf;
  using RouteHandlePtr = std::shared_ptr<RouteHandleIf>;

  static constexpr const char* name = "CarbonTest";

  template <class Route>
  using RouteHandle = CarbonTestRouteHandle<Route>;
  using RoutableRequests = detail::CarbonTestRoutableRequests;
  
  using RouterStats = carbon::Stats<CarbonTestRouterStatsConfig>;

  using RouteHandleFactoryMap = std::unordered_map<
      folly::StringPiece,
      std::function<RouteHandlePtr(
          facebook::memcache::RouteHandleFactory<RouteHandleIf>&,
          const folly::dynamic&)>,
      folly::Hash>;

  using RouteHandleFactoryMapWithProxy = std::unordered_map<
      folly::StringPiece,
      std::function<RouteHandlePtr(
          facebook::memcache::RouteHandleFactory<RouteHandleIf>&,
          const folly::dynamic&,
          facebook::memcache::mcrouter::ProxyBase&)>,
      folly::Hash>;

  static RouteHandleFactoryMap buildRouteMap();
  static RouteHandleFactoryMapWithProxy buildRouteMapWithProxy();

  static std::unique_ptr<facebook::memcache::mcrouter::
                             ExtraRouteHandleProviderIf<CarbonTestRouterInfo>>
  buildExtraProvider();
};
} // namespace test
} // namespace carbon
