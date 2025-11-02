#pragma once
#include QMK_KEYBOARD_H
#include "../alias.h"
#include "../layers.h"

#define CUSTOM_KEY_RANGE NK(NK_Q)... NK(NK_LAST)
#define KEYCODE_RANGE TH_DEL... TH_COLN
#define FUNCTION_RANGE TH_LAUNCH
#define NK(keycode) keycode + SAFE_RANGE

typedef struct {
    // 0 = do not change current mods, 1 = remove just trigger mods, 2 = remove all mods
    uint8_t mod_removal_mode;
    // true = mods must match exactly, false = only one match is required
    bool exact_match;
    // whether replacement_action is a function or a keycode
    bool action_is_function;
} key_remap_options_t;

typedef struct {
    void* replacement_action;
    uint8_t trigger_mods;
    uint8_t negative_mods;
    key_remap_options_t options;
} key_remap_t;

typedef struct {
    void* default_action; // the action to perform if none of the remaps trigger
    uint16_t held_keycode; // the currently held keycode
    uint8_t num_remaps; // how many entries are in remaps[]
    // an array containing remaps that dictate how the key is handles based on the mod state
    key_remap_t remaps[MAX_REMAPS_PER_CUSTOM_KEY];
} custom_key_t;
// -------------------------------------------------------------------------------------------------

// -------------------------------------------------------------------------------------------------

// clang-format off
// NK stands for "new key"
enum custom_keycodes {
    // _BASE layer
    NK_Q,
    // _NUM layer
    NK_COLN,
    NK_MINS_NUM,
    NK_1,
    NK_2,
    NK_3,
    NK_4,
    NK_5,
    NK_6,
    NK_7,
    NK_8,
    NK_9,
    NK_0,
    NK_6_LOW,
    NK_7_LOW,
    NK_8_LOW,
    NK_9_LOW,
    NK_0_LOW,
    // _NAV layer
    NK_BSLS, // backslash
    NK_LBRC, // [
    NK_RBRC, // ]
    NK_MINS_NAV, // -
    NK_EQL, // =
    NK_GRV, // `
    NK_PIPE,
    NK_LCBR,
    NK_RCBR,
    NK_UNDS,
    NK_PLUS,
    NK_F2,
    NK_DLR,
    NK_HOME,
    NK_END,

    // multiple layers
    NK_CIRC,
    NK_AMPR,
    NK_ASTR,
    NK_RPRN,
    NK_ESC,
    NK_UP,
    NK_DOWN,
    NK_BSPC,

    // tap-hold
        // default function
        TH_LAUNCH,
        // default keycode
        TH_DEL,
        TH_RALT,
        TH_TILD,
        TH_LSFT,
        TH_COMM,
        TH_COLN,
        TH_SPC,

    // this is always last
    NK_LAST,
};
// clang-format on

// -------------------------------------------------------------------------------------------------

extern custom_key_t custom_keys[];

// -------------------------------------------------------------------------------------------------
