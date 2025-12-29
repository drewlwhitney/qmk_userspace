#pragma once

#include QMK_KEYBOARD_H
#include <stdbool.h>

enum {
    _BASE,
    _GAME,
    _SH_ARROW,
    _SYM,
    _NAV,
    _NUM,
    _FUNC,
};

extern bool NUM_latched;