---
name: boundary-test-gen
description: Generates boundary-condition unit tests and executes the automated verification script. Use when asked to write tests, verify edge cases, or run the test suite.
---
# Boundary Test Generation & Verification Loop

When generating unit tests for any module in this repository, you MUST follow these strict engineering constraints:

1. **Read-Only Implementation Files:** Treat all files in `src/` and `include/` as **strictly read-only**. You are **forbidden** from modifying implementation source or header files to make unit tests pass. Your job is to test the existing implementation as-is.
2. **Create Deterministic Test File:** Create or update `tests/test_telemetry.cpp` using standard `<cassert>` and `<iostream>` (zero external test framework dependencies).
3. **Mandatory Test Vectors:** You must include explicit test functions covering:
   - Nominal valid packet (valid `0xAA55` sync word, valid XOR checksum, within bounds).
   - Null pointer input (`Status::ERR_NULL_PTR`).
   - Truncated buffer / payload length exceeding `kMaxPayloadBytes` (`Status::ERR_BOUNDS`).
   - Corrupted sync word (`Status::ERR_INVALID_SYNC`) and corrupted checksum (`Status::ERR_CHECKSUM`).
4. **Update Build Config:** Ensure `CMakeLists.txt` defines `enable_testing()`, builds the `test_telemetry` executable linked against `telemetry_core`, and registers `add_test(NAME TelemetryBoundaryTests COMMAND test_telemetry)`.
5. **Automated Execution Loop:** Run `python3 .agents/skills/boundary-test-gen/scripts/run_tests.py` in the terminal tool. If assertions fail due to a bug in the source code, do not alter the source code; report the failure so the implementation can be addressed separately via the safety-audit workflow.