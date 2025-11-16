#include QMK_KEYBOARD_H

#include "../alias.h"
#include "../tap_dance/tap_dance.h"

uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
        case NAV_TAB:
        case NUM_SPC:
        case SFT_BSPC:
        case SYM_ENT:
            return 0;
            break;
    }
    return QUICK_TAP_TERM;
}

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
        case NUM_SPC:
            return false;
            break;
    }
    return true;
}

bool get_permissive_hold(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
        case NUM_SPC:
            return true;
            break;
    }
    return false;
}