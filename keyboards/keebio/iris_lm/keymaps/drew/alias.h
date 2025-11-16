#pragma once

#include QMK_KEYBOARD_H
#include "./layers/layers.h"

/// @brief Custom keycodes.
enum CustomKeycodes {
    WIN_SWAP, // custom alt-tabbing
    OSO_SHIFT, // makes thumb shift oneshot-only
    PH_P, // placeholder key that passes through to P when Ctrl is held
};

#define TD_CLS TD(TD_CAD_LOCK_SLEEP)
#define COMPOSE KC_SCRL
// keys
#define CAD C(A(KC_DEL))
#define LAUNCH A(KC_SPC)
#define MENU S(KC_F10)
#define TAB_RIGHT C(KC_TAB)
#define TAB_LEFT (C(S(KC_TAB)))
#define ZOOM_IN C(KC_EQL)
#define ZOOM_OUT C(KC_MINS)

// layers
#define SYM_ENT LT(_SYM, KC_ENT)
#define NAV_CANCEL LT(_NAV, KC_NO) // have to implement this functionality
#define NUM MO(_NUM)
#define GAME MO(_GAME)
#define LAUNCH_NUM LT(_SH_NUM, LAUNCH)
#define COMP_ARROW LT(_SH_ARROW, COMPOSE)

// trigger mods
#define TABBING_TRIGGER_MODS MOD_MASK_ALT
#define OBLITERATE_TRIGGER_MODS MOD_MASK_GUI
