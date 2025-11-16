#include "./combos.h"
#include "../alias.h"
#include "../layers/layers.h"

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