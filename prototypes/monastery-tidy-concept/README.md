# Monastery Tidy — Concept Prototype (UE 5.7.4)

```
PROTOTYPE - NOT FOR PRODUCTION
Question: If the player drag-drops playful clutter onto home spots and watches
purity rise to a soft book reveal, do they feel relaxing hands-first flow?
Date: 2026-07-18
```

## Hypothesis

Players voluntarily tidy **≥4 props in ~3 minutes** without quitting, and name
**snap + meter tick** as the satisfying moment.

**Riskiest assumption tested first:** drag-drop / snap feel (not sticky / laggy).

## What you get

- Orthographic side-view room (auto-spawned — no level art needed)
- 5 colored cube props + matching ghost homes
- LMB drag → release near home → snap
- Purity meter (`thanh tinh`) + soft gold “TAM TANG” reveal at 100%

## How to run

1. Install **Unreal Engine 5.7.x** (you have 5.7.4).
2. Double-click `MonasteryTidyConcept.uproject`  
   - If prompted to rebuild modules → **Yes**.
   - First open may ask to generate Visual Studio project files → accept.
3. Wait for compile (C++).
4. Press **Play** (PIE).
5. **Left-click drag** colored cubes onto the matching ghost cubes in the row.

### If `.uproject` won't open

From PowerShell (adjust engine path if needed):

```powershell
& "C:\Program Files\Epic Games\UE_5.7\Engine\Binaries\DotNET\UnrealBuildTool\UnrealBuildTool.exe" -projectfiles -project="$PWD\MonasteryTidyConcept.uproject" -game -engine
```

Then open the generated `.sln`, build **Development Editor**, and open the `.uproject`.

## Explicitly cut

Menus, save, Paper Monastery art, 3 books, audio, packaging, architecture.

## After you play

Come back to the chat and report how it felt (hypothesis / best / worst / surprise / PROCEED|PIVOT|KILL).
