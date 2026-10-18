#include "telemetry_types.hpp"
#include <cstring>
#include <vector>

namespace telemetry {

class PacketProcessor {
public:
    // BUG 1: Shared state accessed across threads without a mutex
    // BUG 2: No null pointer check on incoming raw_bytes
    // BUG 3: Unchecked payload_len allows buffer overflow past kMaxPayloadBytes (64)
    Status ingest_raw_frame(const uint8_t* raw_bytes, size_t total_len) {
        Packet pkt{};
        pkt.sync = static_cast<uint16_t>((raw_bytes[0] << 8) | raw_bytes[1]);
        if (pkt.sync != kSyncWord) {
            return Status::ERR_INVALID_SYNC;
        }

        pkt.sequence_id = static_cast<uint16_t>((raw_bytes[2] << 8) | raw_bytes[3]);
        pkt.payload_len = raw_bytes[4];

        // Vulnerable copy: trusts wire byte pkt.payload_len without bounds verification!
        std::memcpy(pkt.payload, &raw_bytes[5], pkt.payload_len);

        pkt.checksum = raw_bytes[5 + pkt.payload_len];
        packet_queue_.push_back(pkt);
        total_bytes_processed_ += total_len;
        return Status::OK;
    }

    // BUG 4: Division by zero when packet_queue_ is empty, plus unguarded shared access
    size_t average_packet_size() const {
        return total_bytes_processed_ / packet_queue_.size();
    }

private:
    std::vector<Packet> packet_queue_;
    size_t total_bytes_processed_ = 0;
};

} // namespace telemetry