#include QMK_KEYBOARD_H
#include "./utils.h"

bool obliterate_line(bool key_down, uint8_t deletion_keycode, uint8_t movement_keycode) {
    if (key_down) {
        tap_code16(S(movement_keycode));
        register_code(deletion_keycode);
    } else {
        unregister_code(deletion_keycode);
    }
    return false;
}

bool obliterate_line_backwards(bool key_down, void* _) {
    return obliterate_line(key_down, KC_BSPC, KC_HOME);
}

bool obliterate_line_forwards(bool key_down, void* _) {
    return obliterate_line(key_down, KC_DEL, KC_END);
}

bool turn_on_caps_word(bool key_down, void* _) {
    caps_word_on();
    return false;
}
