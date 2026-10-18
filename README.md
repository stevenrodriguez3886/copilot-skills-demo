### GitHub Copilot & Agent Skills - Tool Summary


**Tool Information & Access**
* **Tool Name:** GitHub Copilot (featuring Agent Mode & Native `SKILL.md` Support)
* **Location & Access:** Built natively into **VS Code** and **Visual Studio** (no extension install required); also available via plugins for **JetBrains IDEs**, **Xcode**, and **Neovim**, on the web at **[github.com/features/copilot](https://www.google.com/search?q=https%3A%2F%2Fgithub.com%2Ffeatures%2Fcopilot)**, and in the terminal via **Copilot CLI**.
* **Zero-Config Skill Discovery:** Copilot automatically detects modular skill folders placed in `.agents/skills/<skill-name>/SKILL.md` (as well as `.github/skills/` and `~/.copilot/skills/`) out of the box with no workspace configuration required.


**Pricing & Availability**
* **Local Models / BYOK ($0/month):** **100% Free & Offline-Capable** by connecting the VS Code model picker to your own local LLM runtime (vLLM, LM Studio, Ollama, or any OpenAI-compatible local endpoint) with zero cloud token limits.
* **GitHub Copilot Free ($0/month):** Built-in cloud free tier featuring 2,000 inline completions/month and 50 monthly Agent Mode/Chat requests.
* **Students & Faculty ($0/month):** **100% Free access to Copilot Pro** via the verified GitHub Education / Student Developer Pack.
* **Paid Cloud Tiers:** **Pro** ($10/mo), **Pro+** ($39/mo), **Business** ($19/user/mo), and **Enterprise** ($39/user/mo) for hosted frontier models and organization-wide policy controls.


**Main Points & Features Demonstrated**
1. **Progressive Context Disclosure (`SKILL.md`):** Packaging domain workflows into YAML frontmatter (`name`, `description`), procedural Markdown, and bundled `scripts/`, `assets/`, or `references/` so Copilot loads heavy instructions only when triggered.
2. **Architectural Scaffolding Skill (`module-scaffolder`):** Enforcing strict project templates, fixed-width data types, and error-handling contracts during code generation.
3. **Automated Safety Audit & Test-Loop Skills (`safety-audit` & `boundary-test-gen`):** Grounding Copilot Agent Mode with reference checklists and terminal test-runner scripts to detect boundary bugs and verify fixes automatically.


**Engineering Verdict**
* **Value Add:** Skills transform Copilot from a generic autocomplete engine into a zero-config, repository-portable engineering harness that enforces architectural invariants across both cloud and local models.

>