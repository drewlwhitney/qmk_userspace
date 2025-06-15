#include "mod_suppression.h"

void trigger_dummy_key(uint8_t mods) {
    if (mods & MOD_BIT(DUMMY_MOD_NEUTRALIZER_KEYCODE)) {
        unregister_mods(MOD_BIT(DUMMY_MOD_NEUTRALIZER_KEYCODE));
        register_mods(MOD_BIT(DUMMY_MOD_NEUTRALIZER_KEYCODE));
    } else {
        tap_code(DUMMY_MOD_NEUTRALIZER_KEYCODE);
    }
}
void suppress_flashing_mods(uint8_t mods) {
    trigger_dummy_key(mods);
    del_mods(MOD_MASK_AG);
}
void neutralize_mods_on_release(void) {
    uint8_t mods = get_mods();
    if (mods & (MOD_MASK_AG)) {
        send_keyboard_report();
        trigger_dummy_key(mods);
    }
}
// void tap_code16_suppress(uint16_t keycode, uint8_t mods) {
//     suppress_flashing_mods(mods);
//     tap_code16(keycode);
//     set_mods(mods);
// }
// void register_code16_suppress(uint16_t keycode, uint8_t mods) {
//     suppress_flashing_mods(mods);
//     register_code16(keycode);
//     set_mods(mods);
// }