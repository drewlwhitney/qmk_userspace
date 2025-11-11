#pragma once

#include QMK_KEYBOARD_H
#include "./layers.h"

/// @brief Custom keycodes.
enum CustomKeycodes {
    DOWN = SAFE_RANGE,
    UP,

    LOW_6,
    LOW_7,
    LOW_8,
    LOW_9,
    LOW_0,

    MULT, // avoids a conflict with KC_ASTR
};

#define TD_CLS TD(TD_CAD_LOCK_SLEEP)
#define COMPOSE KC_SCRL
// keys
#define CAD C(A(KC_DEL))
#define LAUNCH A(KC_SPC)
#define MENU S(KC_F10)
#define TAB_RIGHT C(KC_TAB)
#define TAB_LEFT (C(S(KC_TAB)))

// layers
// #define NUM_SPC LT(_NUM, KC_SPC)
// #define NAV_ENT LT(_NAV, KC_ENT)
// #define FUNC_PLAY LT(_FUNC, KC_MPLY)

// #define NAV_SPC LT(_NAV, KC_SPC)
#define NUM_SPC LT(_NUM, KC_SPC)
#define NAV MO(_NAV)
#define NUM MO(_NUM)
#define SYM MO(_SYM)
#define LAUNCH_NUM LT(_SH_NUM, LAUNCH)
#define COMP_FUNC LT(_FUNC, COMPOSE)

// mod-taps (not homerow mods)
// #define GUI_LAUNCH GUI_T(LAUNCH)

// trigger mods
#define TABBING_TRIGGER_MODS MOD_MASK_ALT
#define OBLITERATE_TRIGGER_MODS MOD_MASK_GUI
