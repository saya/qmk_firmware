/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

//#define USE_MATRIX_I2C

/* Select hand configuration */

#define MASTER_LEFT

// Force mod-tap decision based only on tapping term...
#define IGNORE_MOD_TAP_INTERRUPT
#define TAPPING_TERM 175
//#define TAPPING_TERM_PER_KEY // See get_tapping_term().
#define COMBO_COUNT 1
#define CAPS_WORD_IDLE_TIMEOUT 0

// ...except some keys that are typically not rolled when typing should only send the tap action
// if not interrupted/rolled.
//#define HOLD_ON_OTHER_KEY_PRESS
//#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY // See get_hold_on_other_key_press().

// Send modifier on tap-and-hold rather than repeated tap-key
#define TAPPING_FORCE_HOLD

#define NO_ACTION_ONESHOT // -576 bytes
