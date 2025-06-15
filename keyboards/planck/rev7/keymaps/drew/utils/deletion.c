#include "deletion.h"

void obliterate_line(uint8_t deletion_keycode) {
    uint8_t movement_keycode;
    switch (deletion_keycode) {
        case KC_BSPC:
            movement_keycode = KC_HOME;
            break;
        case KC_DEL:
            movement_keycode = KC_END;
            break;
        default: // this should never run
            return;
            break;
    }
    tap_code16(S(movement_keycode));
    register_code(deletion_keycode);
}