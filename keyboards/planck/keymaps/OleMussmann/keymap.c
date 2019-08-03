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
  _NEO_NEO,
  _NEO_DE,
  _NEO_US,
  _NEO_GAME,
  _DE_GAME,
  _US_GAME,
  _DE,
  _US,
  _LOWER,
  _NEO_RAISE,
  _DE_RAISE,
  _US_RAISE,
  _ADJUST
};

enum planck_keycodes {
  NEO_NEO = SAFE_RANGE,
  NEO_DE,
  NEO_US,
  NEO_GAME,
  DE_GAME,
  US_GAME,
  DE,
  US,
  N_GRAV,
  N_UNDS,
  N_LBRC,
  N_RBRC,
  N_CIRC,
  N_EXLM,
  N_LT,
  N_GT,
  N_EQL,
  N_AMP,
  N_BSLS,
  N_SLSH,
  N_LCBR,
  N_RCBR,
  N_ASTR,
  N_QUES,
  N_LPRN,
  N_RPRN,
  N_MINS,
  N_COLN,
  N_AT,
  N_HASH,
  N_DLR,
  N_PIPE,
  N_TILD,
  N_GRV,
  N_PLUS,
  N_PERC,
  N_DQT,
  N_QUOT,
  N_SCLN
};

#define NR MO(_NEO_RAISE)
#define DR MO(_DE_RAISE)
#define UR MO(_US_RAISE)
#define LOWER MO(_LOWER)

// Double defined keys
#define KC_CTLESC CTL_T(KC_ESC)

#define KC_TBUPN LT(_NEO_RAISE, KC_TAB)
#define KC_TBUPD LT(_DE_RAISE, KC_TAB)
#define KC_TBUPU LT(_US_RAISE, KC_TAB)

#define KC_QUUPN LT(_NEO_RAISE, KC_QUOT)
#define KC_ZUPD LT(_DE_RAISE, KC_Z)
#define KC_BSUPD LT(_DE_RAISE, KC_BSLS)
#define KC_YUPU LT(_US_RAISE, KC_Y)
#define KC_QUUPU LT(_US_RAISE, KC_QUOT)

#define KC_SDOWN LT(_LOWER, KC_SPC)
#define KC_ZDOWN LT(_LOWER, KC_Z)
#define KC_LBDWN LT(_LOWER, KC_LBRC)


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
//#define KC_G_EUR RALT(KC_E)

// NEO keycodes
#define KC_N_DEG S(KC_1)
#define KC_N_EUR S(KC_7)

// Macros
#define KC_COPY LCTL(KC_C)
#define KC_NCOPY LCTL(KC_R)
#define KC_CPUSR LCTL(KC_B)
#define KC_NCPUS LCTL(KC_N)
#define KC_PASTE LCTL(KC_V)
#define KC_NPSTE LCTL(KC_W)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* NEO keyboard on system NEO layout
 *
 * what the system sees
 *
 * ,-----------------------------------------------------------------------------------.
 * | Grv  |  Q   |  W   |  E   |  R   |  T   |  Y   |  U   |  I   |  O   |  P   | LBRC |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | TabUp|  A   |  S   |  D   |  F   |  G   |  H   |  J   |  K   |  L   | SCLN | 'Up  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | LShft| ZDwn |  X   |  C   |  V   |  B   |  N   |  M   | Comm | Dot  | SLSH | RShft|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |CtlEsc| LWin | LAlt | Copy |Cpyusr| Paste|  SpaceDwn   | Left | Down |  Up  | Right|
 * `-----------------------------------------------------------------------------------'
 *
 * what the user sees
 *
 * ,-----------------------------------------------------------------------------------.
 * | Grv  |  X   |  V   |  L   |  C   |  W   |  K   |  H   |  G   |  F   |  Q   |  ß   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | TabUp|  U   |  I   |  A   |  E   |  O   |  S   |  N   |  R   |  T   |  D   | YUp  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | LShft| ÜDwn |  Ö   |  Ä   |  P   |  Z   |  B   |  M   |  ,   |  .   |  J   | RShft|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |CtlEsc| LWin | LAlt | Copy |Cpyusr| Paste|  SpaceDwn   | Left | Down |  Up  | Right|
 * `-----------------------------------------------------------------------------------'
 */
[_NEO_NEO] = LAYOUT_planck_grid(
    KC_GRV,     KC_Q,     KC_W,    KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,    KC_O,    KC_P,    KC_LBRC,
    KC_TBUPN,  KC_A,     KC_S,    KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,    KC_L,    KC_SCLN, KC_QUUPN,
    KC_LSFT,    KC_ZDOWN, KC_X,    KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
    KC_CTLESC,  KC_LGUI,  KC_LALT, KC_NCOPY, KC_NCPUS, KC_NPSTE, KC_SDOWN, KC_SDOWN, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* NEO keyboard on system NEO layout - GAME mode
 *
 * what the system sees
 *
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |  Q   |  W   |  E   |  R   |  T   |  Y   |  U   |  I   |  O   |  P   | LBRC |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Raise|  A   |  S   |  D   |  F   |  G   |  H   |  J   |  K   |  L   | SCLN | 'Up  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | LShft| ZUp  |  X   |  C   |  V   |  B   |  N   |  M   | Comm | Dot  | SLSH | RShft|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |CtlEsc| LWin | LAlt | Space| Space| Space|  SpaceDwn   | Left | Down |  Up  | Right|
 * `-----------------------------------------------------------------------------------'
 *
 * what the user sees
 *
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |  X   |  V   |  L   |  C   |  W   |  K   |  H   |  G   |  F   |  Q   |  ß   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Raise|  U   |  I   |  A   |  E   |  O   |  S   |  N   |  R   |  T   |  D   | YUp  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | LShft| ÜDwn |  Ö   |  Ä   |  P   |  Z   |  B   |  M   |  ,   |  .   |  J   | RShft|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |CtlEsc| LWin | LAlt | Space| Space| Space|  SpaceDwn   | Left | Down |  Up  | Right|
 * `-----------------------------------------------------------------------------------'
 */
[_NEO_GAME] = LAYOUT_planck_grid(
    KC_TAB,    KC_Q,     KC_W,    KC_E,   KC_R,   KC_T,   KC_Y,     KC_U,     KC_I,    KC_O,    KC_P,    KC_LBRC,
    NR,       KC_A,     KC_S,    KC_D,   KC_F,   KC_G,   KC_H,     KC_J,     KC_K,    KC_L,    KC_SCLN, KC_QUUPN,
    KC_LSFT,   KC_ZDOWN, KC_X,    KC_C,   KC_V,   KC_B,   KC_N,     KC_M,     KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
    KC_CTLESC, KC_LGUI,  KC_LALT, KC_SPC, KC_SPC, KC_SPC, KC_SDOWN, KC_SDOWN, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* NEO keyboard on system DE layout
 *
 * what the system sees
 *
 * ,-----------------------------------------------------------------------------------.
 * | Grv  |  X   |  V   |  L   |  C   |  W   |  K   |  H   |  G   |  F   |  Q   | MINS |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | TabUp|  U   |  I   |  A   |  E   |  O   |  S   |  N   |  R   |  T   |  D   | ZUp  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | LShft|LbcDwn| Scln | Quot |  P   |  Y   |  B   |  M   | Comm | Dot  |  J   | RShft|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |CtlEsc| LWin | LAlt | Copy |Cpyusr| Paste|  SpaceDwn   | Left | Down |  Up  | Right|
 * `-----------------------------------------------------------------------------------'
 *
 * what the user sees
 *
 * ,-----------------------------------------------------------------------------------.
 * | Grv  |  X   |  V   |  L   |  C   |  W   |  K   |  H   |  G   |  F   |  Q   |  ß   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | TabUp|  U   |  I   |  A   |  E   |  O   |  S   |  N   |  R   |  T   |  D   | ZUp  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | LShft| ÜDwn |  Ö   |  Ä   |  P   |  Y   |  B   |  M   |  ,   |  .   |  J   | RShft|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |CtlEsc| LWin | LAlt | Copy |Cpyusr| Paste|  SpaceDwn   | Left | Down |  Up  | Right|
 * `-----------------------------------------------------------------------------------'
 */
[_NEO_DE] = LAYOUT_planck_grid(
    KC_GRV,     KC_X,     KC_V,    KC_L,    KC_C,     KC_W,     KC_K,     KC_H,     KC_G,    KC_F,    KC_Q,   KC_MINS,
    KC_TBUPD,  KC_U,     KC_I,    KC_A,    KC_E,     KC_O,     KC_S,     KC_N,     KC_R,    KC_T,    KC_D,   KC_ZUPD,
    KC_LSFT,    KC_LBDWN, KC_SCLN, KC_QUOT, KC_P,     KC_Y,     KC_B,     KC_M,     KC_COMM, KC_DOT,  KC_J,   KC_RSFT,
    KC_CTLESC,  KC_LGUI,  KC_LALT, KC_COPY, KC_CPUSR, KC_PASTE, KC_SDOWN, KC_SDOWN, KC_LEFT, KC_DOWN, KC_UP,  KC_RGHT
),

/* NEO keyboard on system US layout
 *
 * what the system sees
 *
 * ,-----------------------------------------------------------------------------------.
 * | Grv  |  X   |  V   |  L   |  C   |  W   |  K   |  H   |  G   |  F   |  Q   | SS   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | TabUp|  U   |  I   |  A   |  E   |  O   |  S   |  N   |  R   |  T   |  D   | YUp  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | LShft| Raise|      |      |  P   |  Y   |  B   |  M   | Comm | Dot  |  J   | RShft|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |CtlEsc| LWin | LAlt | Copy |Cpyusr| Paste|  SpaceDwn   | Left | Down |  Up  | Right|
 * `-----------------------------------------------------------------------------------'
 *
 * what the user sees
 *
 * ,-----------------------------------------------------------------------------------.
 * | Grv  |  X   |  V   |  L   |  C   |  W   |  K   |  H   |  G   |  F   |  Q   | MINS |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | TabUp|  U   |  I   |  A   |  E   |  O   |  S   |  N   |  R   |  T   |  D   | ZUp  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | LShft| Raise|      |      |  P   |  Y   |  B   |  M   | Comm | Dot  |  J   | RShft|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |CtlEsc| LWin | LAlt | Copy |Cpyusr| Paste|  SpaceDwn   | Left | Down |  Up  | Right|
 * `-----------------------------------------------------------------------------------'
 */
[_NEO_US] = LAYOUT_planck_grid(
    KC_GRV,     KC_X,    KC_V,    KC_L,    KC_C,     KC_W,     KC_K,     KC_H,     KC_G,    KC_F,    KC_Q,   KC_NO,
    KC_TBUPU,  KC_U,    KC_I,    KC_A,    KC_E,     KC_O,     KC_S,     KC_N,     KC_R,    KC_T,    KC_D,   KC_YUPU,
    KC_LSFT,    LOWER,      KC_NO,   KC_NO,   KC_P,     KC_Z,     KC_B,     KC_M,     KC_COMM, KC_DOT,  KC_J,   KC_RSFT,
    KC_CTLESC,  KC_LGUI, KC_LALT, KC_COPY, KC_CPUSR, KC_PASTE, KC_SDOWN, KC_SDOWN, KC_LEFT, KC_DOWN, KC_UP,  KC_RGHT
),

/* DE keyboard on system DE layout
 *
 * what the system sees
 *
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | TabUp|   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ]  | \Up  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | LShft| ZDown|   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  | Enter|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | LWin | LAlt | Copy |Cpyusr| Paste|  SpaceDwn   | Left | Down |  Up  | Right|
 * `-----------------------------------------------------------------------------------'
 *
 * what the user sees
 *
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Z  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | TabUp|   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   +  | #Up  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | LShft| YDown|   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   -  | Enter|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | LWin | LAlt | Copy |Cpyusr| Paste|  SpaceDwn   | Left | Down |  Up  | Right|
 * `-----------------------------------------------------------------------------------'
 */
[_DE] = LAYOUT_planck_grid(
    KC_ESC,   KC_Q,     KC_W,    KC_E,    KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_TBUPD, KC_A,     KC_S,    KC_D,    KC_F,     KC_G,     KC_H,     KC_J,     KC_K,    KC_L,    KC_RBRC, KC_BSUPD,
    KC_LSFT,  KC_ZDOWN, KC_X,    KC_C,    KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
    KC_LCTL,  KC_LGUI,  KC_LALT, KC_COPY, KC_CPUSR, KC_PASTE, KC_SDOWN,  KC_SDOWN,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* DE keyboard on system DE layout - GAME mode
 *
 * what the system sees
 *
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Raise|   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ]  | \Up  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | LShft| ZDown|   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  | Enter|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | LWin | LAlt | Space| Space| Space|  SpaceDwn   | Left | Down |  Up  | Right|
 * `-----------------------------------------------------------------------------------'
 *
 * what the user sees
 *
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Z  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Raise|   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   +  | #Up  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | LShft| YDown|   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   -  | Enter|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | LWin | LAlt | Space| Space| Space|  SpaceDwn   | Left | Down |  Up  | Right|
 * `-----------------------------------------------------------------------------------'
 */
[_DE_GAME] = LAYOUT_planck_grid(
    KC_TAB,    KC_Q,     KC_W,    KC_E,   KC_R,   KC_T,   KC_Y,     KC_U,     KC_I,    KC_O,    KC_P,    KC_BSPC,
    DR,        KC_A,     KC_S,    KC_D,   KC_F,   KC_G,   KC_H,     KC_J,     KC_K,    KC_L,    KC_SCLN, KC_BSUPD,
    KC_LSFT,   KC_ZDOWN, KC_X,    KC_C,   KC_V,   KC_B,   KC_N,     KC_M,     KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
    KC_CTLESC, KC_LGUI,  KC_LALT, KC_SPC, KC_SPC, KC_SPC, KC_SDOWN,  KC_SDOWN,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* US keyboard on system US layout
 *
 * what the system sees
 *
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | TabUp|   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  | 'Up  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | LShft| ZDown|   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  | Enter|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | LWin | LAlt | Copy |Cpyusr| Paste|  SpaceDwn   | Left | Down |  Up  | Right|
 * `-----------------------------------------------------------------------------------'
 *
 * what the user sees
 *
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | TabUp|   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  | 'Up  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | LShft| ZDown|   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  | Enter|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | LWin | LAlt | Copy |Cpyusr| Paste|  SpaceDwn   | Left | Down |  Up  | Right|
 * `-----------------------------------------------------------------------------------'
 */
[_US] = LAYOUT_planck_grid(
    KC_ESC,   KC_Q,     KC_W,    KC_E,    KC_R,     KC_T,     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_TBUPU, KC_A,     KC_S,    KC_D,    KC_F,     KC_G,     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUUPU,
    KC_LSFT,  KC_ZDOWN, KC_X,    KC_C,    KC_V,     KC_B,     KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
    KC_LCTL,  KC_LGUI,  KC_LALT, NEO_NEO, KC_CPUSR, KC_PASTE, KC_SDOWN, KC_SDOWN, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* US keyboard on system US layout - GAME mode
 *
 * what the system sees
 *
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Raise|   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  | 'Up  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | LShft| ZDown|   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  | Enter|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | LWin | LAlt | Space| Space| Space|  SpaceDwn   | Left | Down |  Up  | Right|
 * `-----------------------------------------------------------------------------------'
 *
 * what the user sees
 *
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Raise|   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  | 'Up  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | LShft| ZDown|   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  | Enter|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | LWin | LAlt | Space| Space| Space|  SpaceDwn   | Left | Down |  Up  | Right|
 * `-----------------------------------------------------------------------------------'
 */
[_US_GAME] = LAYOUT_planck_grid(
    KC_TAB,    KC_Q,     KC_W,    KC_E,   KC_R,   KC_T,   KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    UR,        KC_A,     KC_S,    KC_D,   KC_F,   KC_G,   KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUUPU,
    KC_LSFT,   KC_ZDOWN, KC_X,    KC_C,   KC_V,   KC_B,   KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
    KC_CTLESC, KC_LGUI,  KC_LALT, KC_SPC, KC_SPC, KC_SPC, KC_SDOWN, KC_SDOWN, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* LOWER
 *
 * what the system sees
 *
 * ,-----------------------------------------------------------------------------------.
 * | Esc  | PgUp | Bspc | Up   | Del  | PgDn |  N°  |  7   |  8   |  9   | Pscr | Bspc |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  | Home | Left | Down | Right| End  |  N€  |  4   |  5   |  6   | Slck |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Esc  | Tab  | Ins  | Ent  |      |      |  1   |  2   |  3   | Pause| Ent  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      0      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 *
 * what the user sees (on NEO layout; `°` and `€` will differ depending on the host layout)
 *
 * ,-----------------------------------------------------------------------------------.
 * | Esc  | PgUp | Bspc | Up   | Del  | PgDn |  °   |  7   |  8   |  9   | Pscr | Bspc |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  | Home | Left | Down | Right| End  |  €   |  4   |  5   |  6   | Slck |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Esc  | Tab  | Ins  | Ent  |      |      |  1   |  2   |  3   | Pause| Ent  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      0      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_grid(
    KC_ESC,  KC_PGUP, KC_BSPC, KC_UP,   KC_DEL,  KC_PGDN, KC_N_DEG, KC_7, KC_8,    KC_9,    KC_PSCR, KC_BSPC,
    KC_TAB,  KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END,  KC_N_EUR, KC_4, KC_5,    KC_6,    KC_SLCK, _______,
    _______, KC_ESC,  KC_TAB,  KC_INS,  KC_ENT,  KC_TRNS, KC_TRNS,  KC_1, KC_2,    KC_3,    KC_PAUS, KC_ENT,
    _______, _______, _______, _______, _______, _______, KC_0,     KC_0, _______, _______, _______, _______
),

/* NEO keyboard on system NEO layout RAISE
 *
 * what the system sees
 *
 * ,-----------------------------------------------------------------------------------.
 * |      |   `  |   _  |   [  |   ]  |   ^  |   !  |   <  |   >  |   =  |   &  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   \  |   /  |   {  |   }  |   *  |   ?  |   (  |   )  |   -  |   :  |  @   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   #  |   $  |   |  |   ~  |   `  |   +  |   %  |   "  |   '  |   ;  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |             |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 *
 * what the user sees
 *
 * ,-----------------------------------------------------------------------------------.
 * |      |   `  |   _  |   [  |   ]  |   ^  |   !  |   <  |   >  |   =  |   &  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   \  |   /  |   {  |   }  |   *  |   ?  |   (  |   )  |   -  |   :  |  @   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   #  |   $  |   |  |   ~  |   `  |   +  |   %  |   "  |   '  |   ;  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |             |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_NEO_RAISE] = LAYOUT_planck_grid(
    KC_TRNS, N_GRAV,  N_UNDS,  N_LBRC,  N_RBRC,  N_CIRC,  N_EXLM,  N_LT,    N_GT,    N_EQL,   N_AMP,   KC_TRNS,
    _______, N_BSLS,  N_SLSH,  N_LCBR,  N_RCBR,  N_ASTR,  N_QUES,  N_LPRN,  N_RPRN,  N_MINS,  N_COLN,  N_AT,
    _______, N_HASH,  N_DLR,   N_PIPE,  N_TILD,  N_GRAV,  N_PLUS,  N_PERC,  N_DQT,   N_QUOT,  N_SCLN,  _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* system DE layout RAISE
 *
 * what the system sees
 *
 * ,-----------------------------------------------------------------------------------.
 * |      |   +  |   _  |   ?  |  G]  |   ^  |   !  |  G<  |  G>  |   )  |   ^  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  G\  |   &  |  G{  |  G}  |   }  |   _  |   *  |   (  |   /  |   >  | G@   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   \  |   $  |  G|  |  G~  |  G`  |   ]  |   %  |   @  |   |  |   <  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |             |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 *
 * what the user sees
 *
 * ,-----------------------------------------------------------------------------------.
 * |      |   `  |   _  |   [  |   ]  |   ^  |   !  |   <  |   >  |   =  |   &  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   \  |   /  |   {  |   }  |   *  |   ?  |   (  |   )  |   -  |   :  |  @   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   #  |   $  |   |  |   ~  |   `  |   +  |   %  |   "  |   '  |   ;  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |             |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_DE_RAISE] = LAYOUT_planck_grid(
    KC_TRNS, KC_PLUS,   KC_QUES, KC_G_LBRC, KC_G_RBRC, KC_GRV,   KC_EXLM,  KC_G_LT, KC_G_GT, KC_RPRN, KC_CIRC, KC_TRNS,
    _______, KC_G_BSLS, KC_AMPR, KC_G_LCBR, KC_G_RCBR, KC_RCBR,  KC_UNDS,  KC_ASTR, KC_LPRN, KC_SLSH, KC_GT,   KC_G_AT,
    _______, KC_BSLS,   KC_DLR,  KC_G_PIPE, KC_G_TILD, KC_G_BTK, KC_RBRC,  KC_PERC, KC_AT,   KC_PIPE, KC_LT,   _______,
    _______, _______,   _______, _______,   _______,   _______,  _______, _______,  _______, _______, _______, _______
),

/* system US layout RAISE
 *
 * what the system sees
 *
 * ,-----------------------------------------------------------------------------------.
 * |      |   `  |   _  |   [  |   ]  |   ^  |   !  |   <  |   >  |   =  |   &  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   \  |   /  |   {  |   }  |   *  |   ?  |   (  |   )  |   -  |   :  |  @   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   #  |   $  |   |  |   ~  |   `  |   +  |   %  |   "  |   '  |   ;  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |             |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 *
 * what the user sees
 *
 * ,-----------------------------------------------------------------------------------.
 * |      |   `  |   _  |   [  |   ]  |   ^  |   !  |   <  |   >  |   =  |   &  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   \  |   /  |   {  |   }  |   *  |   ?  |   (  |   )  |   -  |   :  |  @   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   #  |   $  |   |  |   ~  |   `  |   +  |   %  |   "  |   '  |   ;  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |             |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_US_RAISE] = LAYOUT_planck_grid(
    KC_TRNS, KC_GRV,  KC_UNDS, KC_LBRC, KC_RBRC, KC_CIRC, KC_EXLM, KC_LT,   KC_GT,   KC_EQL,  KC_AMPR, KC_TRNS,
    _______, KC_BSLS, KC_SLSH, KC_LCBR, KC_RCBR, KC_ASTR, KC_QUES, KC_LPRN, KC_RPRN, KC_MINS, KC_COLN, KC_AT,
    _______, KC_HASH, KC_DLR,  KC_PIPE, KC_TILD, KC_GRV,  KC_PLUS, KC_PERC, KC_DQT,  KC_QUOT, KC_SCLN, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* ADJUST (LOWER + RAISE)
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Vol+ | Next |Brght+| Pscr |      |      |      |NEO_US|NEO_DE|NEOGAM| NEO  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Vol- | Prev |Brght-|      |      |      |      |      |      |DEGAME| DE   |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Mute | Pause| Play |      |      |      |             |      |USGAME| US   |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,  KC_F12,
    KC_VOLU, KC_MNXT, KC_BRIU, KC_PSCR, _______, _______, _______, NEO_US,  NEO_DE,  NEO_GAME, NEO_NEO, _______,
    KC_VOLD, KC_MPRV, KC_BRID, _______, _______, _______, _______, _______, _______, DE_GAME,  DE,      _______,
    KC_MUTE, KC_MSTP, KC_MPLY, _______, _______, _______, _______, _______, _______, US_GAME,  US,      _______
)
};

//void keyboard_post_init_user(void) {
//  // Customise these values to desired behaviour
//  debug_enable=true;
//  debug_matrix=true;
//  debug_keyboard=true;
//  //debug_mouse=true;
//}

uint32_t layer_state_set_user(uint32_t state) {
  if (
      ( layer_state_cmp(state, _LOWER) && layer_state_cmp(state, _NEO_RAISE ) ) ||
      ( layer_state_cmp(state, _LOWER) && layer_state_cmp(state, _DE_RAISE ) ) ||
      ( layer_state_cmp(state, _LOWER) && layer_state_cmp(state, _US_RAISE ) ) ) {
    return state | (1UL<<_ADJUST);
  } else {
    return state & ~(1UL<<_ADJUST);
  }
}

void neo_layer_3(uint16_t keycode, keyrecord_t *record) {
      if (record->event.pressed) {
        register_code(KC_CAPS);
        tap_code(keycode);
        unregister_code(KC_CAPS);
      }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // pressing both shift keys activates caps lock
  if ((get_mods() & MOD_BIT(KC_LSFT)) && (get_mods() & MOD_BIT(KC_RSFT))) {
//    print("caps\n");
    register_code(KC_CAPS);
    unregister_code(KC_CAPS);
  }
  switch (keycode) {
    case NEO_NEO:
      if (record->event.pressed) {
//        print("neo on neo\n");
        set_single_persistent_default_layer(_NEO_NEO);
      }
      return false;
      break;
    case NEO_DE:
      if (record->event.pressed) {
//        print("neo on de\n");
        set_single_persistent_default_layer(_NEO_DE);
      }
      return false;
      break;
    case NEO_US:
      if (record->event.pressed) {
//        print("neo on us\n");
        set_single_persistent_default_layer(_NEO_US);
      }
      return false;
      break;
    case DE:
      if (record->event.pressed) {
//        print("de\n");
        set_single_persistent_default_layer(_DE);
      }
      return false;
      break;
    case US:
      if (record->event.pressed) {
//        print("us\n");
        set_single_persistent_default_layer(_US);
      }
      return false;
      break;
    case NEO_GAME:
      if (record->event.pressed) {
//        print("neo game\n");
        set_single_persistent_default_layer(_NEO_GAME);
      }
      return false;
      break;
    case DE_GAME:
      if (record->event.pressed) {
//        print("de game\n");
        set_single_persistent_default_layer(_DE_GAME);
      }
      return false;
      break;
    case US_GAME:
      if (record->event.pressed) {
//        print("us game\n");
        set_single_persistent_default_layer(_US_GAME);
      }
      return false;
      break;
// NEO keys      
    case N_GRAV:
      neo_layer_3(KC_B, record);
      break;
    case N_UNDS:
      neo_layer_3(KC_W, record);
      break;
    case N_LBRC:
      neo_layer_3(KC_E, record);
      break;
    case N_RBRC:
      neo_layer_3(KC_R, record);
      break;
    case N_CIRC:
      neo_layer_3(KC_T, record);
      break;
    case N_EXLM:
      neo_layer_3(KC_Y, record);
      break;
    case N_LT:
      neo_layer_3(KC_U, record);
      break;
    case N_GT:
      neo_layer_3(KC_I, record);
      break;
    case N_EQL:
      neo_layer_3(KC_O, record);
      break;
    case N_AMP:
      neo_layer_3(KC_P, record);
      break;
    case N_BSLS:
      neo_layer_3(KC_A, record);
      break;
    case N_SLSH:
      neo_layer_3(KC_S, record);
      break;
    case N_LCBR:
      neo_layer_3(KC_D, record);
      break;
    case N_RCBR:
      neo_layer_3(KC_F, record);
      break;
    case N_ASTR:
      neo_layer_3(KC_G, record);
      break;
    case N_QUES:
      neo_layer_3(KC_H, record);
      break;
    case N_LPRN:
      neo_layer_3(KC_J, record);
      break;
    case N_RPRN:
      neo_layer_3(KC_K, record);
      break;
    case N_MINS:
      neo_layer_3(KC_L, record);
      break;
    case N_COLN:
      neo_layer_3(KC_SCLN, record);
      break;
    case N_AT:
      neo_layer_3(KC_QUOT, record);
      break;
    case N_HASH:
      neo_layer_3(KC_Z, record);
      break;
    case N_DLR:
      neo_layer_3(KC_X, record);
      break;
    case N_PIPE:
      neo_layer_3(KC_C, record);
      break;
    case N_TILD:
      neo_layer_3(KC_V, record);
      break;
    case N_GRV:
      neo_layer_3(KC_B, record);
      break;
    case N_PLUS:
      neo_layer_3(KC_N, record);
      break;
    case N_PERC:
      neo_layer_3(KC_M, record);
      break;
    case N_DQT:
      neo_layer_3(KC_COMM, record);
      break;
    case N_QUOT:
      neo_layer_3(KC_DOT, record);
      break;
    case N_SCLN:
      neo_layer_3(KC_SLSH, record);
      break;
  }
  return true;
}
