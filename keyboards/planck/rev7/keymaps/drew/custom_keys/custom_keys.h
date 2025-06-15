#pragma once
#include QMK_KEYBOARD_H
#include "../utils/mod_suppression.h"
#include "alias.h"

// -------------------------------------------------------------------------------------------------

#define CUSTOM_KEY_RANGE NK(NK_Q)... NK(NK_LAST)
#define KEYCODE_RANGE TH_DEL... TH_COLN
#define FUNCTION_RANGE TH_LAUNCH
#define NK(keycode) keycode + SAFE_RANGE

// -------------------------------------------------------------------------------------------------

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

void update_held_keycode(custom_key_t* custom_key, uint16_t keycode);
void process_custom_key(uint16_t custom_keycode, keyrecord_t* record);
bool process_custom_taphold(uint16_t custom_keycode, keyrecord_t* record);

// -------------------------------------------------------------------------------------------------

enum {
    NO_CHANGE,
    REMOVE_TRIGGER,
    REMOVE_ALL
};

// -------------------------------------------------------------------------------------------------

typedef void (*remap_fn)(custom_key_t*);

#define REMAP_OPTIONS(mod_removal_mode, exact_match, action_is_function)                           \
    {mod_removal_mode, exact_match, action_is_function}

#define REMAP_WITH_NEGATIVE_MODS_AND_OPTIONS_FN(                                                   \
    replacement_action, trigger_mods, negative_mods, mod_removal_mode, exact_match                 \
)                                                                                                  \
    {(remap_fn)replacement_action, trigger_mods, negative_mods,                                    \
     REMAP_OPTIONS(mod_removal_mode, exact_match, true)}

#define REMAP_WITH_NEGATIVE_MODS_AND_OPTIONS(                                                      \
    replacement_keycode, trigger_mods, negative_mods, mod_removal_mode, exact_match                \
)                                                                                                  \
    {&(uint16_t){replacement_keycode}, trigger_mods, negative_mods,                                \
     REMAP_OPTIONS(mod_removal_mode, exact_match, false)}

#define REMAP_WITH_NEGATIVE_MODS(replacement_keycode, trigger_mods, negative_mods)                 \
    REMAP_WITH_NEGATIVE_MODS_AND_OPTIONS(                                                          \
        replacement_keycode, trigger_mods, negative_mods, NO_CHANGE, false                         \
    )

#define REMAP_WITH_OPTIONS(replacement_keycode, trigger_mods, mod_removal_mode, exact_match)       \
    REMAP_WITH_NEGATIVE_MODS_AND_OPTIONS(                                                          \
        replacement_keycode, trigger_mods, 0, mod_removal_mode, exact_match                        \
    )

#define REMAP(replacement_keycode, trigger_mods)                                                   \
    REMAP_WITH_NEGATIVE_MODS(replacement_keycode, trigger_mods, 0)

#define CUSTOM_KEY(default_keycode, num_remaps, ...)                                               \
    {                                                                                              \
        &(uint16_t){default_keycode}, KC_NO, num_remaps, {                                         \
            __VA_ARGS__                                                                            \
        }                                                                                          \
    }

#define CUSTOM_KEY_NO_REMAP(default_keycode) {&(uint16_t){default_keycode}, 0}

#define CUSTOM_KEY_FN(default_action, num_remaps, ...)                                             \
    {                                                                                              \
        (void)(*)(custom_key_t*){default_action}, num_remaps, {                                    \
            __VA_ARGS__                                                                            \
        }                                                                                          \
    }

#define CUSTOM_KEY_FN_NO_REMAP(default_action) {(remap_fn)default_action, 0}

// -------------------------------------------------------------------------------------------------
