#include "tap_dance.h"

void on_password_tap(tap_dance_state_t* state, void* user_data) {
    switch (state->count) {
        case 1:
            tap_code16(C(A(KC_DEL)));
            break;
        case 2:
            SEND_STRING("240303");
            break;
        case 3:
            tap_code(KC_ENT);
            break;
    }
}

tap_dance_action_t tap_dance_actions[] = {
    [TD_PASSWORD] = ACTION_TAP_DANCE_FN_ADVANCED(on_password_tap, NULL, NULL),
    [TD_CAD_LOCK] = ACTION_TAP_DANCE_DOUBLE(CAD, LOCK),
};
