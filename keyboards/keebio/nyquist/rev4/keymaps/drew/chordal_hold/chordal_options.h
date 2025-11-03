#pragma once

#include QMK_KEYBOARD_H
#include "stdint.h"

bool get_chordal_hold(
    uint16_t tap_hold_keycode, keyrecord_t* tap_hold_record, uint16_t other_keycode,
    keyrecord_t* other_record
);