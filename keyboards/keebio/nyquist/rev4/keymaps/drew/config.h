// Copyright 2023 Danny Nguyen (danny@keeb.io)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define SPLIT_HAND_PIN GP23

#define USB_VBUS_PIN GP18

#define SERIAL_USART_FULL_DUPLEX
#define SERIAL_USART_TX_PIN GP8
#define SERIAL_USART_RX_PIN GP9
#define SERIAL_USART_PIN_SWAP

#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 1000U

#define I2C_DRIVER I2CD0
#define I2C0_SDA_PIN GP4
#define I2C0_SCL_PIN GP5m

#define SPLIT_USB_TIMEOUT 20000

// -------------------------------------------------------------------------------------------------

// #define DYNAMIC_KEYMAP_LAYER_COUNT 5

#define TAPPING_TERM 200

#define QUICK_TAP_TERM_PER_KEY

#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY
#define PERMISSIVE_HOLD_PER_KEY
#define TAPPING_TERM_PER_KEY
// #define CHORDAL_HOLD

#define CAPS_WORD_IDLE_TIMEOUT 0

#define DUMMY_MOD_NEUTRALIZER_KEYCODE KC_RCTL
#define MODS_TO_NEUTRALIZE {MOD_BIT(KC_LALT), MOD_BIT(KC_RALT), MOD_BIT(KC_LGUI), MOD_BIT(KC_RGUI)}

// disable some features to make the code smaller
#define NO_ACTION_ONESHOT
