#pragma once

#include "stdbool.h"
#include "stdint.h"

/// @brief Obliterate a line of text.
/// @param key_down Whether the key was pressed down.
/// @param deletion_keycode The deletion keycode. Either `KC_BSPC` or `KC_DEL`.
/// @param movement_keycode The movement keycode. Either `KC_HOME` or `KC_END`.
/// @return Always returns `false`.
bool obliterate_line(bool key_down, uint8_t deletion_keycode, uint8_t movement_keycode);

/// @brief Obliterate a line of text backwards from the cursor.
/// @param key_down Whether the key was pressed down.
/// @param _ Unused.
/// @return Always returns `false`.
bool obliterate_line_backwards(bool key_down, void* _);

/// @brief Obliterate a line of text forwards from the cursor.
/// @param key_down Whether the key was pressed down.
/// @param _ Unused.
/// @return Always returns `false`.
bool obliterate_line_forwards(bool key_down, void* _);

/// @brief Wrapper to turn on caps word.
/// @param key_down Whether the key was pressed down.
/// @param _ Unused.
/// @return Always returns `false`.
bool turn_on_caps_word(bool key_down, void* _);

/// @brief Neutralize flashing modifiers (Alt and Super) if they are active.
static inline void neutralize_flashing_mods(void) {
    if (get_mods() & MOD_MASK_AG) {
        tap_code(DUMMY_MOD_NEUTRALIZER_KEYCODE);
    }
} // have to define this here because it is inline