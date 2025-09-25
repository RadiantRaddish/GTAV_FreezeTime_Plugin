# GTA V - Time Freeze Mod (ASI Plugin)

Freeze and unfreeze time in Grand Theft Auto V with a single key press!

---

## Features

- Freeze and unfreeze the in-game clock (toggle with `F5`)
- Optionally freeze all nearby pedestrians and vehicles
- ASI mod built using ScriptHookV SDK (C++)

---

## Building from Source

### Prerequisites

- Visual Studio with C++ Desktop tools
- ScriptHookV SDK (download and extract to a known location)

### Steps

1. Clone this repository.
2. Open `TimeFreeze.sln` in Visual Studio.
3. Set build configuration to **Release | x64**.
4. Make sure the ScriptHookV SDK paths are set in:
   - **Project Properties > VC++ Directories**:
     - Include Directories
     - Library Directories
   - **Linker > Input > Additional Dependencies**:
     - Add `ScriptHookV.lib`
5. Build the solution. Output: `TimeFreeze.asi`

---

## License

This mod is open-source. You are free to modify or redistribute it under the [MIT License](LICENSE).

---

## Credits

- **ScriptHookV** by Alexander Blade
- Developed by OSNEP
