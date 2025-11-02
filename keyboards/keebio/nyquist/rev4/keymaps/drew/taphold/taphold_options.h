#pragma once

#include QMK_KEYBOARD_H
#include "stdint.h"

uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t* record);
bool get_permissive_hold(uint16_t keycode, keyrecord_t* record);
bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t* record);
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t* record);