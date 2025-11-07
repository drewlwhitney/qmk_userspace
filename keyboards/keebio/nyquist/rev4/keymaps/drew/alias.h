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

// mod-taps (not homerow mods)
#define GUI_LAUNCH GUI_T(LAUNCH)

// trigger mods
#define TABBING_TRIGGER_MODS MOD_MASK_ALT
#define OBLITERATE_TRIGGER_MODS MOD_MASK_GUI

// home row mods
// base layer
#define GUI_A GUI_T(KC_A)
#define ALT_S ALT_T(KC_S)
#define CTL_D CTL_T(KC_D)
#define SFT_F SFT_T(KC_F)

#define GUI_SCLN RGUI_T(KC_SCLN)
#define ALT_L RALT_T(KC_L)
#define CTL_K RCTL_T(KC_K)
#define SFT_J RSFT_T(KC_J)

// nav layer
#define GUI_BSLS GUI_T(KC_BSLS)
#define ALT_LBRC ALT_T(KC_LBRC)
#define CTL_RBRC CTL_T(KC_RBRC)
#define SFT_MINS SFT_T(KC_MINS)

#define GUI_RGHT RGUI_T(KC_RGHT)
#define ALT_UP RALT_T(KC_UP)
#define CTL_DOWN RCTL_T(KC_DOWN)
#define SFT_LEFT RSFT_T(KC_LEFT)

// num layer
#define GUI_1 GUI_T(KC_1)
#define ALT_2 ALT_T(KC_2)
#define CTL_3 CTL_T(KC_3)
#define SFT_4 SFT_T(KC_4)

#define GUI_0 RGUI_T(KC_0)
#define ALT_9 RALT_T(KC_9)
#define CTL_8 RCTL_T(KC_8)
#define SFT_7 RSFT_T(KC_7)