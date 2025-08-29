#include "taphold_options.h"

uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
        case CTL_T(KC_TAB):
        case NUM_SPC:
        case NAV_ENT:
        case GUI_LAUNCH:
        case LT(_FUNC, KC_MPLY):
            return 0; // no repeat tapping when tapped and then held for these keys
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
            return 400;
            break;
        case SFT_SFT:
            return get_mods() & MOD_MASK_ALT ? TAPPING_TERM : 0;
        default:
            return TAPPING_TERM;
            break;
    }
}