#pragma once

#include QMK_KEYBOARD_H
#include "./layers/layers.h"

/// @brief Custom keycodes.
enum CustomKeycodes {
    WIN_SWAP = SAFE_RANGE, // custom alt-tabbing
    PH_P, // placeholder key that passes through to P when Ctrl is held
};

#define TD_CLS TD(TD_CAD_LOCK_SLEEP)
#define GAME TD(TD_GAMER_MODE)
#define COMPOSE KC_SCRL
// keys
#define CAD C(A(KC_DEL))
#define LAUNCH A(KC_SPC)
#define MENU S(KC_F10)
#define TAB_RIGHT C(KC_TAB)
#define TAB_LEFT (C(S(KC_TAB)))
#define ZOOM_IN C(KC_EQL)
#define ZOOM_OUT C(KC_MINS)

#define SFT_BSPC SFT_T(KC_BSPC)

// layers
#define SYM_ENT LT(_SYM, KC_ENT)
#define NAV_TAB LT(_NAV, KC_TAB)
#define NUM_SPC LT(_NUM, KC_SPC)
#define FN_LAUNCH LT(_FUNC, LAUNCH)
#define FN_ESC LT(_FUNC, KC_ESC)
#define ARROW MO(_SH_ARROW)

// trigger mods
#define OBLITERATE_TRIGGER_MODS MOD_MASK_GUI
