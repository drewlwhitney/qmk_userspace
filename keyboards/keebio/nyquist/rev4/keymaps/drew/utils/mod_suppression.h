#pragma once
#include QMK_KEYBOARD_H

void trigger_dummy_key(uint8_t mods);
void suppress_flashing_mods(uint8_t mods);
void neutralize_mods_on_release(void);
void tap_code16_suppress(uint16_t keycode, uint8_t mods);
void register_code16_suppress(uint16_t keycode, uint8_t mods);