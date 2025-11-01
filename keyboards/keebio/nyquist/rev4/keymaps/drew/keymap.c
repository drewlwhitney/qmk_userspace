#include QMK_KEYBOARD_H
#include "caps_word/caps_word.h"
#include "common.h"
#include "layers.h"
#include "tap_dance/tap_dance.c"
#include "tap_dance/tap_dance.h"
#include "taphold/taphold_options.h"

bool NAV_enabled = false;

enum CustomKeycodes {
    DOWN = SAFE_RANGE + 50,
    UP,

    LOW_6,
    LOW_7,
    LOW_8,
    LOW_9,
    LOW_0,
};

#define SFT_DEL SFT_T(KC_DEL)
#define L_SFT SFT_T(KC_LSFT)
#define ALT_COMP ALT_T(KC_RALT)

/// @brief Neutralize flashing modifiers (Alt and Super) if they are active.
static inline void neutralize_flashing_mods(void) {
    if (get_mods() & MOD_MASK_AG) {
        tap_code(DUMMY_MOD_NEUTRALIZER_KEYCODE);
    }
}

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // base
    [_BASE] = LAYOUT_ortho_4x12(
        KC_ESC,            KC_Q,                 KC_W,           KC_E,                  KC_R,            KC_T,               KC_Y,               KC_U,           KC_I,         KC_O,          KC_P,          KC_BSPC,
        CTL_T(KC_TAB),     KC_A,                 KC_S,           KC_D,                  KC_F,            KC_G,               KC_H,               KC_J,           KC_K,         KC_L,          KC_SCLN,       KC_QUOT,
        L_SFT,             KC_Z,                 KC_X,           KC_C,                  KC_V,            KC_B,               KC_N,               KC_M,           KC_COMM,      KC_DOT,        KC_SLSH,       SFT_DEL,
        KC_RCTL,           LT(_FUNC, KC_MPLY),   ALT_T(KC_LALT), TD(TD_CAD_LOCK_SLEEP), GUI_LAUNCH,      NUM_SPC,            NAV_ENT,            ALT_COMP,       KC_LEFT,      DOWN,          UP,            KC_RGHT
    ),
    // gamer
    [_GAME] = LAYOUT_ortho_4x12(
        KC_TRNS,           KC_Q,                 KC_TRNS,        KC_TRNS,               KC_TRNS,         KC_TRNS,            KC_TRNS,            KC_TRNS,        KC_TRNS,      KC_TRNS,       KC_TRNS,       KC_TRNS,
        KC_TAB,            KC_TRNS,              KC_TRNS,        KC_TRNS,               KC_TRNS,         KC_TRNS,            KC_TRNS,            KC_TRNS,        KC_TRNS,      KC_TRNS,       KC_TRNS,       KC_TRNS,
        KC_LSFT,           KC_TRNS,              KC_TRNS,        KC_TRNS,               KC_TRNS,         KC_TRNS,            KC_TRNS,            KC_TRNS,        KC_TRNS,      KC_TRNS,       KC_TRNS,       KC_TRNS,
        KC_TRNS,           KC_TRNS,              KC_TRNS,        KC_PGDN,               KC_PGUP,         KC_TRNS,            KC_TRNS,            KC_TRNS,        KC_TRNS,      KC_TRNS,       KC_TRNS,       KC_TRNS
    ),
    // special characters
    // numbers
    [_NUM] = LAYOUT_ortho_4x12(
        KC_TRNS,           KC_SLSH,              KC_AT,          KC_ASTR,               NK(NK_MINS_NUM), KC_PLUS,            NK(NK_CIRC),        NK(NK_AMPR),    NK(NK_ASTR),  KC_LPRN,       NK(NK_RPRN),   KC_TRNS,
        CTL_T(KC_DOT),     KC_1,                 KC_2,           KC_3,                  KC_4,            KC_5,               KC_6,               KC_7,           KC_8,         KC_9,          KC_0,          KC_TRNS,
        SFT_COMM,          LOW_6,                LOW_7,          LOW_8,                 LOW_9,           LOW_0,              KC_SCLN,            NK(NK_COLN),    KC_TRNS,      KC_TRNS,       KC_TRNS,       KC_TRNS,
        CTL_COLN,          KC_TRNS,              KC_TRNS,        KC_TRNS,               KC_TRNS,         KC_NO,              KC_TRNS,            KC_TRNS,        KC_TRNS,      KC_TRNS,       KC_TRNS,       KC_TRNS
    ),
    [_NAV] = LAYOUT_ortho_4x12(
        NK(NK_GRV),        KC_EXLM,              KC_AT,          KC_HASH,               NK(NK_DLR),      KC_PERC,            NK(NK_CIRC),        NK(NK_AMPR),    NK(NK_ASTR),  KC_LPRN,       NK(NK_RPRN),   KC_TRNS,
        KC_TRNS,           NK(NK_BSLS),          NK(NK_LBRC),    NK(NK_RBRC),           NK(NK_MINS_NAV), NK(NK_EQL),         NK(NK_HOME),        KC_LEFT,        KC_DOWN,      KC_UP,         KC_RGHT,       NK(NK_END),
        SFT_TILD,          NK(NK_PIPE),          NK(NK_LCBR),    NK(NK_RCBR),           NK(NK_UNDS),     NK(NK_PLUS),        KC_NO,              NK(NK_F2),      KC_TRNS,      KC_TRNS,       KC_TRNS,       KC_TRNS,
        KC_TRNS,           KC_TRNS,              KC_TRNS,        KC_TRNS,               KC_TRNS,         KC_TRNS,            KC_NO,              KC_TRNS,        KC_TRNS,      KC_TRNS,       KC_TRNS,       KC_TRNS
    ),
    // function
    [_FUNC] = LAYOUT_ortho_4x12(
        KC_F1,             KC_F2,                KC_F3,          KC_F4,                 KC_F5,           KC_F6,              KC_F7,              KC_F8,          KC_F9,        KC_F10,        KC_F11,        KC_F12,
        KC_F7,             KC_F8,                KC_F9,          KC_F10,                KC_F11,          KC_F12,             KC_NO,              KC_NO,          KC_NO,        KC_NO,         KC_NO,         QK_RBT,
        KC_TRNS,           KC_MUTE,              KC_MPRV,        KC_VOLD,               KC_VOLU,         KC_MNXT,            KC_NO,              KC_NO,          KC_NO,        KC_NO,         TG(_GAME),     QK_BOOT,
        KC_TRNS,           KC_NO,                KC_BRID,        KC_BRIU,               KC_TRNS,         KC_TRNS,            KC_TRNS,            KC_TRNS,        KC_WBAK,      KC_TRNS,       KC_TRNS,       KC_WFWD
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
                if (record->event.pressed) {
                    uint8_t mods = get_mods();
                    if (mods & MOD_MASK_CTRL) {
                        del_mods(mods);
                        tap_code16(MENU);
                        set_mods(mods);
                        return false;
                    }
                }
            }
            break;

        case NAV_ENT:
            if (!record->tap.count) {
                NAV_enabled = record->event.pressed;
            }
            break;

        case GUI_LAUNCH:
            if (record->tap.count && record->event.pressed) {
                tap_code16(LAUNCH);
                return false;
            }
            break;

        case SFT_DEL:
            if (record->tap.count) { // only trigger on taps, not holds
                uint8_t mods = get_mods();
                if (mods & MOD_MASK_GUI) { // obliterate line forwards
                    if (record->event.pressed) {
                        del_mods(MOD_MASK_GUI);
                        tap_code16(S(KC_END));
                        register_code(KC_DEL);
                        set_mods(mods);
                        return false;
                    } else {
                        neutralize_flashing_mods();
                    }
                } else if (mods & MOD_MASK_SHIFT) { // caps word
                    if (record->event.pressed) {
                        caps_word_on();
                    }
                    return false;
                }
            }
            break;

        case L_SFT:
            static bool tab_backward_held = false;
            if (record->tap.count) {
                if (record->event.pressed) {
                    uint8_t mods = get_mods();
                    if (mods & MOD_MASK_ALT) {
                        del_mods(MOD_MASK_ALT);
                        register_code16(TAB_BACKWARD);
                        set_mods(mods);
                        tab_backward_held = true; // set the flag
                        return false;
                    } else if (mods & MOD_MASK_SHIFT) {
                        caps_word_on();
                        return false;
                    }
                } else {
                    if (tab_backward_held) {
                        tab_backward_held = false; // clear the flag
                        unregister_code16(TAB_BACKWARD);
                        neutralize_flashing_mods();
                        return false;
                    }
                }
            }
            break;

        case ALT_COMP:
            // caps lock
            if (record->tap.count && record->event.pressed && get_mods() & MOD_MASK_SHIFT) {
                tap_code(KC_CAPS);
                return false;
            }
            break;

        case CUSTOM_KEY_RANGE:
            process_custom_key(keycode, record);
            return false;
            break;
        case ALT_DEL:
        case SFT_TILD:
        case SFT_SFT:
        case SFT_COMM:
        case CTL_COLN:
            return process_custom_taphold(keycode, record);
            break;
    }
    return true;
}

/// @brief Obliterate a line of text.
/// @param key_down Whether the key was pressed down.
/// @param deletion_keycode The deletion keycode. Either `KC_BSPC` or `KC_DEL`.
/// @param movement_keycode The movement keycode. Either `KC_HOME` or `KC_END`.
/// @return Always returns `false`.
bool obliterate_line2(bool key_down, uint8_t deletion_keycode, uint8_t movement_keycode) {
    if (key_down) {
        tap_code16(S(movement_keycode));
        register_code(deletion_keycode);
    } else {
        unregister_code(deletion_keycode);
    }
    return false;
}

/// @brief Obliterate a line of text backwards from the cursor.
/// @param key_down Whether the key was pressed down.
/// @param _ Unused.
/// @return Always returns `false`.
bool obliterate_line_backwards2(bool key_down, void* _) {
    return obliterate_line2(key_down, KC_BSPC, KC_HOME);
}

/// @brief Obliterate a line of text forwards from the cursor.
/// @param key_down Whether the key was pressed down.
/// @param _ Unused.
/// @return Always returns `false`.
bool obliterate_line_forwards2(bool key_down, void* _) {
    return obliterate_line2(key_down, KC_DEL, KC_END);
}

/// @brief Wrapper to turn on caps word.
/// @param key_down Whether the key was pressed down.
/// @param _ Unused.
/// @return Always returns `false`.
bool turn_on_caps_word2(bool key_down, void* _) {
    caps_word_on();
    return false;
}

const key_override_t Q_TO_KILL = ko_make_with_layers(MOD_MASK_GUI, KC_Q, A(KC_F4), _BASE + 1);

const key_override_t BSPC_TO_OBLITERATE = {
    .trigger = KC_BSPC,
    .trigger_mods = MOD_MASK_GUI,
    .layers = 0xFF,
    .custom_action = obliterate_line_backwards2,
    .suppressed_mods = MOD_MASK_GUI,
};

const key_override_t DEL_TO_OBLITERATE = {
    .trigger = KC_DEL,
    .trigger_mods = MOD_MASK_GUI,
    .layers = 0xFF,
    .custom_action = obliterate_line_forwards2,
    .suppressed_mods = MOD_MASK_GUI,
};
const key_override_t DEL_TO_CAPS_WORD = {
    .trigger = SFT_DEL,
    .trigger_mods = MOD_MASK_SHIFT,
    .layers = 0xFF,
    .custom_action = turn_on_caps_word2,
};

const key_override_t ESC_TO_TAB_FORWARD = ko_make_basic(MOD_MASK_ALT, KC_ESC, TAB_FORWARD);

const key_override_t DOWN_TO_ZOOM_OUT = ko_make_basic(MOD_MASK_CTRL, DOWN, C(KC_MINS));
const key_override_t DOWN_DEFAULT = ko_make_basic(0, DOWN, KC_DOWN);
const key_override_t UP_TO_ZOOM_IN = ko_make_basic(MOD_MASK_CTRL, UP, C(KC_EQL));
const key_override_t UP_DEFAULT = ko_make_basic(0, UP, KC_UP);

const key_override_t ONE_TO_A = ko_make_basic(MOD_MASK_CTRL, KC_1, C(KC_A));
const key_override_t ONE_NOSHIFT = ko_make_basic(MOD_MASK_SHIFT, KC_1, KC_1);

const key_override_t TWO_TO_S = ko_make_basic(MOD_MASK_CTRL, KC_2, C(KC_S));
const key_override_t TWO_NOSHIFT = ko_make_basic(MOD_MASK_SHIFT, KC_2, KC_2);

const key_override_t THREE_NOSHIFT = ko_make_basic(MOD_MASK_SHIFT, KC_3, KC_3);

const key_override_t FOUR_TO_F = ko_make_basic(MOD_MASK_CTRL, KC_4, C(KC_F));
const key_override_t FOUR_NOSHIFT = ko_make_basic(MOD_MASK_SHIFT, KC_4, KC_4);

const key_override_t FIVE_NOSHIFT = ko_make_basic(MOD_MASK_SHIFT, KC_5, KC_5);

const key_override_t SIX_TO_H = ko_make_basic(MOD_MASK_CTRL, KC_6, C(KC_H));
const key_override_t SIX_NOSHIFT = ko_make_basic(MOD_MASK_SHIFT, KC_6, KC_6);

const key_override_t SEVEN_TO_J = ko_make_basic(MOD_MASK_CTRL, KC_7, C(KC_J));
const key_override_t SEVEN_NOSHIFT = ko_make_basic(MOD_MASK_SHIFT, KC_7, KC_7);

const key_override_t EIGHT_NOSHIFT = ko_make_basic(MOD_MASK_SHIFT, KC_8, KC_8);

const key_override_t NINE_NOSHIFT = ko_make_basic(MOD_MASK_SHIFT, KC_9, KC_9);

const key_override_t ZERO_NOSHIFT = ko_make_basic(MOD_MASK_SHIFT, KC_0, KC_0);

const key_override_t LOW_6_TO_Z = ko_make_basic(MOD_MASK_CTRL, LOW_6, C(KC_Z));
const key_override_t LOW_6_NOSHIFT = ko_make_basic(MOD_MASK_SHIFT, LOW_6, KC_6);
const key_override_t LOW_6_DEFAULT = ko_make_basic(0, LOW_6, KC_6);

const key_override_t LOW_7_TO_X = ko_make_basic(MOD_MASK_CTRL, LOW_7, C(KC_X));
const key_override_t LOW_7_NOSHIFT = ko_make_basic(MOD_MASK_SHIFT, LOW_7, KC_7);
const key_override_t LOW_7_DEFAULT = ko_make_basic(0, LOW_7, KC_7);

const key_override_t LOW_8_TO_C = ko_make_basic(MOD_MASK_CTRL, LOW_8, C(KC_C));
const key_override_t LOW_8_NOSHIFT = ko_make_basic(MOD_MASK_SHIFT, LOW_8, KC_8);
const key_override_t LOW_8_DEFAULT = ko_make_basic(0, LOW_8, KC_8);

const key_override_t LOW_9_TO_V = ko_make_basic(MOD_MASK_CTRL, LOW_9, C(KC_V));
const key_override_t LOW_9_NOSHIFT = ko_make_basic(MOD_MASK_SHIFT, LOW_9, KC_9);
const key_override_t LOW_9_DEFAULT = ko_make_basic(0, LOW_9, KC_9);

const key_override_t LOW_0_TO_B = ko_make_basic(MOD_MASK_CTRL, LOW_0, C(KC_B));
const key_override_t LOW_0_NOSHIFT = ko_make_basic(MOD_MASK_SHIFT, LOW_0, KC_0);
const key_override_t LOW_0_DEFAULT = ko_make_basic(0, LOW_0, KC_0);

// this globally defines all key overrides to be used
const key_override_t* key_overrides[] = {
    &Q_TO_KILL,
    &BSPC_TO_OBLITERATE,
    // &DEL_TO_OBLITERATE,
    &DEL_TO_CAPS_WORD,
    &ESC_TO_TAB_FORWARD,

    &DOWN_TO_ZOOM_OUT,
    &DOWN_DEFAULT,
    &UP_TO_ZOOM_IN,
    &UP_DEFAULT,

    &ONE_TO_A,
    &ONE_NOSHIFT,
    &TWO_TO_S,
    &TWO_NOSHIFT,
    &THREE_NOSHIFT,
    &FOUR_TO_F,
    &FOUR_NOSHIFT,
    &FIVE_NOSHIFT,
    &SIX_TO_H,
    &SIX_NOSHIFT,
    &SEVEN_TO_J,
    &SEVEN_NOSHIFT,
    &EIGHT_NOSHIFT,
    &NINE_NOSHIFT,
    &ZERO_NOSHIFT,
    &LOW_6_TO_Z,
    &LOW_6_NOSHIFT,
    &LOW_6_DEFAULT,
    &LOW_7_TO_X,
    &LOW_7_NOSHIFT,
    &LOW_7_DEFAULT,
    &LOW_8_TO_C,
    &LOW_8_NOSHIFT,
    &LOW_8_DEFAULT,
    &LOW_9_TO_V,
    &LOW_9_NOSHIFT,
    &LOW_9_DEFAULT,
    &LOW_0_TO_B,
    &LOW_0_NOSHIFT,
    &LOW_0_DEFAULT,
};
