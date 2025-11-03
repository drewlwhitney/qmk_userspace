#include QMK_KEYBOARD_H

#include "../alias.h"
#include "../tap_dance/tap_dance.h"

uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
        case CTL_T(KC_TAB):
        case NUM_SPC:
        case NAV_ENT:
        case FUNC_PLAY: // no repeat tapping for these keys

        case GUI_A:
        case ALT_S:
        case SFT_D:
        case CTL_F:
        case CTL_G:
        case GUI_SCLN:
        case ALT_L:
        case SFT_K:
        case CTL_J:
        case CTL_H:

        case GUI_1:
        case ALT_2:
        case SFT_3:
        case CTL_4:
        case GUI_0:
        case ALT_9:
        case SFT_8:
        case CTL_7:

        case GUI_BSLS:
        case ALT_LBRC:
        case SFT_RBRC:
        case CTL_MINS: // no repeat tapping for homerow mods
        // intentionally omitting arrow keys
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
        case GUI_A:
        case ALT_S:
        case SFT_D:
        case CTL_F:
        case CTL_G:
        case GUI_SCLN:
        case ALT_L:
        case SFT_K:
        case CTL_J:
        case CTL_H:

        case GUI_1:
        case ALT_2:
        case SFT_3:
        case CTL_4:
        case GUI_0:
        case ALT_9:
        case SFT_8:
        case CTL_7:

        case GUI_BSLS:
        case ALT_LBRC:
        case SFT_RBRC:
        case CTL_MINS: // permissive hold for homerow mods
        case GUI_RGHT:
        case ALT_UP:
        case SFT_DOWN:
        case CTL_LEFT:
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

        case GUI_A:
        case ALT_S:
        case SFT_D:
        case CTL_F:
        case CTL_G:
        case GUI_SCLN:
        case ALT_L:
        case SFT_K:
        case CTL_J:
        case CTL_H:

        case GUI_1:
        case ALT_2:
        case SFT_3:
        case CTL_4:
        case GUI_0:
        case ALT_9:
        case SFT_8:
        case CTL_7:

        case GUI_BSLS:
        case ALT_LBRC:
        case SFT_RBRC:
        case CTL_MINS: // no hold on other key press for homerow mods
        case GUI_RGHT:
        case ALT_UP:
        case SFT_DOWN:
        case CTL_LEFT:
            return false;
            break;
    }
    return true;
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
        case GUI_A:
        case GUI_SCLN:
        case GUI_1:
        case GUI_0:
        case GUI_BSLS:
        case GUI_RGHT:

        case ALT_S:
        case ALT_L:
        case ALT_2:
        case ALT_9:
        case ALT_LBRC: // alt and gui have events for a hold and release
        case ALT_UP:
            return 400;
            break;
        
        case CW_CL: // have to hold for caps lock a little longer
            return 300;
            break;
    }
    return TAPPING_TERM;
}
