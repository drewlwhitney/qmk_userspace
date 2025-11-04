#include QMK_KEYBOARD_H
#include "../alias.h"

uint16_t get_flow_tap_term(uint16_t keycode, keyrecord_t* record, uint16_t previous_keycode) {
    switch (get_tap_keycode(previous_keycode)) {
        case KC_A ... KC_Z:
        case KC_DOT:
        case KC_COMM:
        case KC_SCLN:
        case KC_SLSH:
        case KC_QUOT: // enable flow-tap for these keys
            break;
        
        default: // disable otherwise
            return 0;
    }

    switch (keycode) {
        case CTL_D:
        case CTL_K:
        case CTL_3:
        case CTL_8:
        case CTL_RBRC:
        case CTL_DOWN: // control should always be allowed to hold

        case GUI_LAUNCH: // same with non-homerow mod taps

        case NUM_SPC:
        case NAV_ENT:
        case FUNC_PLAY: // same with layer-taps
            return 0;
            break;
    }
    return FLOW_TAP_TERM;  // enable flow-tap
}
