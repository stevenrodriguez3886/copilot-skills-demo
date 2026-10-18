---
name: boundary-test-gen
description: Generates boundary-condition unit tests and executes the automated verification script. Use when asked to write tests, verify edge cases, or run the test suite.
---
# Boundary Test Generation & Verification Loop

When generating unit tests for any module in this repository:

1. **Create Deterministic Test File:** Create or update `tests/test_telemetry.cpp` using standard `<cassert>` and `<iostream>` (zero external test framework dependencies).
2. **Mandatory Test Vectors:** You must include explicit test functions covering:
   - Nominal valid packet (valid `0xAA55` sync word, valid XOR checksum, within bounds).
   - Null pointer input (`Status::ERR_NULL_PTR`).
   - Truncated buffer / payload length exceeding `kMaxPayloadBytes` (`Status::ERR_BOUNDS`).
   - Corrupted sync word (`Status::ERR_INVALID_SYNC`) and corrupted XOR checksum (`Status::ERR_CHECKSUM`).
3. **Update Build Config:** Ensure `CMakeLists.txt` defines `enable_testing()`, builds the `test_telemetry` executable linked against `telemetry_core`, and registers `add_test(NAME TelemetryBoundaryTests COMMAND test_telemetry)`.
4. **Automated Execution Loop:** Run `python3 .agents/skills/boundary-test-gen/scripts/run_tests.py` in the terminal tool. If compilation or assertions fail, inspect the output and fix the code or test until the script reports `ALL TESTS PASSED`.