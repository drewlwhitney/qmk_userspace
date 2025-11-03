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

    CAPS_WORD,
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

// trigger mods
#define TABBING_TRIGGER_MODS MOD_MASK_ALT
#define OBLITERATE_TRIGGER_MODS MOD_MASK_GUI

// home row mods
// base layer
#define ALT_A ALT_T(KC_A)
#define GUI_S GUI_T(KC_S)
#define CTL_D CTL_T(KC_D)
#define SFT_F SFT_T(KC_F)

#define ALT_SCLN ALT_T(KC_SCLN)
#define GUI_L GUI_T(KC_L)
#define CTL_K CTL_T(KC_K)
#define SFT_J RSFT_T(KC_J)

// nav layer
#define ALT_BSLS ALT_T(KC_BSLS)
#define GUI_LBRC GUI_T(KC_LBRC)
#define CTL_RBRC CTL_T(KC_RBRC)
#define SFT_MINS SFT_T(KC_MINS)

#define ALT_RGHT ALT_T(KC_RGHT)
#define GUI_UP GUI_T(KC_UP)
#define CTL_DOWN CTL_T(KC_DOWN)
#define SFT_LEFT RSFT_T(KC_LEFT)

// num layer
#define ALT_1 ALT_T(KC_1)
#define GUI_2 GUI_T(KC_2)
#define CTL_3 CTL_T(KC_3)
#define SFT_4 SFT_T(KC_4)

#define ALT_0 ALT_T(KC_0)
#define GUI_9 GUI_T(KC_9)
#define CTL_8 CTL_T(KC_8)
#define SFT_7 RSFT_T(KC_7)