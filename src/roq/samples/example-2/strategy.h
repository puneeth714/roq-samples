/* Copyright (c) 2017-2021, Hans Erik Thrane */

#pragma once

#include "roq/api.h"
#include "roq/client.h"

#include "roq/samples/example-2/instrument.h"

namespace roq {
namespace samples {
namespace example_2 {

// strategy implementation

class Strategy final : public client::Handler {
 public:
  explicit Strategy(client::Dispatcher &);

  Strategy(Strategy &&) = default;
  Strategy(const Strategy &) = delete;

 protected:
  void operator()(const Event<Connected> &) override;
  void operator()(const Event<Disconnected> &) override;
  void operator()(const Event<DownloadBegin> &) override;
  void operator()(const Event<DownloadEnd> &) override;
  void operator()(const Event<GatewaySettings> &) override;
  void operator()(const Event<GatewayStatus> &) override;
  void operator()(const Event<ReferenceData> &) override;
  void operator()(const Event<MarketStatus> &) override;
  void operator()(const Event<MarketByPriceUpdate> &) override;

  // helper - dispatch event to the relevant instrument
  template <typename T>
  void dispatch(const T &event);

 private:
  client::Dispatcher &dispatcher_;
  Instrument futures_;
  Instrument cash_;
};

}  // namespace example_2
}  // namespace samples
}  // namespace roq
