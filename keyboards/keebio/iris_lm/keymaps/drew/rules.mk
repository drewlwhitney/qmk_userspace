BOOTLOADER = stm32-dfu

SRC += caps_word/caps_word.c
SRC += tap_dance/tap_dance.c
SRC += combos/combos.c
SRC += taphold/taphold_options.c
# SRC += utils/utils.c

# VIA_ENABLE = yes
LTO_ENABLE = yes

CAPS_WORD_ENABLE = yes

# CONSOLE_ENABLE = yes

TAP_DANCE_ENABLE = yes
KEY_OVERRIDE_ENABLE = yes
COMBO_ENABLE = yes

NKRO_ENABLE = yes