/* Copyright (c) 2017-2021, Hans Erik Thrane */

#include "roq/samples/example-5/strategy.h"

#include "roq/logging.h"

using namespace roq::literals;

namespace roq {
namespace samples {
namespace example_5 {

Strategy::Strategy(client::Dispatcher &dispatcher) : dispatcher_(dispatcher) {
}

void Strategy::operator()(const Event<Connection> &event) {
  log::info(
      "[{}:{}] Connection={}"_fmt,
      event.message_info.source,
      event.message_info.source_name,
      event.value);
}

void Strategy::operator()(const Event<DownloadBegin> &event) {
  log::info(
      "[{}:{}] DownloadBegin={}"_fmt,
      event.message_info.source,
      event.message_info.source_name,
      event.value);
}

void Strategy::operator()(const Event<DownloadEnd> &event) {
  log::info(
      "[{}:{}] DownloadEnd={}"_fmt,
      event.message_info.source,
      event.message_info.source_name,
      event.value);
}

void Strategy::operator()(const Event<GatewaySettings> &event) {
  log::info(
      "[{}:{}] Settings={}"_fmt,
      event.message_info.source,
      event.message_info.source_name,
      event.value);
}

void Strategy::operator()(const Event<StreamUpdate> &event) {
  log::info(
      "[{}:{}] StreamUpdate={}"_fmt,
      event.message_info.source,
      event.message_info.source_name,
      event.value);
}

void Strategy::operator()(const Event<ExternalLatency> &event) {
  // only verbose logging, see comment in header
  log::trace_1(
      "[{}:{}] ExternalLatency={}"_fmt,
      event.message_info.source,
      event.message_info.source_name,
      event.value);
}

void Strategy::operator()(const Event<ReferenceData> &event) {
  log::info(
      "[{}:{}] ReferenceData={}"_fmt,
      event.message_info.source,
      event.message_info.source_name,
      event.value);
}

void Strategy::operator()(const Event<MarketStatus> &event) {
  log::info(
      "[{}:{}] MarketStatus={}"_fmt,
      event.message_info.source,
      event.message_info.source_name,
      event.value);
}

void Strategy::operator()(const Event<MarketByPriceUpdate> &event) {
  // only verbose logging, see comment in header
  log::trace_1(
      "[{}:{}] MarketByPriceUpdate={}"_fmt,
      event.message_info.source,
      event.message_info.source_name,
      event.value);
}

void Strategy::operator()(const Event<MarketByOrderUpdate> &event) {
  // only verbose logging, see comment in header
  log::trace_1(
      "[{}:{}] MarketByOrderUpdate={}"_fmt,
      event.message_info.source,
      event.message_info.source_name,
      event.value);
}

void Strategy::operator()(const Event<TradeSummary> &event) {
  // only verbose logging, see comment in header
  log::trace_1(
      "[{}:{}] TradeSummary={}"_fmt,
      event.message_info.source,
      event.message_info.source_name,
      event.value);
}

}  // namespace example_5
}  // namespace samples
}  // namespace roq