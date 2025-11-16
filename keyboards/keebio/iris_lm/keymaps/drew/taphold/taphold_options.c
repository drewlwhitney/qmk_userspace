#include QMK_KEYBOARD_H

#include "../alias.h"
#include "../tap_dance/tap_dance.h"

uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
        case SYM_ENT: // no repeat tapping for this key
            return 0;
            break;
    }
    return QUICK_TAP_TERM;
}

