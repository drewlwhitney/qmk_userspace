#include "custom_keys.h"
#include "../caps_word/caps_word.h"
#include "mapping.h"

void suppress_flashing_mods_needed(uint8_t mods_to_check, uint8_t active_mods) {
    if (mods_to_check & MOD_MASK_AG) {
        suppress_flashing_mods(active_mods);
    }
}

void update_held_keycode(custom_key_t* custom_key, uint16_t keycode) {
    custom_key->held_keycode = keycode;
}

void handle_caps_word(uint16_t keycode) {
    if (is_caps_word_on()) {
        if (!caps_word_press_user(keycode)) {
            caps_word_off();
        }
    }
}

void do_keycode(uint16_t keycode, custom_key_t* custom_key) {
    handle_caps_word(keycode);
    register_code16(keycode);
    update_held_keycode(custom_key, keycode);
}

void do_action(key_remap_t* remap, custom_key_t* custom_key) {
    // handle the dynamic typing of replacement_action
    if (remap->options.action_is_function) {
        void (*action)(custom_key_t*) = remap->replacement_action;
        action(custom_key);
    } else {
        uint16_t* keycode = remap->replacement_action;
        do_keycode(*keycode, custom_key);
    }
}

void register_default_keycode(custom_key_t* custom_key) {
    uint16_t* keycode = custom_key->default_action;
    do_keycode(*keycode, custom_key);
}

void run_default_fn(custom_key_t* custom_key) {
    void (*action)(custom_key_t*) = custom_key->default_action;
    action(custom_key);
}

void process_remaps(
    custom_key_t* custom_key, keyrecord_t* record, void (*default_fn)(custom_key_t*)
) {
    if (record->event.pressed) { // key down

        for (uint8_t i = 0; i < custom_key->num_remaps; i++) {

            key_remap_t* remap = &(custom_key->remaps)[i];
            key_remap_options_t* options = &remap->options;

            // determine whether there is a mod match
            bool match;
            uint8_t mods = get_mods();
            if (options->exact_match) {
                match = (mods == remap->trigger_mods);
            } else {
                match = (mods & remap->trigger_mods);
            }
            // if any of the trigger_mods are active AND none of the negative mods are active
            if (match && !(mods & remap->negative_mods)) {
                // determine if we need to remove any mods
                switch (options->mod_removal_mode) {
                    case REMOVE_TRIGGER:
                        // if Alt or GUI are in the trigger mods, suppress them
                        suppress_flashing_mods_needed(remap->trigger_mods, mods);
                        del_mods(remap->trigger_mods);
                        break;
                    case REMOVE_ALL:
                        // if Alt or GUI are active, suppress them
                        suppress_flashing_mods_needed(mods, mods);
                        clear_mods();
                        break;
                }
                // register the replacement/perform the function
                do_action(remap, custom_key);
                set_mods(mods);
                return; // do not process more remaps
            }
        }
        // if none of the remaps trigger, register the default keycode/run the default function
        default_fn(custom_key);
    } else { // key up
        unregister_code16(custom_key->held_keycode);
        neutralize_mods_on_release(); // necessary for flashing mods
    }
}

bool process_custom_taphold(uint16_t custom_keycode, keyrecord_t* record) {
    // only trigger a remap on a tap, not a hold
    if (record->tap.count) {
        // get the index from the tap-hold keycode
        uint8_t index = (custom_keycode & 0b11111111) - ((SAFE_RANGE) & 0b11111111);
        custom_key_t* custom_key = &custom_keys[index];
        switch (index) {
            case KEYCODE_RANGE:
                process_remaps(custom_key, record, register_default_keycode);
                break;
            case FUNCTION_RANGE:
                process_remaps(custom_key, record, run_default_fn);
                break;
        }
        return false;
    }
    return true;
}

void process_custom_key(uint16_t custom_keycode, keyrecord_t* record) {
    // subtract SAFE_RANGE to get an index that starts at 0
    custom_key_t* custom_key = &custom_keys[custom_keycode - SAFE_RANGE];
    process_remaps(custom_key, record, register_default_keycode);
}
