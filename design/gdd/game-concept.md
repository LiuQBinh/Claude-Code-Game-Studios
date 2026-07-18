# Game Concept: Monastery Tidy

*Created: 2026-07-18*
*Updated: 2026-07-18 — hub 2.5D + tidy mini-games (vision C); timeline flexible*
*Status: Draft*

> **Creative Director Review (CD-PILLARS)**: CONCERNS → revised pillars accepted 2026-07-18
> **Art Director Review (AD-CONCEPT-VISUAL)**: CONCEPTS — Visual Identity Anchor **Paper Monastery** selected 2026-07-18
> **Technical Director Review (TD-FEASIBILITY)**: CONCERNS (accepted) 2026-07-18
> **Producer Review (PR-SCOPE)**: OPTIMISTIC → adjusted scope accepted 2026-07-18; **scope revised** to hub+minigame (player) 2026-07-18

---

## Elevator Pitch

> It's a cozy 2.5D cutaway monastery game where you walk a small caretaker through layered rooms (like “phá nhà hàng xóm,” but restore — not wreck). Step into a messy room to play a tidy mini-game; each room you calm reveals one Tripitaka (Tam Tạng) volume — find all three.
>
> Test: In ten seconds — walk to a door, tidy clutter home, watch a book appear, return to the house.

---

## Core Identity

| Aspect | Detail |
| ---- | ---- |
| **Genre** | 2.5D cutaway adventure hub + cozy tidy mini-games (pilgrimage fantasy) |
| **Platform** | PC (Steam / Epic) |
| **Target Audience** | Casual–midcore players who like Unpacking / A Little to the Left + light exploration; Creators & order-seekers |
| **Player Count** | Single-player |
| **Session Length** | ~20–45 minutes full vision (3 rooms); shorter if fewer rooms shipped |
| **Monetization** | Premium (none yet) |
| **Estimated Scope** | Medium (Full Vision ~4–10 weeks solo; timeline flexible). Prototype-first before locking ship date. |
| **Comparable Titles** | Unpacking / A Little to the Left (tidy), 2.5D “phá nhà hàng xóm” cutaways (space), light hub games (walk → activity) |

---

## Structure (Hub + Mini-game)

**Layer A — Overworld (2.5D cutaway)**  
Player controls a small caretaker walking left/right through a paper-cut monastery cross-section. Rooms read as layered house slices. Approach a door / room marker → press interact → enter mini-game.

**Layer B — Tidy mini-game**  
Drag-drop playful clutter to home spots; purity (thanh tịnh) meter rises; at 100% for that room, one Tam Tạng volume fades in softly → return to overworld with room marked calm.

**Win condition (full vision):** Calm 3 rooms → collect all 3 Tripitaka volumes.

---

## Core Fantasy

"I walk a living cutaway home, make each room peaceful with my hands, and that peace reveals the sacred."

The player is a gentle caretaker. The house is lovable and slightly funny when messy — never grim. Walking the 2.5D am creates place and pilgrimage; tidying is the intimate act that lets each sutra appear.

---

## Unique Hook

Like Unpacking / tidy games, **AND ALSO** a walkable 2.5D house-cutaway in the DNA of Vietnamese “phá nhà hàng xóm” games — **inverted** from destruction into restoration — where finding the Three Tam Tạng is paced by **entering rooms to tidy them**, not by combat or fetch quests alone.

---

## Visual Identity Anchor

**Selected direction:** Paper Monastery (Art Director recommend)

**One-line visual rule:** *Flat cuts of colored paper, layered to reveal depth — every layer you restore is one closer to the light.*

**Supporting visual principles:**

1. **Silhouette-first props** — Every interactive object must read as pure shape before detail. *Design test:* If an object needs texture detail to be understood → simplify the silhouette.
2. **Color = game state** — Cluttered rooms lean warm terracotta/saffron; tidied space expands cream/light. *Design test:* If a tidy moment does not visually “brighten” the space → the state change is too weak.
3. **Sacred gold is reserved** — Gold appears only on Tripitaka books and the blessing meter fill. *Design test:* If gold appears on ambient clutter or UI chrome → remove it.

**Color philosophy summary:** Strict 5-color folk palette — terracotta `#C1440E`, saffron `#E8A827`, cream `#F0E6D3`, forest green `#3D6B4F`, deep brown `#4A3728` (no pure black) — plus sacred gold `#FFD700` reserved for books and meter. Mood: festive, accessible, Tết paper-cut / folk craft — playful without mocking the sacred.

This section seeds `/art-bible`.

---

## Player Experience Analysis (MDA Framework)

### Target Aesthetics (What the player FEELS)

| Aesthetic | Priority | How We Deliver It |
| ---- | ---- | ---- |
| **Sensation** (sensory pleasure) | 2 | Soft snap, playful clutter motion, cream expansion, gold reveal |
| **Fantasy** (make-believe, role-playing) | 3 | Caretaker of a tiny monastery; peace reveals the sacred |
| **Narrative** (drama, story arc) | 6 | Light staging only; story through space and reveals, not text walls |
| **Challenge** (obstacle course, mastery) | 7 | Minimal — optional spatial puzzle feel, no fail states |
| **Fellowship** (social connection) | N/A | Single-player jam |
| **Discovery** (exploration, secrets) | 4 | Finding sutras as thresholds of calm; reading the cutaway |
| **Expression** (self-expression, creativity) | 5 | Order of tidying; light placement freedom within homes |
| **Submission** (relaxation, comfort zone) | 1 | Primary target: Relaxation & Flow — low stress, rhythmic tidy |

### Key Dynamics (Emergent player behaviors)

- Players walk the cutaway, peek into messy rooms, then “go in” to tidy.
- Players smile at the mess before fixing it, then chase the next purity bump.
- Players return to the hub proud of a calmer room and hunt the next door for the next sutra.

### Core Mechanics (Systems we build)

1. **2.5D hub locomotion** — Side-view cutaway; walk left/right; interact at room doors.
2. **Room → tidy mini-game transition** — Enter/exit without combat or fail states.
3. **Kinematic drag-drop tidy** — Pick prop → snap to home (purity = home-count only).
4. **Per-room blessing** — Room at 100% purity → one Tam Tạng volume fades in; track 3 books.
5. **Playful clutter staging** — Endearing chaos props; Paper Monastery silhouette read.

---

## Player Motivation Profile

### Primary Psychological Needs Served

| Need | How This Game Satisfies It | Strength |
| ---- | ---- | ---- |
| **Autonomy** (freedom, meaningful choice) | Choose which cluster to tidy first; no fail / no forced order | Core |
| **Competence** (mastery, skill growth) | Visible meter + clear “home” snaps; skill is spatial clarity, not twitch | Supporting |
| **Relatedness** (connection, belonging) | Bond with the monastery and the sacred goal (world answers care) | Supporting |

### Player Type Appeal (Bartle Taxonomy)

- [x] **Achievers** (goal completion, collection, progression) — How: complete purity → collect 3 sutras (full vision)
- [x] **Explorers** (discovery, understanding systems, finding secrets) — How: read the cutaway; discover books via calm
- [ ] **Socializers** (relationships, cooperation, community) — How: N/A for jam
- [ ] **Killers/Competitors** (domination, PvP, leaderboards) — How: explicitly not for this audience

**Primary (Quantic Foundry lens):** Creators / order-seekers (Completion + Design).  
**Not for:** Competitive LoL-style players, hardcore achiever grinders, multiplayer socializers.

### Flow State Design

- **Onboarding curve**: First minute — one highlighted prop, drag to ghost home, meter ticks; no tutorial walls.
- **Difficulty scaling**: More props / denser clutter in full vision; jam stays easy.
- **Feedback clarity**: Hover outline, ghost home, meter fill, cream brightness; gold only on sacred payoff.
- **Recovery from failure**: No fail states — misplace freely; purity only rises when homes are filled.

---

## Core Loop

### Moment-to-Moment (30 seconds)

**Hub:** Walk toward a door / room slice.  
**Mini-game:** Grab a playfully misplaced object → drag → snap home → purity nudges.

### Short-Term (5–15 minutes)

Enter one messy room → tidy to 100% → soft sutra reveal → return to hub with room calmed.

### Session-Level (30–120 minutes)

Explore cutaway monastery → clear 2–3 rooms via mini-games → collect all three Tam Tạng → am feels whole.

### Long-Term Progression

Done when 3 volumes are revealed. Timeline flexible (prototype first). Later: denser clutter, audio, store path.

### Retention Hooks

- **Curiosity**: What’s in the next room? Which book appears next?
- **Investment**: Half-calm monastery you want to finish
- **Social**: Minimal
- **Mastery**: Spatial tidy clarity; optional harder room layouts later

---

## Game Pillars

### Pillar 1: Playful Clutter

The player should smile at the mess before they feel the urge to fix it — clutter reads as endearing chaos (a toppled stack of scrolls, a robe draped on a gong), never grime or damage.

*Design test:* If choosing “scary / solemn sacred gloom” vs “lovable mess” → choose lovable mess.

### Pillar 2: Peace Reveals the Sacred

The sacred appears as a consequence of peace, never as a prize for a checklist — sutras fade in when the space feels still (meter as calm proxy), not as loud task-complete fanfare.

*Design test:* If a reveal feels like a slot-machine reward bomb vs a quiet blessing → choose quiet blessing.

### Pillar 3: Hands-First Flow

Primary joy is hands-on: walking the cutaway to choose a room, then drag / drop / arrange inside it. Lore and menus must not break the rhythm. **Carve-out:** sutra reveals and short hub walks are payoffs / framing of hand play — not replacements for it.

*Design test:* If a system adds less hand interaction than it costs in UI → cut it.

### Pillar 4: One Sacred Goal

Everything serves finding the three Tam Tạng volumes — via hub rooms that each unlock one book through a tidy mini-game.

*Design test:* If a feature does not lead to a room tidy or a sutra reveal → do not build it in the current milestone.

### Pillar 5: Reverent Play

The tone is affectionate, never mocking. We play with everyday monastery clutter and daily life; we never make a punchline of the sacred (Buddha images, the sutras, the act of blessing).

*Design test:* If a gag lands its humor on the sacred object itself → cut it; if humor lands on everyday clutter around it → keep it.

### Anti-Pillars (What This Game Is NOT)

- **NOT combat / stealth / die-reload**: Would destroy Relaxation & Flow.
- **NOT deep colony sim (ONI-like)**: Would bury hands-first tidy under systems.
- **NOT violent destruction / demolish sim**: Playful mess ≠ wrecking for spectacle.
- **NOT open world / many maps**: One cutaway monastery with a handful of rooms — not a big map.
- **NOT combat platformer**: Walk + interact only; no jumps-as-challenge, no enemies.
- **NOT fail states / reward bombs**: Soft blessing only.
- **NOT mockery of the sacred**: Protects Reverent Play and cultural respect.
- **NOT store submission before a playable packaged build exists**: .exe first; Coming Soon optional.

---

## Inspiration and References

| Reference | What We Take From It | What We Do Differently | Why It Matters |
| ---- | ---- | ---- | ---- |
| Unpacking | Satisfying place-object fantasy, calm pace | Sacred goal + purity thresholds + cutaway set | Validates cozy tidy as a genre |
| A Little to the Left | Order-seeking, gentle spatial puzzles | Less strict “one true solution”; playful mess first | Order-seeker audience |
| 2.5D “phá nhà hàng xóm” cutaways | Layered house readability, toy-like space | Invert wreck → tidy; reverence guardrails | Visual/spatial DNA the player asked for |
| Vietnamese folk / Tết paper art | Flat layered craft, festive readability | Applied to monastery caretaker fantasy | Paper Monastery identity |

**Non-game inspirations**: Quiet temple courtyards; paper cuttings and folk craft; the cultural resonance of the Tripitaka as a pilgrimage of care rather than conquest.

---

## Target Player Profile

| Attribute | Detail |
| ---- | ---- |
| **Age range** | ~16–40 |
| **Gaming experience** | Casual to mid-core |
| **Time availability** | One sitting (20–40 min jam); short weeknight sessions later |
| **Platform preference** | PC |
| **Current games they play** | Unpacking, A Little to the Left, cozy / tidy / light puzzle |
| **What they're looking for** | Low-stress flow with a clear, meaningful finish |
| **What would turn them away** | Fail states, combat, irreverent jokes about Buddhism, noisy reward spam |

**Creative brief note:** The designer’s own play taste includes Oxygen Not Included, Civ 6, and LoL, but the *product* intentionally targets Relaxation & Flow, not those genres’ intensity.

---

## Technical Considerations

| Consideration | Assessment |
| ---- | ---- |
| **Recommended Engine** | **Unreal Engine 5** (user preference — locked). Use smallest slice: Blank/Blueprint template; orthographic camera; kinematic drag-drop; unlit/emissive paper materials; no Lumen/Nanite/Chaos for jam. |
| **Key Technical Challenges** | UE5 overhead for a first game; 2.5D character + camera; hub↔minigame flow; orthographic drag-drop; packaging |
| **Art Style** | 2.5D paper-cut folk (Paper Monastery) |
| **Art Pipeline Complexity** | Low–Medium (flat textured planes / cutouts, 5-color discipline) |
| **Audio Needs** | Minimal–Moderate (soft place sounds, ambient; blessing sting soft) |
| **Networking** | None |
| **Content Volume** | Full vision: 1 cutaway monastery, 3 rooms, 3 tidy mini-games, 3 sutras. Shipable demos may be 1 room first. |
| **Procedural Systems** | None |

---

## Risks and Open Questions

### Design Risks

- Playful mess vs reverence — jokes that accidentally mock the sacred (mitigated by Reverent Play).
- Meter-as-checklist feeling vs “peace reveals sacred” fantasy (mitigated by soft reveals + Peace Reveals the Sacred pillar).
- Core tidy feel may be weak if snap/ghost feedback is unclear.

### Technical Risks

- UE5 + first game + 7 days (TD: CONCERNS) — editor/cook/package overhead.
- Drag-drop under orthographic camera for a beginner.
- Packaging left until late → editor-only “build” (PR: pull packaging to Day 1).

### Market Risks

- Cozy tidy niche is small but proven; differentiation relies on cutaway + Tam Tạng hook.
- Cultural sensitivity if marketing or art mishandles Buddhist imagery.

### Scope Risks

- Expanding to 3 reveals / 12+ props before packaged core loop exists.
- Attempting Steam/Epic submission inside the jam week.
- Feature creep into sim-like cleanliness rules.

### Open Questions

- Exact home-volume authoring workflow in UE5 for 4–6 props — answer via Day 1–2 drag-drop spike.
- Whether 33/66 reveals fit after Day 5 feature freeze — only if core loop is packaged early.
- Post-jam: Steam page → submission timeline after playable .exe exists.

---

## MVP Definition

**Core hypothesis:** Players enjoy walking a 2.5D cutaway monastery, entering a room to tidy, and feeling that each calm room rightly reveals a Tam Tạng volume — enough to want the next door.

**Required for visualization prototype (HTML — now):**
1. Walkable hub (left/right) with 3 room doors.
2. Enter door → tidy mini-game → 100% → one book → return to hub.
3. Track 3 books; win when all three rooms done.

**Required for first UE vertical (when timeline allows):**
1. Packaged .exe path proven early.
2. Same hub + minigame loop with Paper Monastery placeholders.
3. Purity = home-count only; soft reveals; no combat.

**Explicitly NOT in first demo:**
- Combat, fail states, deep sim, store submission, full art bible polish

### Scope Tiers (timeline flexible — cut gracefully)

| Tier | Content | Features | Notes |
| ---- | ---- | ---- | ---- |
| **A — Feel demo** | HTML or thin UE | Hub walk + 1 door + 1 tidy + 1 book | Prove fantasy today |
| **B — Thin vertical** | 1 cutaway + character | 1–2 rooms, tidy minigames, 1–2 books | Shipable slice |
| **C — Full vision** | Multi-room cutaway | 3 rooms, 3 minigames, 3 books, Paper Monastery art | ~4–10 weeks solo estimate |
| **Post** | Polish | Audio, Coming Soon / store path | After C playable |

---

## Next Steps

- [ ] Run `/setup-engine` to configure Unreal Engine 5 and populate version-aware reference docs
- [ ] Run `/art-bible` to expand the Paper Monastery Visual Identity Anchor (required before Technical Setup gate)
- [ ] Use `/design-review design/gdd/game-concept.md` to validate concept completeness
- [ ] **Prototype core idea** (`/prototype tidy-drag-drop` or similar) — validate hands-first loop before heavy GDD work (recommended Path B for unproven feel)
- [ ] If prototype PROCEEDS: `/map-systems` → `/design-system` per MVP system
- [ ] `/create-architecture` → `/architecture-decision (×N)` → `/architecture-review`
- [ ] `/gate-check` before Pre-Production / Production commitment
- [ ] Build `/vertical-slice` when design+architecture are ready
- [ ] `/playtest-report` after vertical slice sessions
- [ ] `/sprint-plan` once stories exist

---

## Recommended Pipeline After Concept

**Path B — Prototype-First** (recommended here: core tidy feel + UE5 first-game risk):

1. `/setup-engine`
2. `/prototype` — 1–3 day throwaway validating drag → home → meter → reveal
3. If PROCEEDS: `/art-bible`, then `/map-systems` → `/design-system` → architecture path
4. If PIVOTS: return to `/brainstorm` with learnings
5. Later: `/vertical-slice` before sprint commitment

**Path A — Design-First** (if you skip prototype): `/setup-engine` → `/art-bible` → `/design-review` → `/map-systems` → `/design-system` → `/create-architecture` → ADRs → `/architecture-review` → `/gate-check`
