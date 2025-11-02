#include "./taphold_options.h"
#include "../alias.h"
#include "../tap_dance/tap_dance.h"

uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
        case CTL_T(KC_TAB):
        case NUM_SPC:
        case NAV_ENT:
        case GUI_LAUNCH:
        case FUNC_PLAY:
            return 0; // no repeat tapping when tapped and then held for these keys
            break;
    }
    return QUICK_TAP_TERM;
}

bool get_permissive_hold(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
        case NUM_SPC: // permissive hold for layer tap space
            return true;
            break;
    }
    return false;
}

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
        case NUM_SPC: // no hold on other key press for layer tap space
            return false;
            break;
    }
    return true;
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
        case GUI_LAUNCH:
            return 400;
            break;
    }
    return TAPPING_TERM;
}
