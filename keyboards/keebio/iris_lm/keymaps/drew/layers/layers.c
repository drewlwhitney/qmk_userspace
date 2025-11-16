#include "./layers.h"

// bool NUM_latched = false;

// layer_state_t layer_state_set_user(layer_state_t state) {
    // NUM latching
    // if (NUM_latched) {
    //     if (IS_LAYER_ON_STATE(state, _SYM) && IS_LAYER_ON_STATE(state, _NAV)) {
    //         state |= 1 << _NUM; // turn on NUM
    //     } else {
    //         // if both NAV and SYM are off, de-latch NUM
    //         if (!IS_LAYER_ON_STATE(state, _SYM) && !IS_LAYER_ON_STATE(state, _NAV)) {
    //             NUM_latched = false;
    //         }
    //         // since both layers aren't held, turn off NUM
    //         state &= ~(1 << _NUM);
    //     }
    // } else if (IS_LAYER_ON_STATE(state, _NUM)) {
    //     NUM_latched = true;
    //     state |= 1 << _NAV | 1 << _SYM; // turn on NAV and SYM
    // }

    // return update_tri_layer_state(state, _SYM, _NAV, _NUM);

//     return state;
// }
