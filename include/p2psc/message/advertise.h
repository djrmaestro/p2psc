#pragma once

#include <p2psc/message/types.h>
#include <spotify/json.hpp>

using namespace spotify::json;

namespace p2psc {
namespace message {

struct Advertise {
  static const MessageType type = kTypeAdvertise;
  std::uint8_t version;
  std::string our_key;
  std::string their_key;
};

inline bool operator==(const Advertise &lhs, const Advertise &rhs) {
  return lhs.version == rhs.version && lhs.our_key == rhs.our_key &&
         lhs.their_key == rhs.their_key;
}
}
}

namespace spotify {
namespace json {
template <> struct default_codec_t<p2psc::message::Advertise> {
  static codec::object_t<p2psc::message::Advertise> codec() {
    auto codec = codec::object<p2psc::message::Advertise>();
    codec.required("version", &p2psc::message::Advertise::version);
    codec.required("our_key", &p2psc::message::Advertise::our_key);
    codec.required("their_key", &p2psc::message::Advertise::their_key);
    return codec;
  }
};
}
}