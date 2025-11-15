#include "./combos.h"
#include "../alias.h"
#include "../layers/layers.h"

uint16_t get_combo_term(uint16_t combo_index, combo_t *combo) {
    switch (combo_index) {
        case NumCombo:
            return 75;
            break;
    }
    return COMBO_TERM;
}

bool process_combo_key_release(
    uint16_t combo_index, combo_t* combo, uint8_t key_index, uint16_t keycode
) {
    switch (combo_index) {
        case NumCombo: // release the combo on any releases
            switch (keycode) {
                case SYM_ENT:
                    layer_off(_SYM);
                    break;
                case NAV:
                    layer_off(_NAV);
                    break;
            }
            layer_off(_NUM);
            break;
    }
    return false;
}

bool process_combo_key_repress(
    uint16_t combo_index, combo_t* combo, uint8_t key_index, uint16_t keycode
) {
    switch (combo_index) {
        case WinSwapCombo:
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