#include "./combos.h"
#include "../alias.h"
#include "../layers/layers.h"

uint16_t get_combo_term(uint16_t combo_index, combo_t* combo) {
    switch (combo_index) {
        case NumCombo:
            return 150; // make a larger window for triggering the combo
            break;
    }
    return COMBO_TERM;
}

// necessary to make sure the layers are turned off for the NUM layer combo, since the original
// layer keys are consumed by the combo activation
bool process_combo_key_release(
    uint16_t combo_index, combo_t* combo, uint8_t key_index, uint16_t keycode
) {
    switch (combo_index) {
        case NumCombo:
            // whenever one of the layer keys is released, turn off that layer (this will
            // automatically turn off the NUM layer because of the layer_state_set_user() callback)
            switch (keycode) {
                case SYM_BSPC:
                    layer_off(_SYM);
                    break;
                case NAV_TAB:
                    layer_off(_NAV);
                    break;
            }
            break;
    }
    return false;
}

// necessary for the NUM layer combo, since it shouldn't trigger on a tap
bool get_combo_must_hold(uint16_t combo_index, combo_t* combo) {
    switch (combo_index) {
        case NumCombo: // make the NUM layer combo hold-only
            return true;
            break;
    }
    return false;
}

bool process_combo_key_repress(
    uint16_t combo_index, combo_t* combo, uint8_t key_index, uint16_t keycode
) {
    switch (combo_index) {
        case WinSwapCombo:
            // implement the tab left and tab right part of alt-tab
            switch (keycode) {
                case TAB_LEFT:
                    tap_code16(S(KC_TAB));
                    break;
                case TAB_RIGHT:
                    tap_code(KC_TAB);
                    break;
            }
            return true;
            break;
    }
    return false;
}