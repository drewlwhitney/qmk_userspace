#include QMK_KEYBOARD_H
#include "caps_word.h"

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied
        case KC_A ... KC_Z:
            add_weak_mods(MOD_BIT(KC_LSFT)); // Apply shift to next key
            return true;
            break;
        // Keycodes that continue Caps Word, without shifting
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_LEFT:
        case KC_RGHT:
        case KC_MINS:
        case KC_UNDS:
        // custom keycodes
            return true;
            break;
        default:
            return false; // Deactivate Caps Word
            break;
    }
}