#pragma once

#include QMK_KEYBOARD_H
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
bool toggle_caps_word(bool key_down, void* _);

/// @brief Neutralize flashing modifiers (Alt and Super) if they are active.
static inline void neutralize_flashing_mods(void) {
    if (get_mods() & MOD_MASK_AG) {
        tap_code(DUMMY_MOD_NEUTRALIZER_KEYCODE);
    }
} // have to define this here because it is inline

/// @brief If control is held, register the control keycode. Otherwise, if shift is being held,
/// register the key without shift. Otherwise, register the key normally.
/// @param keycode The keycode being processed.
/// @param ctrl_keycode The keycode to register if control is being held.
/// @param record The current `keyrecord_t`.
/// @return Whether processing of the key should continue.
bool unshift_register_or_ctrl_fallthrough(
    uint8_t keycode, uint8_t ctrl_keycode, keyrecord_t* record
);

/// @brief Register a keycode without shift.
/// @param keycode The keycode being processed.
/// @param record The current `keyrecord_t`.
/// @return Whether processing of the key should continue.
bool unshift_register(uint8_t keycode, keyrecord_t* record);

/// @brief Trigger a key's tap action when it is held and not interrupted.
/// @param keycode The keycode being processed.
/// @param record The current `keyrecord_t`.
/// @return Whether processing of the key should continue.
bool trigger_tap_on_hold(uint8_t keycode, keyrecord_t* record);