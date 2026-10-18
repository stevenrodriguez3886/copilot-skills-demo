#ifndef TELEMETRY_MODULE_TEMPLATE_HPP
#define TELEMETRY_MODULE_TEMPLATE_HPP

#include "telemetry_types.hpp"
#include <cstdint>
#include <cstddef>

namespace telemetry {

class ModuleName final {
public:
    ModuleName() noexcept = default;
    ~ModuleName() noexcept = default;

    ModuleName(const ModuleName&) = delete;
    ModuleName& operator=(const ModuleName&) = delete;

    // All operational methods must be noexcept and return telemetry::Status
    [[nodiscard]] static Status execute(
        const uint8_t* input_buf,
        size_t input_len,
        Packet* out_packet) noexcept;
};

} // namespace telemetry

#endif // TELEMETRY_MODULE_TEMPLATE_HPP