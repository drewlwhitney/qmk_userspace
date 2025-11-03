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

// weird tap holds
#define CW_CL SFT_T(CAPS_WORD)

// layers
#define NUM_SPC LT(_NUM, KC_SPC)
#define NAV_ENT LT(_NAV, KC_ENT)
#define FUNC_PLAY LT(_FUNC, KC_MPLY)

// trigger mods
#define TABBING_TRIGGER_MODS MOD_MASK_ALT
#define OBLITERATE_TRIGGER_MODS MOD_MASK_GUI

// home row mods
// base layer
#define GUI_A GUI_T(KC_A)
#define ALT_S GUI_T(KC_S)
#define SFT_D SFT_T(KC_D)
#define CTL_F CTL_T(KC_F)
#define CTL_G CTL_T(KC_G)

#define GUI_SCLN GUI_T(KC_SCLN)
#define ALT_L ALT_T(KC_L)
#define SFT_K RSFT_T(KC_K)
#define CTL_J CTL_T(KC_J)
#define CTL_H CTL_T(KC_H)

// nav layer
#define GUI_BSLS GUI_T(KC_BSLS)
#define ALT_LBRC ALT_T(KC_LBRC)
#define SFT_RBRC SFT_T(KC_RBRC)
#define CTL_MINS CTL_T(KC_MINS)

#define GUI_RGHT GUI_T(KC_RGHT)
#define ALT_UP ALT_T(KC_UP)
#define SFT_DOWN RSFT_T(KC_DOWN)
#define CTL_LEFT CTL_T(KC_LEFT)

// num layer
#define GUI_1 GUI_T(KC_1)
#define ALT_2 ALT_T(KC_2)
#define SFT_3 SFT_T(KC_3)
#define CTL_4 CTL_T(KC_4)

#define GUI_0 GUI_T(KC_0)
#define ALT_9 ALT_T(KC_9)
#define SFT_8 RSFT_T(KC_8)
#define CTL_7 CTL_T(KC_7)