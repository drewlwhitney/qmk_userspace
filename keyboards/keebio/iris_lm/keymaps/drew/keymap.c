#include "config.h"
#include QMK_KEYBOARD_H
#include <stdbool.h>
#include <stdint.h>

// -------------------------------------------------------------------------------------------------
// definitions

enum {
    _BASE,
    _VIDEO,
    _NUMPAD,
    _SYM,
    _NAV,
    _NUM,
    _FUNC,
};

// keys
#define COMPOSE KC_SCRL
#define CAD C(A(KC_DEL))
#define LAUNCH G(KC_SPC)
#define MENU S(KC_F10)
#define TAB_RIGHT C(KC_TAB)
#define TAB_LEFT (C(S(KC_TAB)))
#define MOVE_TAB_LEFT C(S(KC_PGUP))
#define MOVE_TAB_RIGHT C(S(KC_PGDN))
#define ZOOM_IN C(KC_EQL)
#define ZOOM_OUT C(KC_MINS)

// layers
#define VIDEO_PLAY LT(_VIDEO, KC_MPLY)
#define NUMPAD MO(_NUMPAD)
#define NAV MO(_NAV)
#define SYM MO(_SYM)
#define NUM MO(_NUM)
#define FUNC_PLAY LT(_FUNC, KC_MPLY)
#define NAV_TAB LT(_NAV, KC_TAB)
#define SYM_DEL LT(_SYM, KC_DEL)

// mod-taps
#define GUI_ESC GUI_T(KC_ESC)
#define ALT_ENT ALT_T(KC_ENT)
#define CTL_SPC CTL_T(KC_SPC)
#define SFT_BSPC SFT_T(KC_BSPC)
// character mod-taps
#define CTL_BSLS CTL_T(KC_BSLS)
#define ALT_PIPE ALT_T(KC_PIPE)
#define GUI_PLUS GUI_T(KC_PLUS)

// trigger mods
#define OBLITERATE_TRIGGER_MODS MOD_MASK_SHIFT

// -------------------------------------------------------------------------------------------------
// custom logic

void obliterate_line_backwards(void) {
    tap_code16(S(KC_HOME));
    register_code(KC_BSPC);
}

void obliterate_line_forwards(void) {
    tap_code16(S(KC_END));
    register_code(KC_DEL);
}

bool obliterate_line_backwards_callback(bool key_down, void* _) {
    if (key_down) {
        obliterate_line_backwards();
    } else {
        unregister_code(KC_BSPC);
    }
    return false;
}

bool obliterate_line_forwards_callback(bool key_down, void* _) {
    if (key_down) {
        obliterate_line_forwards();
    } else {
        unregister_code(KC_DEL);
    }
    return false;
}

// -------------------------------------------------------------------------------------------------
// keymap

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_BASE] = LAYOUT(
//┌───────────┬───────────┬───────────┬───────────┬───────────┬───────────┐                           ┌───────────┬───────────┬───────────┬───────────┬───────────┬───────────┐
   KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,                                  KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
//├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤                           ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤
   KC_NO,      KC_Q,       KC_W,       KC_F,       KC_P,       KC_B,                                   KC_J,       KC_L,       KC_U,       KC_Y,       KC_QUOT,    KC_NO,
//├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤                           ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤
   GUI_ESC,    KC_A,       KC_R,       KC_S,       KC_T,       KC_G,                                   KC_M,       KC_N,       KC_E,       KC_I,       KC_O,       ALT_ENT,
//├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┼───────────┐   ┌───────────┼───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤
   NUMPAD,     KC_Z,       KC_X,       KC_C,       KC_D,       KC_V,       KC_NO,          KC_NO,      KC_K,       KC_H,       KC_COMM,    KC_DOT,     KC_SLSH,    VIDEO_PLAY,
//└───────────┴───────────┴───────────┴─────┬─────┴─────┬─────┴─────┬─────┴────┬──────┘   └─────┬─────┴─────┬─────┴─────┬─────┴─────┬─────┴───────────┴───────────┴───────────┘
                                             FUNC_PLAY,  NAV_TAB,    CTL_SPC,                    SFT_BSPC,   SYM_DEL,    KC_NO
//                                          └───────────┴───────────┴──────────┘                └───────────┴───────────┴───────────┘
),

[_VIDEO] = LAYOUT(
//┌───────────┬───────────┬───────────┬───────────┬───────────┬───────────┐                           ┌───────────┬───────────┬───────────┬───────────┬───────────┬───────────┐
   KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,                                KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
//├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤                           ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤
   KC_TRNS,    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,                                  KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_TRNS,
//├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤                           ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤
   KC_TRNS,    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,                                  KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_TRNS,
//├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┼───────────┐   ┌───────────┼───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤
   KC_TRNS,    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_TRNS,        KC_TRNS,    KC_NO,      KC_NO,      KC_LEFT,    KC_RIGHT,   KC_SPC,     KC_TRNS,
//└───────────┴───────────┴───────────┴─────┬─────┴─────┬─────┴─────┬─────┴────┬──────┘   └─────┬─────┴─────┬─────┴─────┬─────┴─────┬─────┴───────────┴───────────┴───────────┘
                                             KC_TRNS,    KC_TRNS,    KC_TRNS,                    KC_TRNS,    KC_TRNS,    KC_TRNS
//                                          └───────────┴───────────┴──────────┘                └───────────┴───────────┴───────────┘
),

[_NUMPAD] = LAYOUT(
//┌───────────┬───────────┬───────────┬───────────┬───────────┬───────────┐                           ┌───────────┬───────────┬───────────┬───────────┬───────────┬───────────┐
   KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,                                KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
//├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤                           ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤
   KC_SLSH,    KC_7,       KC_8,       KC_9,       KC_MINS,    KC_NO,                                  KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_TRNS,
//├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤                           ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤
   KC_ASTR,    KC_4,       KC_5,       KC_6,       KC_PLUS,    KC_NO,                                  KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_TRNS,
//├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┼───────────┐   ┌───────────┼───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤
   KC_TRNS,    KC_1,       KC_2,       KC_3,       KC_DOT,     KC_NO,      KC_TRNS,        KC_TRNS,    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_TRNS,
//└───────────┴───────────┴───────────┴─────┬─────┴─────┬─────┴─────┬─────┴────┬──────┘   └─────┬─────┴─────┬─────┴─────┬─────┴─────┬─────┴───────────┴───────────┴───────────┘
                                             KC_TRNS,    KC_TRNS,    KC_0,                       KC_TRNS,    KC_TRNS,    KC_TRNS
//                                          └───────────┴───────────┴──────────┘                └───────────┴───────────┴───────────┘
),

[_SYM] = LAYOUT(
//┌───────────┬───────────┬───────────┬───────────┬───────────┬───────────┐                           ┌───────────┬───────────┬───────────┬───────────┬───────────┬───────────┐
   KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,                                KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
//├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤                           ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤
   KC_TRNS,    KC_EXLM,    KC_AT,      KC_HASH,    KC_DLR,     KC_PERC,                                KC_CIRC,    KC_AMPR,    KC_ASTR,    KC_QUES,    KC_GRV,     KC_TRNS,
//├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤                           ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤
   KC_TRNS,    KC_SCLN,    KC_COLN,    KC_UNDS,    KC_MINS,    KC_EQL,                                 KC_DQUO,    OS_LSFT,    CTL_BSLS,   ALT_PIPE,   GUI_PLUS,   KC_TRNS,
//├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┼───────────┐   ┌───────────┼───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤
   KC_TRNS,    KC_LPRN,    KC_RPRN,    KC_LBRC,    KC_RBRC,    KC_LABK,    KC_TRNS,        KC_TRNS,    KC_RABK,    KC_BSPC,    KC_LCBR,    KC_RCBR,    KC_TILDE,   KC_RABK,
//└───────────┴───────────┴───────────┴─────┬─────┴─────┬─────┴─────┬─────┴────┬──────┘   └─────┬─────┴─────┬─────┴─────┬─────┴─────┬─────┴───────────┴───────────┴───────────┘
                                             KC_TRNS,    KC_TRNS,    KC_TRNS,                    KC_TRNS,    KC_TRNS,    KC_TRNS
//                                          └───────────┴───────────┴──────────┘                └───────────┴───────────┴───────────┘
),

[_NAV] = LAYOUT(
//┌───────────┬───────────┬───────────┬───────────┬───────────┬───────────┐                           ┌───────────┬───────────┬───────────┬───────────┬───────────┬───────────┐
   KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,                                KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
//├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤                           ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤
   KC_TRNS,    CAD,        KC_F11,     TAB_LEFT,   TAB_RIGHT,  KC_NO,                                  KC_PGUP,    KC_HOME,    KC_UP,      KC_END,     COMPOSE,    KC_TRNS,
//├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤                           ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤
   KC_TRNS,    OS_LGUI,    OS_LALT,    OS_LCTL,    OS_LSFT,    KC_F2,                                  KC_CAPS,    KC_LEFT,    KC_DOWN,    KC_RGHT,    CW_TOGG,    KC_TRNS,
//├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┼───────────┐   ┌───────────┼───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤
   KC_TRNS,    ZOOM_OUT,   ZOOM_IN,    KC_WBAK,    KC_WFWD,    KC_NO,      KC_TRNS,        KC_TRNS,    KC_PGDN,    KC_NO,      KC_COMM,    KC_DOT,     KC_SLSH,    KC_TRNS,
//└───────────┴───────────┴───────────┴─────┬─────┴─────┬─────┴─────┬─────┴────┬──────┘   └─────┬─────┴─────┬─────┴─────┬─────┴─────┬─────┴───────────┴───────────┴───────────┘
                                             KC_TRNS,    KC_TRNS,    KC_TRNS,                    KC_TRNS,    KC_TRNS,    KC_TRNS
//                                          └───────────┴───────────┴──────────┘                └───────────┴───────────┴───────────┘
),

[_NUM] = LAYOUT(
//┌───────────┬───────────┬───────────┬───────────┬───────────┬───────────┐                           ┌───────────┬───────────┬───────────┬───────────┬───────────┬───────────┐
   KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,                                KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
//├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤                           ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤
   KC_TRNS,    KC_NO,      KC_PLUS,    KC_E,       KC_MINS,    KC_EQL,                                 KC_CIRC,    KC_NO,      KC_ASTR,    KC_NO,      KC_NO,      KC_TRNS,
//├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤                           ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤
   KC_TRNS,    KC_1,       KC_2,       KC_3,       KC_4,       KC_5,                                   KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_TRNS,
//├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┼───────────┐   ┌───────────┼───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤
   KC_TRNS,    KC_LPRN,    KC_RPRN,    KC_NO,      KC_SPC,     KC_NO,      KC_TRNS,        KC_TRNS,    KC_NO,      KC_BSPC,    KC_COMM,    KC_DOT,     KC_SLSH,    KC_TRNS,
//└───────────┴───────────┴───────────┴─────┬─────┴─────┬─────┴─────┬─────┴────┬──────┘   └─────┬─────┴─────┬─────┴─────┬─────┴─────┬─────┴───────────┴───────────┴───────────┘
                                             KC_TRNS,    KC_TRNS,    KC_TRNS,                    KC_TRNS,    KC_TRNS,    KC_TRNS
//                                          └───────────┴───────────┴──────────┘                └───────────┴───────────┴───────────┘
),

[_FUNC] = LAYOUT(
//┌───────────┬───────────┬───────────┬───────────┬───────────┬───────────┐                           ┌───────────┬───────────┬───────────┬───────────┬───────────┬───────────┐
   KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,                                KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
//├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤                           ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤
   KC_TRNS,    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_SLEP,                                QK_BOOT,    KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_TRNS,
//├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤                           ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤
   KC_TRNS,    KC_MPRV,    KC_MNXT,    KC_VOLD,    KC_VOLU,    KC_MUTE,                                KC_NO,      KC_F5,      KC_F6,      KC_F7,      KC_F8,      KC_TRNS,
//├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┼───────────┐   ┌───────────┼───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤
   KC_TRNS,    KC_NO,      KC_NO,      KC_BRID,    KC_BRIU,    QK_BOOT,    KC_TRNS,        KC_TRNS,    KC_NO,      KC_F9,      KC_F10,     KC_F11,     KC_F12,     KC_TRNS,
//└───────────┴───────────┴───────────┴─────┬─────┴─────┬─────┴─────┬─────┴────┬──────┘   └─────┬─────┴─────┬─────┴─────┬─────┴─────┬─────┴───────────┴───────────┴───────────┘
                                             KC_TRNS,    KC_TRNS,    KC_TRNS,                    KC_TRNS,    KC_TRNS,    KC_TRNS
//                                          └───────────┴───────────┴──────────┘                └───────────┴───────────┴───────────┘
),

};
// clang-format on

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
        case CTL_SPC:
            if (get_highest_layer(layer_state) != _BASE) {
                return true;
            }
            if (record->event.pressed && record->tap.count > 0) {
                uint8_t mods = get_mods();
                if ((mods | get_oneshot_mods()) & MOD_MASK_CTRL) {
                    del_mods(MOD_MASK_CTRL);
                    clear_oneshot_mods();
                    tap_code16(MENU);
                    set_mods(mods);
                    return false;
                }
            }
            break;

        case SFT_BSPC:
            if (record->event.pressed && record->tap.count > 0) {
                uint8_t mods = get_mods();
                if ((mods | get_oneshot_mods()) & OBLITERATE_TRIGGER_MODS) {
                    del_mods(MOD_MASK_SHIFT);
                    clear_oneshot_mods();
                    obliterate_line_backwards();
                    set_mods(mods);
                    return false;
                }
            }
            break;

        case SYM_DEL:
            if (record->event.pressed && record->tap.count > 0) {
                uint8_t mods = get_mods();
                if ((mods | get_oneshot_mods()) & OBLITERATE_TRIGGER_MODS) {
                    del_mods(MOD_MASK_SHIFT);
                    clear_oneshot_mods();
                    obliterate_line_forwards();
                    set_mods(mods);
                    return false;
                }
            }
            break;

        case ALT_PIPE:
            if (record->tap.count > 0) {
                (record->event.pressed ? register_code16 : unregister_code16)(KC_PIPE);
            }
            return false;
            break;

        case GUI_PLUS:
            if (record->tap.count > 0) {
                (record->event.pressed ? register_code16 : unregister_code16)(KC_PLUS);
            }
            return false;
            break;
    }
    return true;
}

// -------------------------------------------------------------------------------------------------
// tap-hold config

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
        case CTL_SPC:
        case CTL_BSLS:
        case ALT_PIPE:
        case GUI_PLUS:
            return false;
            break;
    }
    return true;
}

bool get_permissive_hold(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
        case CTL_SPC:
        case CTL_BSLS:
        case ALT_PIPE:
        case GUI_PLUS:
            return true;
            break;
    }
    return false;
}

bool get_speculative_hold(uint16_t keycode, keyrecord_t* record) {
    return true;
}

uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
        case CTL_BSLS:
        case ALT_PIPE:
        case GUI_PLUS:
            return TAPPING_TERM;
            break;
    }
    return 0;
}

// -------------------------------------------------------------------------------------------------
// tri-layer

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _SYM, _NAV, _NUM);
}

// -------------------------------------------------------------------------------------------------
// caps word

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // key codes that continue Caps Word, with shift applied
        case KC_A ... KC_Z:
            add_weak_mods(MOD_BIT(KC_LSFT)); // Apply shift to next key
            return true;
            break;
        // key codes that continue Caps Word, without shifting
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_LEFT:
        case KC_RGHT:
        case KC_MINS:
        case KC_UNDS:
        case KC_SLSH:
            return true;
            break;
        default:
            return false; // Deactivate Caps Word
            break;
    }
}

// -------------------------------------------------------------------------------------------------
// key overrides

const key_override_t DEL_TO_OBLITERATE = {
    .trigger = KC_DEL,
    .trigger_mods = OBLITERATE_TRIGGER_MODS,
    .layers = 0xFF,
    .custom_action = obliterate_line_forwards_callback,
};

const key_override_t BSPC_TO_OBLITERATE = {
    .trigger = KC_BSPC,
    .trigger_mods = OBLITERATE_TRIGGER_MODS,
    .layers = 0xFF,
    .custom_action = obliterate_line_backwards_callback,
};

// tabbing and moving tabs
const key_override_t LEFT_TO_TAB_LEFT =
    ko_make_with_layers_and_negmods(MOD_MASK_ALT, KC_LEFT, TAB_LEFT, 1 << _NAV, MOD_MASK_CSG);
const key_override_t RIGHT_TO_TAB_RIGHT =
    ko_make_with_layers_and_negmods(MOD_MASK_ALT, KC_RIGHT, TAB_RIGHT, 1 << _NAV, MOD_MASK_CSG);
const key_override_t LEFT_TO_MOVE_TAB_LEFT = ko_make_with_layers_and_negmods(
    MOD_MASK_ALT | MOD_MASK_SHIFT, KC_LEFT, MOVE_TAB_LEFT, 1 << _NAV, MOD_MASK_CG
);
const key_override_t RIGHT_TO_MOVE_TAB_RIGHT = ko_make_with_layers_and_negmods(
    MOD_MASK_ALT | MOD_MASK_SHIFT, KC_RIGHT, MOVE_TAB_RIGHT, 1 << _NAV, MOD_MASK_CG
);

// noshifts
const key_override_t ONE_NOSHIFT = ko_make_basic(MOD_MASK_SHIFT, KC_1, KC_1);
const key_override_t TWO_NOSHIFT = ko_make_basic(MOD_MASK_SHIFT, KC_2, KC_2);
const key_override_t THREE_NOSHIFT = ko_make_basic(MOD_MASK_SHIFT, KC_3, KC_3);
const key_override_t FOUR_NOSHIFT = ko_make_basic(MOD_MASK_SHIFT, KC_4, KC_4);
const key_override_t FIVE_NOSHIFT = ko_make_basic(MOD_MASK_SHIFT, KC_5, KC_5);
const key_override_t SIX_NOSHIFT = ko_make_basic(MOD_MASK_SHIFT, KC_6, KC_6);
const key_override_t SEVEN_NOSHIFT = ko_make_basic(MOD_MASK_SHIFT, KC_7, KC_7);
const key_override_t EIGHT_NOSHIFT = ko_make_basic(MOD_MASK_SHIFT, KC_8, KC_8);
const key_override_t NINE_NOSHIFT = ko_make_basic(MOD_MASK_SHIFT, KC_9, KC_9);
const key_override_t ZERO_NOSHIFT = ko_make_basic(MOD_MASK_SHIFT, KC_0, KC_0);

// \[]-=`
const key_override_t BSLS_NOSHIFT = ko_make_basic(MOD_MASK_SHIFT, KC_BSLS, KC_BSLS);
const key_override_t LBRC_NOSHIFT = ko_make_basic(MOD_MASK_SHIFT, KC_LBRC, KC_LBRC);
const key_override_t RBRC_NOSHIFT = ko_make_basic(MOD_MASK_SHIFT, KC_RBRC, KC_RBRC);
const key_override_t MINS_NOSHIFT = ko_make_basic(MOD_MASK_SHIFT, KC_MINS, KC_MINS);
const key_override_t EQL_NOSHIFT = ko_make_basic(MOD_MASK_SHIFT, KC_EQL, KC_EQL);
const key_override_t GRV_NOSHIFT = ko_make_basic(MOD_MASK_SHIFT, KC_GRV, KC_GRV);

// this globally defines all key overrides to be used
const key_override_t* key_overrides[] = {
    // blocking formatting with this line
    &DEL_TO_OBLITERATE,
    &BSPC_TO_OBLITERATE,

    // tabbing and moving tabs
    &LEFT_TO_TAB_LEFT,
    &RIGHT_TO_TAB_RIGHT,
    &LEFT_TO_MOVE_TAB_LEFT,
    &RIGHT_TO_MOVE_TAB_RIGHT,

    // noshifts
    &ONE_NOSHIFT,
    &TWO_NOSHIFT,
    &THREE_NOSHIFT,
    &FOUR_NOSHIFT,
    &FIVE_NOSHIFT,
    &SIX_NOSHIFT,
    &SEVEN_NOSHIFT,
    &EIGHT_NOSHIFT,
    &NINE_NOSHIFT,
    &ZERO_NOSHIFT,

    &BSLS_NOSHIFT,
    &LBRC_NOSHIFT,
    &RBRC_NOSHIFT,
    &MINS_NOSHIFT,
    &EQL_NOSHIFT,
    &GRV_NOSHIFT,
    &GRV_NOSHIFT,
};

// -------------------------------------------------------------------------------------------------
// combos

enum Combos {
    WinSwap,
};

const uint16_t PROGMEM win_swap_combo[] = {KC_F, KC_P, COMBO_END};

combo_t key_combos[] = {
    [WinSwap] = COMBO(win_swap_combo, KC_NO),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
    switch (combo_index) {
        case WinSwap:
            if (pressed) {
                register_mods(MOD_LALT);
                tap_code(KC_TAB);
            } else {
                unregister_mods(MOD_LALT);
            }
            break;
    }
}

bool process_combo_key_repress(
    uint16_t combo_index, combo_t* combo, uint8_t key_index, uint16_t keycode
) {
    switch (combo_index) {
        case WinSwap:
            switch (keycode) {
                case KC_F:
                    tap_code16(S(KC_TAB));
                    return true;
                case KC_P:
                    tap_code(KC_TAB);
                    return true;
            }
    }
    return false;
}
