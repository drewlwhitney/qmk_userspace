#include "./layers.h"

bool NUM_latched = false;
bool NAV_pressed_first = false;

layer_state_t layer_state_set_user(layer_state_t state) {
    // NUM latching
    if (NUM_latched) {
        if (IS_LAYER_ON_STATE(state, _SYM) && IS_LAYER_ON_STATE(state, _NAV)) {
            state |= 1 << _NUM; // turn on NUM
        } else {
            // if both NAV and SYM are off, de-latch NUM
            if (!IS_LAYER_ON_STATE(state, _SYM) && !IS_LAYER_ON_STATE(state, _NAV)) {
                NUM_latched = false;
                NAV_pressed_first = false; // reset to the original state
            }
            // since both layers aren't held, turn off NUM
            state &= ~(1 << _NUM);
        }
    } else {
        if (NAV_pressed_first && IS_LAYER_ON_STATE(state, _SYM)) {
            // both layers are on in the correct order, so turn on NUM and latch it
            NUM_latched = true;
            state |= 1 << _NUM;
        } else {
            NAV_pressed_first = IS_LAYER_ON_STATE(state, _NAV) && !IS_LAYER_ON_STATE(state, _SYM);
        }
    }

    return state;
}
