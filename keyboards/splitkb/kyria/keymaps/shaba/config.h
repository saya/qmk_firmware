#pragma once

// Force mod-tap decision based only on tapping term...
#define IGNORE_MOD_TAP_INTERRUPT
#define TAPPING_TERM 200
#define TAPPING_TERM_PER_KEY // See get_tapping_term().

// ...except some keys that are typically not rolled when typing should only send the tap action
// if not interrupted/rolled.
#define HOLD_ON_OTHER_KEY_PRESS
#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY // See get_hold_on_other_key_press().

// Send modifier on tap-and-hold rather than repeated tap-key
#define TAPPING_FORCE_HOLD

// Nested taps send modifier even if below tapping term. This causes quite many misfires.
// #define PERMISSIVE_HOLD

// Save some space
#define NO_ACTION_ONESHOT // -576 bytes
