#pragma once

#include QMK_KEYBOARD_H

enum {
    TD_CAD_LOCK_SLEEP,
    TD_GAMER_MODE,
};

void CAD_lock_sleep(tap_dance_state_t* state, void*);
void enter_gamer_mode(tap_dance_state_t* state, void*);