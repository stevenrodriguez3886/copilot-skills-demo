---
name: module-scaffolder
description: Scaffolds new C++ telemetry modules, parsers, or validators. Use whenever asked to create, generate, or scaffold a new module, parser, or header/implementation pair.
---
# Module Scaffolding Skill

When scaffolding a new C++ module in this repository, you MUST enforce the following deterministic engineering rules:

1. **Read the Structural Template First:** Before writing any code, inspect `.agents/skills/module-scaffolder/assets/module_template.hpp` and match its exact namespace, class layout, and header-guard conventions.
2. **Strict Type & Memory Rules:**
   - Use fixed-width integers (`uint8_t`, `uint16_t`, `uint32_t`, `size_t`) from `<cstdint>` and `<cstddef>`.
   - Return `telemetry::Status` codes for all fallible operations. Never throw C++ exceptions.
   - Do not use dynamic heap allocation (`new`, `malloc`, `std::vector`) inside packet parsing functions; operate strictly on caller-provided buffers or fixed-size structs.
3. **Output Deliverables:**
   - Create the header in `include/<module_name>.hpp` and implementation in `src/<module_name>.cpp`.
   - Register the new `.cpp` file in `CMakeLists.txt` under `telemetry_core`.