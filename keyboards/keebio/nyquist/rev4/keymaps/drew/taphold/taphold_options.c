#include QMK_KEYBOARD_H

#include "../alias.h"
#include "../tap_dance/tap_dance.h"

uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
        case GUI_LAUNCH:
        case NUM_SPC:
        case NAV_ENT:
        case FUNC_PLAY: // no repeat tapping for these keys

        case ALT_A:
        case GUI_S:
        case CTL_D:
        case SFT_F:
        case ALT_SCLN:
        case GUI_L:
        case CTL_K:
        case SFT_J:

        case ALT_BSLS:
        case GUI_LBRC:
        case CTL_RBRC:
        case SFT_MINS:
        // intentionally omitting arrow keys

        case ALT_1:
        case GUI_2:
        case CTL_3:
        case SFT_4:
        case ALT_0:
        case GUI_9:
        case CTL_8:
        case SFT_7: // no repeat tapping for homerow mods
            return 0;
            break;
    }
    return QUICK_TAP_TERM;
}

bool get_permissive_hold(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
        case NUM_SPC: // permissive hold for layer tap space
            return true;
            break;

        case ALT_A:
        case GUI_S:
        case CTL_D:
        case SFT_F:
        case ALT_SCLN:
        case GUI_L:
        case CTL_K:
        case SFT_J:

        case ALT_BSLS:
        case GUI_LBRC:
        case CTL_RBRC:
        case SFT_MINS:
        case ALT_RGHT:
        case GUI_UP:
        case CTL_DOWN:
        case SFT_LEFT:

        case ALT_1:
        case GUI_2:
        case CTL_3:
        case SFT_4:
        case ALT_0:
        case GUI_9:
        case CTL_8:
        case SFT_7: // permissive hold for mod-taps
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

        case ALT_A:
        case GUI_S:
        case CTL_D:
        case SFT_F:
        case ALT_SCLN:
        case GUI_L:
        case CTL_K:
        case SFT_J:

        case ALT_BSLS:
        case GUI_LBRC:
        case CTL_RBRC:
        case SFT_MINS:
        case ALT_RGHT:
        case GUI_UP:
        case CTL_DOWN:
        case SFT_LEFT:

        case ALT_1:
        case GUI_2:
        case CTL_3:
        case SFT_4:
        case ALT_0:
        case GUI_9:
        case CTL_8:
        case SFT_7: // no hold on other key press for mod taps
            return false;
            break;
    }
    return true;
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
        case GUI_S:
        case GUI_L:
        case GUI_2:
        case GUI_9:
        case GUI_LBRC:
        case GUI_UP:

        case ALT_A:
        case ALT_SCLN:
        case ALT_1:
        case ALT_0:
        case ALT_BSLS:
        case ALT_RGHT: // alt and gui have events for a hold and release
        
        case GUI_LAUNCH: // also non-homerow mod-taps
            return 400;
            break;
    }
    return TAPPING_TERM;
}
