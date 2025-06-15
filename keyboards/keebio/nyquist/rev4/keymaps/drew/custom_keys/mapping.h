#pragma once
#include QMK_KEYBOARD_H
#include "../common.h"
#include "../layers.h"
#include "../utils/deletion.h"
#include "alias.h"
#include "custom_keys.h"

// -------------------------------------------------------------------------------------------------

// -------------------------------------------------------------------------------------------------

// clang-format off
// NK stands for "new key"
enum custom_keycodes {
    // _BASE layer
    NK_Q,
    // _NUM layer
    NK_COLN,
    NK_MINS_NUM,
    NK_1,
    NK_2,
    NK_3,
    NK_4,
    NK_5,
    NK_6,
    NK_7,
    NK_8,
    NK_9,
    NK_0,
    NK_6_LOW,
    NK_7_LOW,
    NK_8_LOW,
    NK_9_LOW,
    NK_0_LOW,
    // _NAV layer
    NK_BSLS, // backslash
    NK_LBRC, // [
    NK_RBRC, // ]
    NK_MINS_NAV, // -
    NK_EQL, // =
    NK_GRV, // `
    NK_PIPE,
    NK_LCBR,
    NK_RCBR,
    NK_UNDS,
    NK_PLUS,
    NK_F2,
    NK_DLR,
    NK_HOME,
    NK_END,

    // multiple layers
    NK_CIRC,
    NK_AMPR,
    NK_ASTR,
    NK_RPRN,
    NK_ESC,
    NK_UP,
    NK_DOWN,
    NK_BSPC,

    // tap-hold
        // default function
        TH_LAUNCH,
        // default keycode
        TH_DEL,
        TH_RALT,
        TH_TILD,
        TH_LSFT,
        TH_COMM,
        TH_COLN,
        TH_SPC,

    // this is always last
    NK_LAST,
};
// clang-format on

// -------------------------------------------------------------------------------------------------

extern custom_key_t custom_keys[];

// -------------------------------------------------------------------------------------------------
