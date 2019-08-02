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
  _NEO_NEO_RAISE,
//  _NEO_NEO_ADJUST,
  _NEO_DE_RAISE,
//  _NEO_DE_ADJUST,
  _NEO_US_RAISE,
//  _NEO_US_ADJUST,
  _DE_RAISE,
//  _DE_ADJUST,
  _US_RAISE,
//  _US_ADJUST
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
  BACKTICK
};

#define NNL MO(_LOWER)
#define NNR MO(_NEO_NEO_RAISE)

#define NDL MO(_LOWER)
#define NDR MO(_NEO_DE_RAISE)

#define NUL MO(_LOWER)
#define NUR MO(_NEO_US_RAISE)

#define DL MO(_LOWER)
#define DR MO(_DE_RAISE)

//#define DA MO(_DE_ADJUST)
#define UL MO(_LOWER)

#define UR MO(_US_RAISE)
//#define UA MO(_US_ADJUST)

// Double defined keys
#define KC_CTLESC CTL_T(KC_ESC)

#define KC_TBUPNN LT(_NEO_NEO_RAISE, KC_TAB)
#define KC_TBUPND LT(_NEO_DE_RAISE, KC_TAB)
#define KC_TBUPNU LT(_NEO_US_RAISE, KC_TAB)
//#define KC_TBUPD MO(_DE_RAISE)
#define KC_TBUPD LT(_DE_RAISE, KC_TAB)
#define KC_TBUPU LT(_US_RAISE, KC_TAB)

#define KC_ZDNNN LT(_LOWER, KC_Z)
#define KC_ZUPND LT(_NEO_DE_RAISE, KC_Z)

#define KC_YUPNU LT(_NEO_US_RAISE, KC_Y)

#define KC_QUUPN LT(_NEO_NEO_RAISE, KC_QUOT)
#define KC_BSUPD LT(_DE_RAISE, KC_BSLS)
#define KC_QUUPU LT(_US_RAISE, KC_QUOT)

#define KC_SPDNN LT(_LOWER, KC_SPC)
#define KC_SPDND LT(_LOWER, KC_SPC)
#define KC_SPDNU LT(_LOWER, KC_SPC)
//#define KC_SPDD LT(_LOWER, KC_SPC)
#define KC_SPDD MO(_LOWER)
#define KC_SPDU LT(_LOWER, KC_SPC)

#define KC_LBDND LT(_LOWER, KC_LBRC)
#define KC_LBDNU LT(_LOWER, KC_LBRC)
#define KC_YDWNU LT(_LOWER, KC_Y)

#define KC_ZDWNU LT(_LOWER, KC_Z)
#define KC_ZDWND LT(_LOWER, KC_Z)

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

// NEO keycodes
#define KC_N_DEG S(KC_1)
#define KC_N_EUR S(KC_7)

// Macros
#define KC_COPY LCTL(KC_C)
#define KC_CPUSR LCTL(KC_B)
#define KC_PASTE LCTL(KC_V)

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
    KC_GRV,     KC_Q,     KC_W,    KC_E,    KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,    KC_O,    KC_P,    KC_LBRC,
    KC_TBUPNN,  KC_A,     KC_S,    KC_D,    KC_F,     KC_G,     KC_H,     KC_J,     KC_K,    KC_L,    KC_SCLN, KC_QUUPN,
    KC_LSFT,    KC_ZDNNN, KC_X,    KC_C,    KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
    KC_CTLESC,  KC_LGUI,  KC_LALT, KC_COPY, KC_CPUSR, KC_PASTE, KC_SPDNN, KC_SPDNN, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
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
    NNR,       KC_A,     KC_S,    KC_D,   KC_F,   KC_G,   KC_H,     KC_J,     KC_K,    KC_L,    KC_SCLN, KC_QUUPN,
    KC_LSFT,   KC_ZDNNN, KC_X,    KC_C,   KC_V,   KC_B,   KC_N,     KC_M,     KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
    KC_CTLESC, KC_LGUI,  KC_LALT, KC_SPC, KC_SPC, KC_SPC, KC_SPDNN, KC_SPDNN, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
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
    KC_TBUPND,  KC_U,     KC_I,    KC_A,    KC_E,     KC_O,     KC_S,     KC_N,     KC_R,    KC_T,    KC_D,   KC_ZUPND,
    KC_LSFT,    KC_LBDND, KC_SCLN, KC_QUOT, KC_P,     KC_Y,     KC_B,     KC_M,     KC_COMM, KC_DOT,  KC_J,   KC_RSFT,
    KC_CTLESC,  KC_LGUI,  KC_LALT, KC_COPY, KC_CPUSR, KC_PASTE, KC_SPDND, KC_SPDND, KC_LEFT, KC_DOWN, KC_UP,  KC_RGHT
),

/* NEO keyboard on system US layout
 *
 * what the system sees
 *
 * ,-----------------------------------------------------------------------------------.
 * | Grv  |  X   |  V   |  L   |  C   |  W   |  K   |  H   |  G   |  F   |  Q   | MINS |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | TabUp|  U   |  I   |  A   |  E   |  O   |  S   |  N   |  R   |  T   |  D   | YUp  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | LShft| YDwn | Scln | Quot |  P   |  Y   |  B   |  M   | Comm | Dot  |  J   | RShft|
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
 * | LShft| ZDwn | Scln | Quot |  P   |  Y   |  B   |  M   | Comm | Dot  |  J   | RShft|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |CtlEsc| LWin | LAlt | Copy |Cpyusr| Paste|  SpaceDwn   | Left | Down |  Up  | Right|
 * `-----------------------------------------------------------------------------------'
 */
[_NEO_US] = LAYOUT_planck_grid(
    KC_GRV,     KC_X,     KC_V,    KC_L,    KC_C,     KC_W,     KC_K,     KC_H,     KC_G,    KC_F,    KC_Q,   KC_MINS,
    KC_TBUPNU,  KC_U,     KC_I,    KC_A,    KC_E,     KC_O,     KC_S,     KC_N,     KC_R,    KC_T,    KC_D,   KC_YUPNU,
    KC_LSFT,    KC_YDWNU, KC_SCLN, KC_QUOT, KC_P,     KC_Z,     KC_B,     KC_M,     KC_COMM, KC_DOT,  KC_J,   KC_RSFT,
    KC_CTLESC,  KC_LGUI,  KC_LALT, KC_COPY, KC_CPUSR, KC_PASTE, KC_SPDNU, KC_SPDNU, KC_LEFT, KC_DOWN, KC_UP,  KC_RGHT
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
    KC_LSFT,  KC_ZDWND, KC_X,    KC_C,    KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
    KC_LCTL,  KC_LGUI,  KC_LALT, KC_COPY, KC_CPUSR, KC_PASTE, KC_SPDD,  KC_SPDD,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
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
    KC_LSFT,   KC_ZDWND, KC_X,    KC_C,   KC_V,   KC_B,   KC_N,     KC_M,     KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
    KC_CTLESC, KC_LGUI,  KC_LALT, KC_SPC, KC_SPC, KC_SPC, KC_SPDD,  KC_SPDD,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
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
    KC_LSFT,  KC_ZDWNU, KC_X,    KC_C,    KC_V,     KC_B,     KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
    KC_LCTL,  KC_LGUI,  KC_LALT, NEO_NEO, KC_CPUSR, KC_PASTE, KC_SPDU, KC_SPDU, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
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
    KC_LSFT,   KC_ZDWNU, KC_X,    KC_C,   KC_V,   KC_B,   KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
    KC_CTLESC, KC_LGUI,  KC_LALT, KC_SPC, KC_SPC, KC_SPC, KC_SPDU, KC_SPDU, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
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
 * | TabUp|   \  |   /  |   {  |   }  |   *  |   ?  |   (  |   )  |   -  |   :  |  @   |
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
 * | TabUp|   \  |   /  |   {  |   }  |   *  |   ?  |   (  |   )  |   -  |   :  |  @   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   #  |   $  |   |  |   ~  |   `  |   +  |   %  |   "  |   '  |   ;  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |             |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_NEO_NEO_RAISE] = LAYOUT_planck_grid(
    KC_TRNS, BACKTICK,  KC_QUES, KC_G_LBRC, KC_G_RBRC, KC_GRV,   KC_EXLM,  KC_G_LT, KC_G_GT, KC_RPRN, KC_CIRC, KC_TRNS,
    _______, KC_G_BSLS, KC_AMPR, KC_G_LCBR, KC_G_RCBR, KC_RCBR,  KC_UNDS,  KC_ASTR, KC_LPRN, KC_SLSH, KC_GT,   KC_G_AT,
    _______, KC_BSLS,   KC_DLR,  KC_G_PIPE, KC_G_TILD, KC_G_BTK, KC_RBRC,  KC_PERC, KC_AT,   KC_PIPE, KC_LT,   _______,
    _______, _______,   _______, _______,   _______,   _______,  _______, _______,  _______, _______, _______, _______
),

/* neo on de raise
 * ,-----------------------------------------------------------------------------------.
 * |   X  |   `  |   _  |   [  |   ]  |   ^  |   !  |   <  |   >  |   =  |   &  |  X   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | TabUp|   \  |   /  |   {  |   }  |   *  |   ?  |   (  |   )  |   -  |   :  |  @   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   #  |   $  |   |  |   ~  |   `  |   +  |   %  |   "  |   '  |   ;  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |             |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_NEO_DE_RAISE] = LAYOUT_planck_grid(
    KC_TRNS, KC_PLUS,   KC_QUES, KC_G_LBRC, KC_G_RBRC, KC_GRV,   KC_EXLM,  KC_G_LT, KC_G_GT, KC_RPRN, KC_CIRC, KC_TRNS,
    _______, KC_G_BSLS, KC_AMPR, KC_G_LCBR, KC_G_RCBR, KC_RCBR,  KC_UNDS,  KC_ASTR, KC_LPRN, KC_SLSH, KC_GT,   KC_G_AT,
    _______, KC_BSLS,   KC_DLR,  KC_G_PIPE, KC_G_TILD, KC_G_BTK, KC_RBRC,  KC_PERC, KC_AT,   KC_PIPE, KC_LT,   _______,
    _______, _______,   _______, _______,   _______,   _______,  _______, _______,  _______, _______, _______, _______
),

/* neo on us raise
 * ,-----------------------------------------------------------------------------------.
 * |   X  |   `  |   _  |   [  |   ]  |   ^  |   !  |   <  |   >  |   =  |   &  |  X   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | TabUp|   \  |   /  |   {  |   }  |   *  |   ?  |   (  |   )  |   -  |   :  |  @   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   #  |   $  |   |  |   ~  |   `  |   +  |   %  |   "  |   '  |   ;  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |             |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_NEO_US_RAISE] = LAYOUT_planck_grid(
    KC_TRNS, KC_PLUS,   KC_QUES, KC_G_LBRC, KC_G_RBRC, KC_GRV,   KC_EXLM,  KC_G_LT, KC_G_GT, KC_RPRN, KC_CIRC, KC_TRNS,
    _______, KC_G_BSLS, KC_AMPR, KC_G_LCBR, KC_G_RCBR, KC_RCBR,  KC_UNDS,  KC_ASTR, KC_LPRN, KC_SLSH, KC_GT,   KC_G_AT,
    _______, KC_BSLS,   KC_DLR,  KC_G_PIPE, KC_G_TILD, KC_G_BTK, KC_RBRC,  KC_PERC, KC_AT,   KC_PIPE, KC_LT,   _______,
    _______, _______,   _______, _______,   _______,   _______,  _______, _______,  _______, _______, _______, _______
),

/* de raise
 * ,-----------------------------------------------------------------------------------.
 * |   X  |   `  |   _  |   [  |   ]  |   ^  |   !  |   <  |   >  |   =  |   &  |  X   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | TabUp|   \  |   /  |   {  |   }  |   *  |   ?  |   (  |   )  |   -  |   :  |  @   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   #  |   $  |   |  |   ~  |   `  |   +  |   %  |   "  |   '  |   ;  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |             |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_DE_RAISE] = LAYOUT_planck_grid(
    KC_TRNS, KC_GRV,  KC_UNDS, KC_LBRC, KC_RBRC, KC_CIRC, KC_EXLM, KC_LT,   KC_GT,   KC_EQL,  KC_AMPR, KC_TRNS,
    KC_TRNS, KC_BSLS, KC_SLSH, KC_LCBR, KC_RCBR, KC_ASTR, KC_QUES, KC_LPRN, KC_RPRN, KC_MINS, KC_COLN, KC_AT,
    _______, KC_HASH, KC_DLR,  KC_PIPE, KC_TILD, KC_GRV,  KC_PLUS, KC_PERC, KC_DQUO, KC_QUOT, KC_SCLN, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* us raise
 * ,-----------------------------------------------------------------------------------.
 * |   X  |   `  |   _  |   [  |   ]  |   ^  |   !  |   <  |   >  |   =  |   &  |  X   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | TabUp|   \  |   /  |   {  |   }  |   *  |   ?  |   (  |   )  |   -  |   :  |  @   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   #  |   $  |   |  |   ~  |   `  |   +  |   %  |   "  |   '  |   ;  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |             |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_US_RAISE] = LAYOUT_planck_grid(
    KC_TRNS, KC_GRV,  KC_UNDS, KC_LBRC, KC_RBRC, KC_CIRC, KC_EXLM, KC_LT,   KC_GT,   KC_EQL,  KC_AMPR, KC_TRNS,
    KC_TRNS, KC_BSLS, KC_SLSH, KC_LCBR, KC_RCBR, KC_ASTR, KC_QUES, KC_LPRN, KC_RPRN, KC_MINS, KC_COLN, KC_AT,
    _______, KC_HASH, KC_DLR,  KC_PIPE, KC_TILD, KC_GRV,  KC_PLUS, KC_PERC, KC_DQUO, KC_QUOT, KC_SCLN, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

///* neo on neo adjust (neo neo lower + neo neo raise)
// * ,-----------------------------------------------------------------------------------.
// * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  | F10  | F11  | F12  |
// * |------+------+------+------+------+------+------+------+------+------+------+------|
// * | Vol+ | Next |Brght+| Pscr |      |      |      |NEO_US|NEO_DE|NEOGAM| NEO  |      |
// * |------+------+------+------+------+------+------+------+------+------+------+------|
// * | Vol- | Prev |Brght-|      |      |      |      |      |      |DEGAME| DE   |      |
// * |------+------+------+------+------+------+------+------+------+------+------+------|
// * | Mute | Pause| Play |      |      |      |             |      |USGAME| US   |      |
// * `-----------------------------------------------------------------------------------'
// */
//[_NEO_NEO_ADJUST] = LAYOUT_planck_grid(
//    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,  KC_F12,
//    KC_VOLU, KC_MNXT, KC_BRIU, KC_PSCR, _______, _______, _______, NEO_US,  NEO_DE,  NEO_GAME, NEO_NEO, _______,
//    KC_VOLD, KC_MPRV, KC_BRID, _______, _______, _______, _______, _______, _______, DE_GAME,  DE,      _______,
//    KC_MUTE, KC_MSTP, KC_MPLY, _______, _______, _______, _______, _______, _______, US_GAME,  US,      _______
//),
//
///* neo on de adjust (neo de lower + neo de raise)
// * ,-----------------------------------------------------------------------------------.
// * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  | F10  | F11  | F12  |
// * |------+------+------+------+------+------+------+------+------+------+------+------|
// * | Vol+ | Next |Brght+| Pscr |      |      |      |NEO_US|NEO_DE|NEOGAM| NEO  |      |
// * |------+------+------+------+------+------+------+------+------+------+------+------|
// * | Vol- | Prev |Brght-|      |      |      |      |      |      |DEGAME| DE   |      |
// * |------+------+------+------+------+------+------+------+------+------+------+------|
// * | Mute | Pause| Play |      |      |      |             |      |USGAME| US   |      |
// * `-----------------------------------------------------------------------------------'
// */
//[_NEO_DE_ADJUST] = LAYOUT_planck_grid(
//    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,  KC_F12,
//    KC_VOLU, KC_MNXT, KC_BRIU, KC_PSCR, _______, _______, _______, NEO_US,  NEO_DE,  NEO_GAME, NEO_NEO, _______,
//    KC_VOLD, KC_MPRV, KC_BRID, _______, _______, _______, _______, _______, _______, DE_GAME,  DE,      _______,
//    KC_MUTE, KC_MSTP, KC_MPLY, _______, _______, _______, _______, _______, _______, US_GAME,  US,      _______
//),
//
///* neo on us adjust (neo us lower + neo us raise)
// * ,-----------------------------------------------------------------------------------.
// * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  | F10  | F11  | F12  |
// * |------+------+------+------+------+------+------+------+------+------+------+------|
// * | Vol+ | Next |Brght+| Pscr |      |      |      |NEO_US|NEO_DE|NEOGAM| NEO  |      |
// * |------+------+------+------+------+------+------+------+------+------+------+------|
// * | Vol- | Prev |Brght-|      |      |      |      |      |      |DEGAME| DE   |      |
// * |------+------+------+------+------+------+------+------+------+------+------+------|
// * | Mute | Pause| Play |      |      |      |             |      |USGAME| US   |      |
// * `-----------------------------------------------------------------------------------'
// */
//[_NEO_US_ADJUST] = LAYOUT_planck_grid(
//    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,  KC_F12,
//    KC_VOLU, KC_MNXT, KC_BRIU, KC_PSCR, _______, _______, _______, NEO_US,  NEO_DE,  NEO_GAME, NEO_NEO, _______,
//    KC_VOLD, KC_MPRV, KC_BRID, _______, _______, _______, _______, _______, _______, DE_GAME,  DE,      _______,
//    KC_MUTE, KC_MSTP, KC_MPLY, _______, _______, _______, _______, _______, _______, US_GAME,  US,      _______
//),
//
///* de adjust (de lower + de raise)
// * ,-----------------------------------------------------------------------------------.
// * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  | F10  | F11  | F12  |
// * |------+------+------+------+------+------+------+------+------+------+------+------|
// * | Vol+ | Next |Brght+| Pscr |      |      |      |NEO_US|NEO_DE|NEOGAM| NEO  |      |
// * |------+------+------+------+------+------+------+------+------+------+------+------|
// * | Vol- | Prev |Brght-|      |      |      |      |      |      |DEGAME| DE   |      |
// * |------+------+------+------+------+------+------+------+------+------+------+------|
// * | Mute | Pause| Play |      |      |      |             |      |USGAME| US   |      |
// * `-----------------------------------------------------------------------------------'
// */
//[_DE_ADJUST] = LAYOUT_planck_grid(
//    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,  KC_F12,
//    KC_VOLU, KC_MNXT, KC_BRIU, KC_PSCR, _______, _______, _______, NEO_US,  NEO_DE,  NEO_GAME, NEO_NEO, _______,
//    KC_VOLD, KC_MPRV, KC_BRID, _______, _______, _______, _______, _______, _______, DE_GAME,  DE,      _______,
//    KC_MUTE, KC_MSTP, KC_MPLY, _______, _______, _______, _______, _______, _______, US_GAME,  US,      _______
//),
//
///* us adjust (us lower + us raise)
// * ,-----------------------------------------------------------------------------------.
// * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  | F10  | F11  | F12  |
// * |------+------+------+------+------+------+------+------+------+------+------+------|
// * | Vol+ | Next |Brght+| Pscr |      |      |      |NEO_US|NEO_DE|NEOGAM| NEO  |      |
// * |------+------+------+------+------+------+------+------+------+------+------+------|
// * | Vol- | Prev |Brght-|      |      |      |      |      |      |DEGAME| DE   |      |
// * |------+------+------+------+------+------+------+------+------+------+------+------|
// * | Mute | Pause| Play |      |      |      |             |      |USGAME| US   |      |
// * `-----------------------------------------------------------------------------------'
// */
//[_US_ADJUST] = LAYOUT_planck_grid(
//    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,  KC_F12,
//    KC_VOLU, KC_MNXT, KC_BRIU, KC_PSCR, _______, _______, _______, NEO_US,  NEO_DE,  NEO_GAME, NEO_NEO, _______,
//    KC_VOLD, KC_MPRV, KC_BRID, _______, _______, _______, _______, _______, _______, DE_GAME,  DE,      _______,
//    KC_MUTE, KC_MSTP, KC_MPLY, _______, _______, _______, _______, _______, _______, US_GAME,  US,      _______
//)
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

//#ifdef AUDIO_ENABLE
//  float game_song[][2]     = SONG(PLOVER_SOUND);
//  float game_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
//#endif

//void keyboard_post_init_user(void) {
//  // Customise these values to desired behaviour
//  debug_enable=true;
//  debug_matrix=true;
//  debug_keyboard=true;
//  //debug_mouse=true;
//}

uint32_t layer_state_set_user(uint32_t state) {
//  print("orig\n");
//  if (layer_state_is(_LOWER)) {print("LOWER\n");}
//  if (layer_state_is(_RAISE)) {print("RAISE\n");}
//  if (layer_state_is(_ADJUST)) {print("ADJUST\n");}
//  if (layer_state_is(_NEOLOWER)) {print("NEOLOWER\n");}
//  if (layer_state_is(_NEORAISE)) {print("NEORAISE\n");}
//  if (layer_state_is(_NEOADJUST)) {print("NEOADJUST\n");}
//  state = update_tri_layer_state(state, _LOWER, _NEO_NEO_RAISE, _NEO_NEO_ADJUST);
//  state = update_tri_layer_state(state, _LOWER, _NEO_DE_RAISE, _NEO_DE_ADJUST);
//  state = update_tri_layer_state(state, _LOWER, _NEO_US_RAISE, _NEO_US_ADJUST);
//  state = update_tri_layer_state(state, _LOWER, _DE_RAISE, _DE_ADJUST);
//  state = update_tri_layer_state(state, _LOWER, _US_RAISE, _US_ADJUST);
//  print("first\n");
//  if (layer_state_is(_LOWER)) {print("LOWER\n");}
//  if (layer_state_is(_RAISE)) {print("RAISE\n");}
//  if (layer_state_is(_ADJUST)) {print("ADJUST\n");}
//  if (layer_state_is(_NEOLOWER)) {print("NEOLOWER\n");}
//  if (layer_state_is(_NEORAISE)) {print("NEORAISE\n");}
//  if (layer_state_is(_NEOADJUST)) {print("NEOADJUST\n");}
//  print("second\n");
//  if (layer_state_is(_LOWER)) {print("LOWER\n");}
//  if (layer_state_is(_RAISE)) {print("RAISE\n");}
//  if (layer_state_is(_ADJUST)) {print("ADJUST\n");}
//  if (layer_state_is(_NEOLOWER)) {print("NEOLOWER\n");}
//  if (layer_state_is(_NEORAISE)) {print("NEORAISE\n");}
//  if (layer_state_is(_NEOADJUST)) {print("NEOADJUST\n");}
//  print("\n");
//  return state;
  if (
      ( layer_state_cmp(state, _LOWER) && layer_state_cmp(state, _NEO_NEO_RAISE ) ) ||
      ( layer_state_cmp(state, _LOWER) && layer_state_cmp(state, _NEO_DE_RAISE ) ) ||
      ( layer_state_cmp(state, _LOWER) && layer_state_cmp(state, _NEO_US_RAISE ) ) ||
      ( layer_state_cmp(state, _LOWER) && layer_state_cmp(state, _DE_RAISE ) ) ||
      ( layer_state_cmp(state, _LOWER) && layer_state_cmp(state, _US_RAISE ) ) ) {
    return state | (1UL<<_ADJUST);
  } else {
    return state & ~(1UL<<_ADJUST);
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
    case BACKTICK:
      if (record->event.pressed) {
//        print("backtick\n");
        SENDSTRING("`");
      } else {
        // when keycode QMKBEST is released
      }
      break;
  }
  return true;
}

//bool muse_mode = false;
//uint8_t last_muse_note = 0;
//uint16_t muse_counter = 0;
//uint8_t muse_offset = 70;
//uint16_t muse_tempo = 50;
//
//void encoder_update(bool clockwise) {
//  if (muse_mode) {
//    if (IS_LAYER_ON(_RAISE)) {
//      if (clockwise) {
//        muse_offset++;
//      } else {
//        muse_offset--;
//      }
//    } else {
//      if (clockwise) {
//        muse_tempo+=1;
//      } else {
//        muse_tempo-=1;
//      }
//    }
//  } else {
//    if (clockwise) {
//      #ifdef MOUSEKEY_ENABLE
//        tap_code(KC_MS_WH_DOWN);
//      #else
//        tap_code(KC_PGDN);
//      #endif
//    } else {
//      #ifdef MOUSEKEY_ENABLE
//        tap_code(KC_MS_WH_UP);
//      #else
//        tap_code(KC_PGUP);
//      #endif
//    }
//  }
//}
//
//void dip_update(uint8_t index, bool active) {
//  switch (index) {
//    case 0:
//      if (active) {
//        layer_on(_ADJUST);
//      } else {
//        layer_off(_ADJUST);
//      }
//      break;
//    case 1:
//      if (active) {
//        muse_mode = true;
//      } else {
//        muse_mode = false;
//        #ifdef AUDIO_ENABLE
//          stop_all_notes();
//        #endif
//      }
//   }
//}
//
//void matrix_scan_user(void) {
//  #ifdef AUDIO_ENABLE
//    if (muse_mode) {
//      if (muse_counter == 0) {
//        uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
//        if (muse_note != last_muse_note) {
//          stop_note(compute_freq_for_midi_note(last_muse_note));
//          play_note(compute_freq_for_midi_note(muse_note), 0xF);
//          last_muse_note = muse_note;
//        }
//      }
//      muse_counter = (muse_counter + 1) % muse_tempo;
//    }
//  #endif
//}
//
//bool music_mask_user(uint16_t keycode) {
//  switch (keycode) {
//    case RAISE:
//    case LOWER:
//      return false;
//    default:
//      return true;
//  }
//}
