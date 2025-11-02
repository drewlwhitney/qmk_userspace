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

// keys
#define CAD C(A(KC_DEL))
#define LOCK G(KC_L)
#define LAUNCH A(KC_SPC)
#define MENU S(KC_F10)
#define TAB_FORWARD C(KC_TAB)
#define TAB_BACKWARD (C(S(KC_TAB)))

// layers
#define NUM_SPC LT(_NUM, KC_SPC)
#define NAV_ENT LT(_NAV, KC_ENT)
#define FUNC_PLAY LT(_FUNC, KC_MPLY)

// mod-tap
// 8-bit tap key
#define SFT_DEL RSFT_T(KC_DEL)
#define L_SFT SFT_T(KC_LSFT)
#define SFT_COMM SFT_T(KC_COMM)
#define ALT_COMP ALT_T(KC_RALT)
// 16-bit tap key
#define SFT_TILD SFT_T(KC_TILD)
#define CTL_COLN CTL_T(KC_COLN)
#define GUI_LAUNCH GUI_T(LAUNCH)

// trigger mods
#define TABBING_TRIGGER_MODS MOD_MASK_ALT
#define OBLITERATE_TRIGGER_MODS MOD_MASK_GUI
