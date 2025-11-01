#include "mapping.h"

void obliterate_line_backwards(custom_key_t* custom_key) {
    obliterate_line(KC_BSPC);
    update_held_keycode(custom_key, KC_BSPC);
}
void obliterate_line_forwards(custom_key_t* custom_key) {
    obliterate_line(KC_DEL);
    update_held_keycode(custom_key, KC_DEL);
}
void launch(custom_key_t* custom_key) {
    tap_code16(LAUNCH);
    update_held_keycode(custom_key, KC_NO);
}
void turn_on_caps_word(custom_key_t* custom_key) {
    caps_word_on();
    update_held_keycode(custom_key, KC_NO);
}

custom_key_t custom_keys[] = {
    // _BASE layer

    // _NUM layer
    [NK_COLN] = CUSTOM_KEY(KC_COLN, 1, REMAP(KC_M, MOD_MASK_CTRL)),
    [NK_MINS_NUM] = CUSTOM_KEY(
        KC_MINS, 2, REMAP(KC_R, MOD_MASK_CTRL),
        REMAP_WITH_OPTIONS(KC_MINS, MOD_MASK_SHIFT, REMOVE_TRIGGER, false)
    ),

    // _NAV layer
    [NK_BSLS] = CUSTOM_KEY(
        KC_BSLS, 2, REMAP(KC_A, MOD_MASK_CTRL),
        REMAP_WITH_OPTIONS(KC_BSLS, MOD_MASK_SHIFT, REMOVE_TRIGGER, false)
    ),
    [NK_LBRC] = CUSTOM_KEY(
        KC_LBRC, 2, REMAP(KC_S, MOD_MASK_CTRL),
        REMAP_WITH_OPTIONS(KC_LBRC, MOD_MASK_SHIFT, REMOVE_TRIGGER, false)
    ),
    [NK_RBRC] =
        CUSTOM_KEY(KC_RBRC, 1, REMAP_WITH_OPTIONS(KC_RBRC, MOD_MASK_SHIFT, REMOVE_TRIGGER, false)),
    [NK_MINS_NAV] = CUSTOM_KEY(
        KC_MINS, 2, REMAP(KC_F, MOD_MASK_CTRL),
        REMAP_WITH_OPTIONS(KC_MINS, MOD_MASK_SHIFT, REMOVE_TRIGGER, false)
    ),
    [NK_EQL] =
        CUSTOM_KEY(KC_EQL, 1, REMAP_WITH_OPTIONS(KC_EQL, MOD_MASK_SHIFT, REMOVE_TRIGGER, false)),
    [NK_GRV] = CUSTOM_KEY(
        KC_GRV, 2, REMAP_WITH_OPTIONS(TAB_FORWARD, MOD_MASK_ALT, REMOVE_ALL, false),
        REMAP_WITH_OPTIONS(KC_GRV, MOD_MASK_SHIFT, REMOVE_TRIGGER, false)
    ),
    [NK_PIPE] = CUSTOM_KEY(KC_PIPE, 1, REMAP(KC_Z, MOD_MASK_CTRL)),
    [NK_LCBR] = CUSTOM_KEY(KC_LCBR, 1, REMAP(KC_X, MOD_MASK_CTRL)),
    [NK_RCBR] = CUSTOM_KEY(KC_RCBR, 1, REMAP(KC_C, MOD_MASK_CTRL)),
    [NK_UNDS] = CUSTOM_KEY(KC_UNDS, 1, REMAP(KC_V, MOD_MASK_CTRL)),
    [NK_PLUS] = CUSTOM_KEY(KC_PLUS, 1, REMAP(KC_B, MOD_MASK_CTRL)),
    [NK_F2] = CUSTOM_KEY(KC_F2, 1, REMAP(KC_M, MOD_MASK_CTRL)),
    [NK_DLR] = CUSTOM_KEY(KC_DLR, 1, REMAP(KC_Y, MOD_MASK_CTRL)),
    [NK_HOME] = CUSTOM_KEY(
        KC_HOME, 2, REMAP_WITH_OPTIONS(C(KC_HOME), MOD_MASK_GUI, REMOVE_TRIGGER, false),
        REMAP_WITH_OPTIONS(KC_HOME, MOD_MASK_CTRL, REMOVE_TRIGGER, false)
    ),
    [NK_END] = CUSTOM_KEY(
        KC_END, 2, REMAP_WITH_OPTIONS(C(KC_END), MOD_MASK_GUI, REMOVE_TRIGGER, false),
        REMAP_WITH_OPTIONS(KC_END, MOD_MASK_CTRL, REMOVE_TRIGGER, false)
    ),

    // multiple layers
    [NK_CIRC] = CUSTOM_KEY(KC_CIRC, 1, REMAP(KC_Y, MOD_MASK_CTRL)),
    [NK_AMPR] = CUSTOM_KEY(KC_AMPR, 1, REMAP(KC_U, MOD_MASK_CTRL)),
    [NK_ASTR] = CUSTOM_KEY(KC_ASTR, 1, REMAP(KC_I, MOD_MASK_CTRL)),
    [NK_RPRN] = CUSTOM_KEY(KC_RPRN, 1, REMAP(KC_P, MOD_MASK_CTRL)),

    // tap-hold
    [TH_TILD] =
        CUSTOM_KEY(KC_TILD, 1, REMAP_WITH_OPTIONS(TAB_BACKWARD, MOD_MASK_ALT, REMOVE_ALL, false)),
    [TH_COMM] =
        CUSTOM_KEY(KC_COMM, 1, REMAP_WITH_OPTIONS(TAB_BACKWARD, MOD_MASK_ALT, REMOVE_ALL, false)),
    [TH_COLN] = CUSTOM_KEY_NO_REMAP(KC_COLN),
};