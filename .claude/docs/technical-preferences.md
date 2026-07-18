# Technical Preferences

<!-- Populated by /setup-engine. Updated as the user makes decisions throughout development. -->
<!-- All agents reference this file for project-specific standards and conventions. -->

## Engine & Language

- **Engine**: Unreal Engine 5.7.4
- **Language**: C++ (primary), Blueprint (gameplay prototyping)
- **Rendering**: Unlit / emissive paper-cut materials for jam MVP; Lumen/Nanite/Chaos off unless explicitly approved
- **Physics**: Disabled for MVP — kinematic drag-drop only (no Chaos simulation)

## Input & Platform

<!-- Written by /setup-engine. Read by /ux-design, /ux-review, /test-setup, /team-ui, and /dev-story -->
<!-- to scope interaction specs, test helpers, and implementation to the correct input methods. -->

- **Target Platforms**: PC (Steam / Epic)
- **Input Methods**: Keyboard/Mouse
- **Primary Input**: Keyboard/Mouse
- **Gamepad Support**: Partial (recommended)
- **Touch Support**: None
- **Platform Notes**: Orthographic 2.5D cutaway; mouse pick/drag is the core verb. Hover highlights are OK on PC. Gamepad optional later — not required for jam MVP.

## Naming Conventions

- **Classes**: Prefixed PascalCase (`A` Actor, `U` UObject, `F` struct) — e.g., `ATidyProp`, `UPurityMeterComponent`
- **Variables**: PascalCase (e.g., `MoveSpeed`, `HomeOverlap`)
- **Signals/Events**: PascalCase delegates / dynamic multicast (e.g., `OnPurityChanged`, `OnSutraRevealed`)
- **Files**: Match class without prefix (e.g., `TidyProp.h`, `PurityMeterComponent.cpp`)
- **Scenes/Prefabs**: PascalCase maps / Blueprints (e.g., `MonasteryRoom`, `BP_TidyProp`)
- **Constants**: PascalCase or `b` prefix for booleans (e.g., `MaxProps`, `bIsHome`)

## Performance Budgets

- **Target Framerate**: 60 fps
- **Frame Budget**: 16.6 ms
- **Draw Calls**: ~2000 (PC stylized 2.5D soft ceiling)
- **Memory Ceiling**: ~2 GB soft (jam / mid-range PC)

## Testing

- **Framework**: Unreal Automation Framework / Spec (`FAutomationSpecBase`)
- **Minimum Coverage**: Core tidy loop (grab/place/home), purity score math, reveal threshold triggers
- **Required Tests**: Balance formulas (if any), gameplay systems (purity/home-count), networking (N/A — single-player)

## Forbidden Patterns

<!-- Add patterns that should never appear in this project's codebase -->
- [None configured yet — add as architectural decisions are made]

## Allowed Libraries / Addons

<!-- Add approved third-party dependencies here -->
- [None configured yet — add as dependencies are approved]

## Architecture Decisions Log

<!-- Quick reference linking to full ADRs in docs/architecture/ -->
- [No ADRs yet — use /architecture-decision to create one]

## Engine Specialists

<!-- Written by /setup-engine when engine is configured. -->
<!-- Read by /code-review, /architecture-decision, /architecture-review, and team skills -->
<!-- to know which specialist to spawn for engine-specific validation. -->

- **Primary**: unreal-specialist
- **Language/Code Specialist**: ue-blueprint-specialist (Blueprint graphs) or unreal-specialist (C++)
- **Shader Specialist**: unreal-specialist (no dedicated shader specialist — primary covers materials)
- **UI Specialist**: ue-umg-specialist (UMG widgets, CommonUI, input routing, widget styling)
- **Additional Specialists**: ue-gas-specialist (Gameplay Ability System — unlikely for this jam), ue-replication-specialist (netcode — N/A single-player)
- **Routing Notes**: Invoke primary for C++ architecture and broad engine decisions. Invoke Blueprint specialist for Blueprint graph architecture and BP/C++ boundary design. Invoke UMG specialist for all UI (purity meter, reveals). Skip GAS/replication unless scope expands.

### File Extension Routing

<!-- Skills use this table to select the right specialist per file type. -->
<!-- If a row says [TO BE CONFIGURED], fall back to Primary for that file type. -->

| File Extension / Type | Specialist to Spawn |
|-----------------------|---------------------|
| Game code (.cpp, .h files) | unreal-specialist |
| Shader / material files (.usf, .ush, Material assets) | unreal-specialist |
| UI / screen files (.umg, UMG Widget Blueprints) | ue-umg-specialist |
| Scene / prefab / level files (.umap, .uasset) | unreal-specialist |
| Native extension / plugin files (Plugin .uplugin, modules) | unreal-specialist |
| Blueprint graphs (.uasset BP classes) | ue-blueprint-specialist |
| General architecture review | unreal-specialist |
