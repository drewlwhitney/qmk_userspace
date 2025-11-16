#include "./layers.h"

bool NUM_latched = false;
bool NAV_pressed_first = false;

layer_state_t layer_state_set_user(layer_state_t state) {
    // allow the SYM and NUM layers to override each other
    

    return state;
}
