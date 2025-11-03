// TODO: possibly remove

#include "../alias.h"

bool get_chordal_hold(
    uint16_t tap_hold_keycode, keyrecord_t* tap_hold_record, uint16_t other_keycode,
    keyrecord_t* other_record
) {
    switch (tap_hold_keycode) {
        case SFT_D:
        case SFT_K: // no same hand stuff for shift
            return get_chordal_hold_default(tap_hold_record, other_record);
    }
    return true; // allow same hand stuff for everything else
}