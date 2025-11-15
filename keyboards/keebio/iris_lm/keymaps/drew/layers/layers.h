#pragma once

#include QMK_KEYBOARD_H
#include <stdbool.h>

enum {
    _BASE,
    _GAME,
    _SYM,
    _NAV,
    _NUM,
    _SH_NUM,
};

extern bool NUM_latched;

layer_state_t layer_state_set_user(layer_state_t state);
