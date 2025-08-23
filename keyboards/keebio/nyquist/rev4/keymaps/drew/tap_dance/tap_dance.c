#include "tap_dance.h"
#include "../common.h"
#include "../custom_keys/alias.h"

void CAD_lock_sleep(tap_dance_state_t* state, void* user_data) {
    switch (state->count) {
        case 1:
            tap_code16(CAD);
            break;
        case 2:
            tap_code16(G(KC_L));
            break;
        case 3:
            tap_code16(KC_SLEP);
        default:
            reset_tap_dance(state);
            break;
    }
}

tap_dance_action_t tap_dance_actions[] = {
    [TD_CAD_LOCK_SLEEP] = ACTION_TAP_DANCE_FN(CAD_lock_sleep),
};
