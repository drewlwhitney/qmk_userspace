#include "./tap_dance.h"
#include "../alias.h"

void CAD_lock_sleep(tap_dance_state_t* state, void*) {
    switch (state->count) {
        case 1:
            tap_code16(CAD);
            break;
        case 2:
            tap_code16(G(KC_L));
            break;
        case 3:
            tap_code16(KC_SLEP);
            reset_tap_dance(state);
            break;
    }
}

void enter_gamer_mode(tap_dance_state_t* state, void*) {
    switch (state->count) {
        case 1:
            break;
        case 2:
            break;
        case 3:
            layer_on(_GAME);
            reset_tap_dance(state);
            break;
    }
}