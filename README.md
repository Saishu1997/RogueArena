Memory & Ownership (The Foundation)  
## Game: Console Rogue Arena

A console-based arena combat prototype built to **master C++ memory management and ownership semantics**.  
The game intentionally keeps gameplay simple to enforce **correct object lifetimes, strict ownership rules, and RAII-based design**.

---

## 🎮 Game Overview

- Player enters a rogue-style arena
- Faces continuous enemy encounters
- Combat proceeds automatically in rounds
- The game ends when the player is defeated

This project focuses on **how objects are owned, created, destroyed, and transferred**, not on complex gameplay.

---

## 🧠 Core C++ Concepts Practiced

- `std::unique_ptr` ownership
- RAII (Resource Acquisition Is Initialization)
- Deterministic destruction
- Constructor / destructor flow
- Ownership transfer via `std::move`
- No shared ownership
- No memory leaks

---

## 🏗️ Architecture Highlights

### Entity System
- `Entity` (base class)
- `Player`
- `Enemy`

Entities:
- Own their own health and combat logic
- Are destroyed automatically when out of scope
- Never require manual deletion

---

### Item System
- `Item` (abstract base class)
- `WeaponItem`
- `ArmorItem`
- `PotionItem`

Items:
- Are heap-allocated and **exclusively owned**
- Transferred using `std::unique_ptr`
- Cleanly destroyed when dropped or consumed

---

## 🔒 Mandatory Constraints (Strictly Enforced)

- ✅ All heap objects owned via `std::unique_ptr`
- ✅ No raw `new` / `delete`
- ✅ No shared ownership (`shared_ptr` forbidden)
- ✅ No memory leaks
- ✅ No dangling references
- ✅ Clear ownership boundaries

---

## 🧪 Skill Check

> **At no point should the programmer need to manually manage memory.**

If an object goes out of scope, it is destroyed **automatically and safely**.

---

## ▶️ How to Run

### Windows (Prebuilt)
1. Download `RogueArena.exe` from Releases
2. Run from terminal or double-click

### Build from Source
- Open `RogueArena.sln` in Visual Studio
- Build (x64 / Debug or Release)
- Run the executable

---

## 📌 Example Output

