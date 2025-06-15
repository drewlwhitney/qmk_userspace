#pragma once

// stuff I added
#define MAX_REMAPS_PER_CUSTOM_KEY 2
// end stuff I added

#define TAPPING_TERM 200

#define QUICK_TAP_TERM_PER_KEY

#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY
#define PERMISSIVE_HOLD_PER_KEY
#define TAPPING_TERM_PER_KEY

#define CAPS_WORD_IDLE_TIMEOUT 0

#define DUMMY_MOD_NEUTRALIZER_KEYCODE KC_RCTL
#define MODS_TO_NEUTRALIZE {MOD_BIT(KC_LALT), MOD_BIT(KC_RALT), MOD_BIT(KC_LGUI), MOD_BIT(KC_RGUI)}

// disable some features to make the code smaller
#define NO_ACTION_ONESHOT

// delete later; tap dance
#define TAPPING_TERM_PER_KEY
#define DYNAMIC_KEYMAP_LAYER_COUNT 6