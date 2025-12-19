# Virtual World Simulator

A turn-based life simulation project implemented in C++, featuring a 2D grid world () populated by various animals and plants with unique behaviors.

## Project Overview

The simulator models an ecosystem where organisms interact based on their **strength**, **initiative**, and **age**. The world is rendered in the console using ASCII characters, and the simulation progresses turn-by-turn.

### Key Mechanics:

* **Turn-based System**: All organisms perform actions once per turn.
* **Turn Priority**: Determined by **Initiative** (highest first). If initiatives are equal, the **Age** of the organism (seniority) decides.
* **Collision System**:
* If a move results in two organisms on the same tile, a fight occurs.
* The stronger organism typically wins. If strengths are equal, the attacker wins.
* Special behaviors: Some organisms can repel attacks or kill the aggressor regardless of strength.


* **Human Player**: Unlike AI organisms, the Human is controlled via arrow keys and possesses a **Special Ability** (active for 5 turns, 5-turn cooldown).
* **Reproduction**: Animals can breed, and plants can spread to adjacent empty tiles.
* **Persistence**: Features a Save/Load system to store the state of the world in a file.

##  Organisms

| Type | Symbol | Behavior |
| --- | --- | --- |
| **Human** | `H` | Controlled by player; uses special abilities. |
| **Wolf** | `W` | High strength; aggressive predator. |
| **Sheep** | `S` | Standard herbivore. |
| **Turtle** | `T` | High defense; reflects attacks from weak organisms. |
| **Grass** | `g` | Standard plant; spreads slowly. |
| **Guarana** | `G` | Increases the strength of the animal that eats it. |

---

##  Controls & UI

* **Arrow Keys**: Move Human.
* **Special Key**: Activate Human's unique ability.
* **Enter/Any Key**: Proceed to the next turn.
* **Event Log**: A dedicated section of the console displays fight results, deaths, and special events.

##  How to Run

1. Compile the source code using your preferred compiler (e.g., `g++`).
2. Run the executable.
3. Set the grid dimensions () when prompted.
