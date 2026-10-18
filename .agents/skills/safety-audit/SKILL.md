---
name: safety-audit
description: Performs a static safety, memory-bounds, and concurrency audit on C++ source files. Use when asked to review, audit, or fix bugs in existing source files.
---
# Safety & Concurrency Audit Skill

Follow this exact procedure when auditing or fixing C++ source files:

1. **Load the Checklist:** Read `.agents/skills/safety-audit/references/safety_checklist.md` to load the required verification rules (Rules `SAFE-01` through `SAFE-04`).
2. **Produce an Audit Report Table:** Before editing any code, output a Markdown table in Chat with columns: `Rule ID`, `Line(s)`, `Vulnerability Description`, and `Planned Fix`.
3. **Apply Remediation Diffs:**
   - Add `std::mutex` and `std::lock_guard<std::mutex>` to protect shared class state.
   - Validate all pointer inputs against `nullptr` and return `Status::ERR_NULL_PTR`.
   - Validate all buffer lengths against both `kMaxPayloadBytes` and the caller's `total_len` before any `std::memcpy` or index read, returning `Status::ERR_BOUNDS` on violation.
   - Guard all division operations against zero denominators.