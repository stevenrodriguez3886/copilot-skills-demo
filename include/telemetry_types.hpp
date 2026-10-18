#ifndef TELEMETRY_TYPES_HPP
#define TELEMETRY_TYPES_HPP

#include <cstdint>
#include <cstddef>

namespace telemetry {

constexpr uint16_t kSyncWord = 0xAA55;
constexpr size_t kMaxPayloadBytes = 64;

enum class Status : uint8_t {
    OK = 0,
    ERR_NULL_PTR = 1,
    ERR_INVALID_SYNC = 2,
    ERR_BOUNDS = 3,
    ERR_CHECKSUM = 4,
    ERR_EMPTY_QUEUE = 5
};

struct Packet {
    uint16_t sync;
    uint16_t sequence_id;
    uint8_t payload_len;
    uint8_t payload[kMaxPayloadBytes];
    uint8_t checksum;
};

} // namespace telemetry

#endif // TELEMETRY_TYPES_HPP