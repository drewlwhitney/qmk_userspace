#pragma once

#include QMK_KEYBOARD_H
#include "./layers/layers.h"

/// @brief Custom keycodes.
enum CustomKeycodes {
    WIN_SWAP = SAFE_RANGE, // custom alt-tabbing
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

// layers
#define NUM MO(_NUM)
#define SYM_BSPC LT(_SYM, KC_BSPC)
#define NAV_TAB LT(_NAV, KC_TAB)
#define FN_LAUNCH LT(_FUNC, LAUNCH)
#define FN_ESC LT(_FUNC, KC_ESC)
#define ARROW MO(_SH_ARROW)

// trigger mods
#define OBLITERATE_TRIGGER_MODS MOD_MASK_GUI
