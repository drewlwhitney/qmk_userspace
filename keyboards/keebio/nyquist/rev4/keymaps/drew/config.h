// Copyright 2023 Danny Nguyen (danny@keeb.io)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#pragma once

#define USB_VBUS_PIN GP18

#define SERIAL_USART_FULL_DUPLEX
#define SERIAL_USART_TX_PIN GP8
#define SERIAL_USART_RX_PIN GP9
#define SERIAL_USART_PIN_SWAP

#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 1000U

// -------------------------------------------------------------------------------------------------

#define TAPPING_TERM 200

// tap-hold
#define QUICK_TAP_TERM_PER_KEY
#define HOLD_ON_OTHER_KEY_PRESS
// #define HOLD_ON_OTHER_KEY_PRESS_PER_KEY
// #define PERMISSIVE_HOLD_PER_KEY

// combos
#define COMBO_PROCESS_KEY_RELEASE
#define COMBO_PROCESS_KEY_REPRESS
#define COMBO_TERM_PER_COMBO
#define COMBO_MUST_HOLD_PER_COMBO

#define CAPS_WORD_IDLE_TIMEOUT 0

#define DUMMY_MOD_NEUTRALIZER_KEYCODE KC_RCTL
#define MODS_TO_NEUTRALIZE {MOD_BIT(KC_LALT), MOD_BIT(KC_RALT), MOD_BIT(KC_LGUI), MOD_BIT(KC_RGUI)}

#define NKRO_DEFAULT_ON true