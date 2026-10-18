## Two-Presenter 8-Minute Video Runbook

### Presenter 1: Architecture, Discovery, & Module Scaffolding (0:00 - 4:00)

* **0:00 - 1:30 | Native Discovery & Progressive Disclosure**
* **What to Show:** Open VS Code. Show the file tree expanding `.agents/skills/`. Point out that GitHub Copilot now discovers skills out of the box with zero workspace settings required.
* **The Talking Point:** Explain the open **agentskills.io** standard. Mention that at startup, Copilot only reads the lightweight YAML frontmatter (`name` and `description`) from each skill folder. The full instruction body (`SKILL.md`) and bundled resources (`assets/`) are only pulled into the context window when a user prompt triggers them, saving tokens and keeping responses deterministic.


* **1:30 - 3:45 | Experiment 1: Architectural Scaffolding**
* **What to Show:** Open Copilot Chat in **Agent Mode**. Type the prompt to scaffold a new module:
> `Scaffold a new CrcValidator module that validates a raw telemetry frame buffer, verifies the 0xAA55 sync word, computes an XOR checksum over the payload bytes, and populates an output Packet struct.`


* **The Talking Point:** Point out the `Used skill: module-scaffolder` badge in the chat UI. Show how Copilot consulted `.agents/skills/module-scaffolder/assets/module_template.hpp`, enforced `noexcept` and `[[nodiscard]]`, avoided dynamic heap allocation, and registered the new file in `CMakeLists.txt`.


* **3:45 - 4:00 | Seamless Handoff**
* **Script:** *"Now that our validator module is successfully scaffolded with strict architectural invariants, I'll pass it over to [Partner Name] to show how Agent Skills handle safety audits and automated test-runner loops."*



---

### Presenter 2: Safety Audits, Automated Testing, & Summary (4:00 - 8:30)

* **4:00 - 6:15 | Experiment 2: Safety & Concurrency Audit**
* **What to Show:** Open `src/packet_processor.cpp` and issue the prompt in Agent Mode:
> `Run a safety and concurrency audit on src/packet_processor.cpp and apply the fixes.`


* **The Talking Point:** Watch Copilot trigger the `safety-audit` skill, read `.agents/skills/safety-audit/references/safety_checklist.md`, and output a structured Markdown vulnerability table covering `SAFE-01` through `SAFE-04`. Highlight the multi-file diff that adds the `std::mutex`, `nullptr` guards, wire-length bounds checks before `std::memcpy`, and divide-by-zero protection.


* **6:15 - 7:45 | Experiment 3: Automated Test Generation & Execution Loop**
* **What to Show:** In Agent Mode, invoke the test generator skill:
> `/boundary-test-gen Generate boundary unit tests for CrcValidator and PacketProcessor and verify them.`


* **The Talking Point:** Show Copilot creating `tests/test_telemetry.cpp`, updating CMake configuration, and automatically executing `.agents/skills/boundary-test-gen/scripts/run_tests.py` inside the integrated terminal until the runner prints `=== ALL TESTS PASSED ===`.


* **7:45 - 8:30 | 1-Page Summary Slide Walkthrough**
* **What to Show:** Switch to your final slide (displaying the 1-page summary text with native VS Code integration, zero-config discovery, and local model support).
* **The Talking Point:** Walk through tool access, student pricing, and how running skills locally via BYOK/Ollama/vLLM gives teams a completely offline, zero-cost engineering harness.