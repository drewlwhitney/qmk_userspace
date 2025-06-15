#include QMK_KEYBOARD_H
#include "caps_word/caps_word.h"
#include "custom_keys/custom_keys.h"
#include "custom_keys/mapping.h"
#include "layers.h"
#include "tap_dance.c"
#include "taphold/taphold_options.h"

bool NAV_enabled = false;

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // base
    [_BASE] = LAYOUT_ortho_4x12(
        NK(NK_ESC),        NK(NK_Q),             KC_W,           KC_E,            NK(NK_R),        KC_T,               KC_Y,               KC_U,           KC_I,         KC_O,          KC_P,          NK(NK_BSPC),
        CTL_T(KC_TAB),     KC_A,                 KC_S,           KC_D,            KC_F,            KC_G,               KC_H,               KC_J,           KC_K,         KC_L,          KC_SCLN,       KC_QUOT,
        SFT_SFT,           KC_Z,                 KC_X,           KC_C,            KC_V,            KC_B,               KC_N,               KC_M,           KC_COMM,      KC_DOT,        KC_SLSH,       ALT_DEL,
        KC_RCTL,           LT(_FUNC, KC_MPLY),   ALT_T(KC_LALT), TD(TD_CAD_LOCK), GUI_LAUNCH,      NUM_SPC,            NAV_ENT,            ALT_COMP,       KC_LEFT,      NK(NK_DOWN),   NK(NK_UP),     KC_RGHT
    ),
    // gamer
    [_GAME] = LAYOUT_ortho_4x12(
        KC_TRNS,           KC_Q,                 KC_TRNS,        KC_TRNS,         KC_R,            KC_TRNS,            KC_TRNS,            KC_TRNS,        KC_TRNS,      KC_TRNS,       KC_TRNS,       KC_TRNS,
        KC_TAB,            KC_TRNS,              KC_TRNS,        KC_TRNS,         KC_TRNS,         KC_TRNS,            KC_TRNS,            KC_TRNS,        KC_TRNS,      KC_TRNS,       KC_TRNS,       KC_TRNS,
        KC_LSFT,           KC_TRNS,              KC_TRNS,        KC_TRNS,         KC_TRNS,         KC_TRNS,            KC_TRNS,            KC_TRNS,        KC_TRNS,      KC_TRNS,       KC_TRNS,       KC_TRNS,
        KC_TRNS,           KC_TRNS,              KC_TRNS,        KC_PGDN,         KC_PGUP,         KC_TRNS,            KC_TRNS,            KC_TRNS,        KC_TRNS,      KC_TRNS,       KC_TRNS,       KC_TRNS
    ),
    // special characters
    // numbers
    [_NUM] = LAYOUT_ortho_4x12(
        KC_TRNS,           KC_SLSH,              KC_AT,          KC_ASTR,         NK(NK_MINS_NUM), KC_PLUS,            NK(NK_CIRC),        NK(NK_AMPR),    NK(NK_ASTR),  KC_LPRN,       NK(NK_RPRN),   KC_TRNS,
        CTL_T(KC_DOT),     NK(NK_1),             NK(NK_2),       NK(NK_3),        NK(NK_4),        NK(NK_5),           NK(NK_6),           NK(NK_7),       NK(NK_8),     NK(NK_9),      NK(NK_0),      KC_TRNS,
        SFT_COMM,          NK(NK_6_LOW),         NK(NK_7_LOW),   NK(NK_8_LOW),    NK(NK_9_LOW),    NK(NK_0_LOW),       KC_SCLN,            NK(NK_COLN),    KC_TRNS,      KC_TRNS,       KC_TRNS,       KC_TRNS,
        CTL_COLN,          KC_TRNS,              KC_TRNS,        KC_TRNS,         KC_TRNS,         KC_NO,              KC_TRNS,            KC_TRNS,        KC_TRNS,      KC_TRNS,       KC_TRNS,       KC_TRNS
    ),
    [_NAV] = LAYOUT_ortho_4x12(
        NK(NK_GRV),        KC_EXLM,              KC_AT,          KC_HASH,         NK(NK_DLR),      KC_PERC,            NK(NK_CIRC),        NK(NK_AMPR),    NK(NK_ASTR),  KC_LPRN,       NK(NK_RPRN),   KC_TRNS,
        KC_TRNS,           NK(NK_BSLS),          NK(NK_LBRC),    NK(NK_RBRC),     NK(NK_MINS_NAV), NK(NK_EQL),         NK(NK_HOME),        KC_LEFT,        KC_DOWN,      KC_UP,         KC_RGHT,       NK(NK_END),
        SFT_TILD,          NK(NK_PIPE),          NK(NK_LCBR),    NK(NK_RCBR),     NK(NK_UNDS),     NK(NK_PLUS),        KC_NO,              NK(NK_F2),      KC_TRNS,      KC_TRNS,       KC_TRNS,       KC_TRNS,
        KC_TRNS,           KC_TRNS,              KC_TRNS,        KC_TRNS,         KC_TRNS,         KC_TRNS,            KC_NO,              KC_TRNS,        KC_TRNS,      KC_TRNS,       KC_TRNS,       KC_TRNS
    ),
    // function
    [_FUNC] = LAYOUT_ortho_4x12(
        KC_F1,             KC_F2,                KC_F3,          KC_F4,           KC_F5,           KC_F6,              KC_F7,              KC_F8,          KC_F9,        KC_F10,        KC_F11,        KC_F12,
        KC_F7,             KC_F8,                KC_F9,          KC_F10,          KC_F11,          KC_F12,             KC_NO,              KC_NO,          KC_NO,        KC_NO,         KC_NO,         KC_NO,
        KC_TRNS,           KC_MUTE,              KC_MPRV,        KC_VOLD,         KC_VOLU,         KC_MNXT,            KC_NO,              KC_NO,          KC_NO,        QK_AUDIO_OFF,  TG(_GAME),     QK_BOOT,
        KC_TRNS,           KC_NO,                KC_BRID,        KC_BRIU,         KC_TRNS,         KC_TRNS,            KC_TRNS,            KC_TRNS,        KC_TRNS,      KC_TRNS,       KC_TRNS,       QK_RBT
    ),
};
// clang-format on

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
        // make it possible to go from layer 3 to layer 2
        case NUM_SPC:
            if (!record->tap.count) {
                if (NAV_enabled) {
                    record->event.pressed ? layer_off(_NAV) : layer_on(_NAV);
                }
            } else {
                process_custom_key(NK(TH_SPC), record);
                return false;
            }
            break;
        case NAV_ENT:
            if (!record->tap.count) {
                NAV_enabled = record->event.pressed;
            }
            break;
        case CUSTOM_KEY_RANGE:
            process_custom_key(keycode, record);
            return false;
            break;
        case GUI_LAUNCH:
        case ALT_DEL:
        case ALT_COMP:
        case SFT_TILD:
        case SFT_SFT:
        case SFT_COMM:
        case CTL_COLN:
            return process_custom_taphold(keycode, record);
            break;
    }
    return true;
}
