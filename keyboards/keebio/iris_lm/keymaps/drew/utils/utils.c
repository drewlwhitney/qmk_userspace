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

bool toggle_caps_word(bool key_down, void* _) {
    caps_word_toggle();
    return false;
}

bool unshift_register_or_ctrl_fallthrough(
    uint8_t keycode, uint8_t control_keycode, keyrecord_t* record
) {
    if (record->tap.count) {
        if (record->event.pressed) {
            uint8_t mods = get_mods();
            if (mods & MOD_MASK_CTRL) {
                register_code(control_keycode);
                return false;
            } else if (mods & MOD_MASK_SHIFT) {
                del_mods(MOD_MASK_SHIFT); // remove shift
                // register the code. This is fine because you will just chop to the 8-bit keycode
                register_code(keycode);
                set_mods(mods); // re-add shift
                return false;
            }
        } else {
            unregister_code(control_keycode);
        }
    }
    return true;
}

bool unshift_register(uint8_t keycode, keyrecord_t* record) {
    if (record->tap.count && record->event.pressed) {
        uint8_t mods = get_mods();
        if (mods & MOD_MASK_SHIFT) {
            del_mods(MOD_MASK_SHIFT);
            register_code(keycode);
            set_mods(mods);
            return false;
        }
    }
    return true;
}
