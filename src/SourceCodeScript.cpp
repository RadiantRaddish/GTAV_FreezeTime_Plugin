#include "script.h"
#include "keyboard.h"

bool timeFrozen = false;
int frozenTime = 0;

void ToggleTimeFreeze() {
    if (!timeFrozen) {
        // Get current in-game time
        int hour, minute, second;
        TIME::GET_CLOCK_TIME(&hour, &minute, &second);
        frozenTime = hour * 60 + minute;

        // Freeze time and entities
        TIME::PAUSE_CLOCK(true);
        FreezeWorldEntities(true);

        UI::PRINT_TO_SCREEN("Time and world frozen.");
    } else {
        // Unfreeze time and entities
        TIME::PAUSE_CLOCK(false);
        FreezeWorldEntities(false);

        UI::PRINT_TO_SCREEN("Time and world resumed.");
    }

    timeFrozen = !timeFrozen;
}

void FreezeWorldEntities(bool freeze) {
    for (int i = 0; i < 256; ++i) {
        Ped ped = PED::GET_PED_NEARBY_PEDS(PLAYER::PLAYER_PED_ID(), i);
        if (ENTITY::DOES_ENTITY_EXIST(ped) && !PED::IS_PED_A_PLAYER(ped)) {
            ENTITY::FREEZE_ENTITY_POSITION(ped, freeze);
        }
    }

    for (int i = 0; i < 256; ++i) {
        Vehicle veh = VEHICLE::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), true);
        if (ENTITY::DOES_ENTITY_EXIST(veh)) {
            ENTITY::FREEZE_ENTITY_POSITION(veh, freeze);
        }
    }
}

void main() {
    while (true) {
        WAIT(0);

        // Press F5 to toggle time freeze
        if (IsKeyJustUp(VK_F5)) {
            ToggleTimeFreeze();
        }

        if (timeFrozen) {
            int hour = frozenTime / 60;
            int minute = frozenTime % 60;
            TIME::SET_CLOCK_TIME(hour, minute, 0);
        }
    }
}

void ScriptMain() {
    main();
}
