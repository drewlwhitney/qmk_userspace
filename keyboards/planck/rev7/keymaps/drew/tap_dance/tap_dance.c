#include "tap_dance.h"
#include "../common.h"
#include "../custom_keys/alias.h"

tap_dance_action_t tap_dance_actions[] = {
    [TD_CAD_LOCK] = ACTION_TAP_DANCE_DOUBLE(CAD, LOCK),
};
