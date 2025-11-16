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
    _SH_ARROW,
};

extern bool NUM_latched;

