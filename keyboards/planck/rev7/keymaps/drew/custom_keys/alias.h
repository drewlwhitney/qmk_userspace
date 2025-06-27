#pragma once

#include QMK_KEYBOARD_H
#include "../common.h"

#define TAB_FORWARD C(KC_TAB)
#define TAB_BACKWARD (C(S(KC_TAB)))
#define LAUNCH A(KC_SPC)
#define MENU S(KC_F10)
#define GUI_LAUNCH GUI_T(NK(TH_LAUNCH))
#define ALT_DEL ALT_T(NK(TH_DEL))
#define ALT_COMP ALT_T(NK(TH_RALT))
#define SFT_TILD SFT_T(NK(TH_TILD))
#define SFT_SFT SFT_T(NK(TH_LSFT))
#define SFT_COMM SFT_T(NK(TH_COMM))
#define CTL_COLN CTL_T(NK(TH_COLN))

// non-custom
#define NUM_SPC LT(_NUM, TH_SPC)
#define NAV_ENT LT(_NAV, KC_ENT)
#define CAD C(A(KC_DEL))
#define LOCK G(KC_L)