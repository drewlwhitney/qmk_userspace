#include "taphold_options.h"

uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
        case CTL_T(KC_TAB):
        case NUM_SPC:
        case NAV_ENT:
        case GUI_LAUNCH: // no repeat tapping when tapped and then held for these keys
            return 0;
            break;
        default:
            return QUICK_TAP_TERM;
            break;
    }
}

bool get_permissive_hold(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
        case NUM_SPC: // permissive hold for layer tap space
            return true;
            break;
        default:
            return false;
            break;
    }
}

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
        case NUM_SPC: // no hold on other key press for layer tap space
            return false;
            break;
        default:
            return true;
            break;
    }
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
        case GUI_LAUNCH:
            return 500;
            break;
        case TD(TD_PASSWORD):
            return 800;
            break;
        default:
            return TAPPING_TERM;
            break;
    }
}