#pragma once

#include QMK_KEYBOARD_H

enum {
    TD_CAD_LOCK_SLEEP,
};

void CAD_lock_sleep(tap_dance_state_t* state, void*);