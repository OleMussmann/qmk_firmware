/* Copyright 2015-2017 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "muse.h"

extern keymap_config_t keymap_config;

enum planck_layers {
  _NEO,
  _QWERTY,
  _GAME,
  _ADJUST,
  _LOWER,
  _RAISE,
};

enum planck_keycodes {
  NEO = SAFE_RANGE,
  QWERTY,
  GAME
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
//#define ADJUST MO(_ADJUST)
//#define LOWER MO(_LOWER)
//#define RAISE MO(_RAISE)

// Double defined keys
#define KC_CTLESC CTL_T(KC_ESC)
#define KC_TABUP LT(_RAISE, KC_TAB)
//#define KC_TABUP LT(_RAISE, KC_TAB)
#define KC_ZUP LT(_RAISE, KC_Z)
//#define KC_ZUP LT(_RAISE, KC_Z)
#define KC_SPCDWN LT(_LOWER, KC_SPC)
#define KC_LBRCDWN LT(_LOWER, KC_LBRC)

// German keycodes
#define KC_G_LBRC RALT(KC_8)
#define KC_G_RBRC RALT(KC_9)
#define KC_G_LCBR RALT(KC_7)
#define KC_G_RCBR RALT(KC_0)
#define KC_G_LT KC_NUBS
#define KC_G_GT S(KC_NUBS)
#define KC_G_BSLS RALT(KC_MINS)
#define KC_G_AT RALT(KC_Q)
#define KC_G_PIPE RALT(KC_NUBS)
#define KC_G_TILD RALT(KC_RBRC)
#define KC_G_BTK S(KC_PLUS)
#define KC_G_EUR RALT(KC_E)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Neo
 * ,-----------------------------------------------------------------------------------.
 * | Grv  |   X  |   V  |   L  |   C  |   W  |   K  |   H  |   G  |   F  |   Q  | MINS |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | TabUp|   U  |   I  |   A  |   E  |   O  |   S  |   N  |   R  |   T  |   D  | ZUp  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | LShft|LbcDwn| Scln | Quot |   P  |   Y  |   B  |   M  | Comm | Dot  |   J  | RShft|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |CtlEsc| LWin | LAlt | Lower| Lower| Raise|  SpaceDwn   | Left | Down |  Up  | Right|
 * `-----------------------------------------------------------------------------------'
 */
[_NEO] = LAYOUT_planck_grid(
    KC_GRV,    KC_X,       KC_V,    KC_L,     KC_C,      KC_W,     KC_K,      KC_H,      KC_G,    KC_F,    KC_Q,    KC_MINS,
    KC_TABUP,  KC_U,       KC_I,    KC_A,     KC_E,      KC_O,     KC_S,      KC_N,      KC_R,    KC_T,    KC_D,    KC_ZUP,
    KC_LSFT,   KC_LBRCDWN, KC_SCLN, KC_QUOT,  KC_P,      KC_Y,     KC_B,      KC_M,      KC_COMM, KC_DOT,  KC_J,    KC_RSFT,
    KC_CTLESC, KC_LGUI,    KC_LALT, LOWER, LOWER,  RAISE, KC_SPCDWN, KC_SPCDWN, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  | Enter|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | LWin | LAlt | Lower| Lower| Raise|    Space    | Left | Down |  Up  | Right|
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_grid(
    KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT ,
    KC_LCTL, KC_LGUI, KC_LALT, LOWER,   LOWER,  RAISE,   KC_SPC,  KC_SPC,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Game
 * ,-----------------------------------------------------------------------------------.
 * | Grv  |   X  |   V  |   L  |   C  |   W  |   K  |   H  |   G  |   F  |   Q  | MINS |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab  |   U  |   I  |   A  |   E  |   O  |   S  |   N  |   R  |   T  |   D  | ZUp  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | LShft|LbcDwn| Scln | Quot |   P  |   Y  |   B  |   M  | Comm | Dot  |   J  | RShft|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |CtlEsc| LWin | LAlt | Space| Space| Space|  SpaceDwn   | Left | Down |  Up  | Right|
 * `-----------------------------------------------------------------------------------'
 */
[_GAME] = LAYOUT_planck_grid(
    KC_GRV,    KC_X,       KC_V,    KC_L,     KC_C,      KC_W,     KC_K,      KC_H,      KC_G,    KC_F,    KC_Q,    KC_MINS,
    KC_TAB,    KC_U,       KC_I,    KC_A,     KC_E,      KC_O,     KC_S,      KC_N,      KC_R,    KC_T,    KC_D,    KC_ZUP,
    KC_LSFT,   KC_LBRCDWN, KC_SCLN, KC_QUOT,  KC_P,      KC_Y,     KC_B,      KC_M,      KC_COMM, KC_DOT,  KC_J,    KC_RSFT,
    KC_CTLESC, KC_LGUI,    KC_LALT, KC_SPC,   KC_SPC,    KC_SPC,   KC_SPCDWN, KC_SPCDWN, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | | Home | End  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |             | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_grid(
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,    KC_ASTR,    KC_LPRN, KC_RPRN, KC_BSPC,
    KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS,    KC_PLUS,    KC_LCBR, KC_RCBR, KC_PIPE,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  S(KC_NUHS), S(KC_NUBS), KC_HOME, KC_END,  _______,
    _______, _______, _______, _______, _______, _______, _______, _______,    KC_MNXT,    KC_VOLD, KC_VOLU, KC_MPLY
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |Pg Up |Pg Dn |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |             | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
//[_RAISE] = LAYOUT_planck_grid(
//    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
//    KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
//    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, KC_PGUP, KC_PGDN, _______,
//    _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
//),

/* NEOLower
 * ,-----------------------------------------------------------------------------------.
 * | Esc  | PgUp | Bspc | Up   | Del  | PgDn |  °   |  7   |  8   |  9   | Pscr | Bspc |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      | Home | Left | Down | Right| End  |  €   |  4   |  5   |  6   | Slck | ZUp  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      | Esc  | Tab  | Ins  | Ent  |  X   |  X   |  1   |  2   |  3   | Pause| Ent  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      0      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_grid(
    KC_ESC,  KC_PGUP, KC_BSPC, KC_UP,   KC_DEL,  KC_PGDN, KC_TILD,  KC_7, KC_8,    KC_9,    KC_PSCR, KC_BSPC,
    _______, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END,  KC_G_EUR, KC_4, KC_5,    KC_6,    KC_SLCK, _______,
    _______, KC_ESC,  KC_TAB,  KC_INS,  KC_ENT,  KC_TRNS, KC_TRNS,  KC_1, KC_2,    KC_3,    KC_PAUS, KC_ENT,
    _______, _______, _______, _______, _______, _______, KC_0,     KC_0, _______, _______, _______, _______
),

/* NEORaise
 * ,-----------------------------------------------------------------------------------.
 * |   X  |   `  |   _  |   [  |   ]  |   ^  |   !  |   <  |   >  |   =  |   &  |  X   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | TabUp|   \  |   /  |   {  |   }  |   *  |   ?  |   (  |   )  |   -  |   :  |  @   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |   #  |   $  |   |  |   ~  |   `  |   +  |   %  |   "  |   '  |   ;  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |             |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid(
    KC_TRNS, KC_PLUS,   KC_QUES, KC_G_LBRC, KC_G_RBRC, KC_GRV,   KC_EXLM,  KC_G_LT, KC_G_GT, KC_RPRN, KC_CIRC, KC_TRNS,
    _______, KC_G_BSLS, KC_AMPR, KC_G_LCBR, KC_G_RCBR, KC_RCBR,  KC_UNDS,  KC_ASTR, KC_LPRN, KC_SLSH, KC_GT,   KC_G_AT,
    _______, KC_BSLS,   KC_DLR,  KC_G_PIPE, KC_G_TILD, KC_G_BTK, KC_RBRC,  KC_PERC, KC_AT,   KC_PIPE, KC_LT,   _______,
    _______, _______,   _______, _______,   _______,   _______,  _______, _______,  _______, _______, _______, _______
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Vol+ | Next |Brght+|      |      |      |      |      |      | Pscr | NEO  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Vol- | Prev |Brght-|      |      |      |      |      |      |      |QWERTY|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Mute | Pause| Play |      |      |      |             |      |      |GAME  |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
    KC_F5, KC_MNXT, KC_BRIU, _______, _______, _______, _______, _______, _______, KC_PSCR, NEO,     _______,
    KC_VOLD, KC_MPRV, KC_BRID, _______, _______, _______, _______, _______, _______, _______, QWERTY,  _______,
    KC_MUTE, KC_MSTP, KC_MPLY, _______, _______, _______, _______, _______, _______, _______, GAME,    _______
)
};

#ifdef AUDIO_ENABLE
  float game_song[][2]     = SONG(PLOVER_SOUND);
  float game_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif

uint32_t layer_state_set_user(uint32_t state) {
  state = update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
//  state = update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
  return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // pressing both shift keys activates caps lock
  if ((get_mods() & MOD_BIT(KC_LSFT)) && (get_mods() & MOD_BIT(KC_RSFT))) {
    register_code(KC_CAPS);
    unregister_code(KC_CAPS);
  }
  switch (keycode) {
    case NEO:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_NEO);
      }
      return false;
      break;
    case QWERTY:
      if (record->event.pressed) {
        print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case GAME:
      if (record->event.pressed) {
        print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
  }
  return true;
}

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update(bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      #ifdef MOUSEKEY_ENABLE
        tap_code(KC_MS_WH_DOWN);
      #else
        tap_code(KC_PGDN);
      #endif
    } else {
      #ifdef MOUSEKEY_ENABLE
        tap_code(KC_MS_WH_UP);
      #else
        tap_code(KC_PGUP);
      #endif
    }
  }
}

void dip_update(uint8_t index, bool active) {
  switch (index) {
    case 0:
      if (active) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      break;
    case 1:
      if (active) {
        muse_mode = true;
      } else {
        muse_mode = false;
        #ifdef AUDIO_ENABLE
          stop_all_notes();
        #endif
      }
   }
}

void matrix_scan_user(void) {
  #ifdef AUDIO_ENABLE
    if (muse_mode) {
      if (muse_counter == 0) {
        uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
        if (muse_note != last_muse_note) {
          stop_note(compute_freq_for_midi_note(last_muse_note));
          play_note(compute_freq_for_midi_note(muse_note), 0xF);
          last_muse_note = muse_note;
        }
      }
      muse_counter = (muse_counter + 1) % muse_tempo;
    }
  #endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}
