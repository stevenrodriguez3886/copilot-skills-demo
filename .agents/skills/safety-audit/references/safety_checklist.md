# Embedded & Systems Safety Verification Checklist

- **SAFE-01 (Pointer Validation):** Every public function accepting a raw pointer (`const uint8_t*`, `Packet*`) must check for `nullptr` before dereferencing and return `Status::ERR_NULL_PTR`.
- **SAFE-02 (Buffer & Wire-Length Bounds):** Never trust a length field extracted from raw wire bytes (`payload_len`). Verify both:
  1. `total_len >= 6 + payload_len` (2 sync bytes + 2 sequence bytes + 1 length byte + payload_len + 1 checksum byte).
  2. `payload_len <= kMaxPayloadBytes` (64 bytes) prior to invoking `std::memcpy`.
- **SAFE-03 (Thread Safety):** Any class maintaining mutable state (`std::vector`, counters, queues) across public methods must synchronize access using a private `mutable std::mutex` and `std::lock_guard<std::mutex>`.
- **SAFE-04 (Arithmetic Safety):** All division or modulo operations on runtime counters or container sizes must check for zero denominators before evaluation.