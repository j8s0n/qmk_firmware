/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

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

#include QMK_KEYBOARD_H

#define MO_LAYR XXXXXXX

#define O_ALT   LALT_T(KC_O)
#define E_CTL   LCTL_T(KC_E)
#define U_GUI   LGUI_T(KC_U)
#define I_SFT   LSFT_T(KC_I)
#define D_SFT   LSFT_T(KC_D)
#define H_GUI   LGUI_T(KC_H)
#define T_CTL   LCTL_T(KC_T)
#define N_ALT   LALT_T(KC_N)
#define ONE_SFT OSM(MOD_LSFT)

#define ZERO_SH LSFT_T(KC_0)

#define L2_TAB  LT(2, KC_TAB)
#define L1_ESC  LT(1, KC_ESC)
#define L4_ENTR LT(4, KC_ENT)

#define PER_ALT LALT_T(KC_PERC)
#define CAR_ALT RALT_T(KC_CIRC)
#define _5_CTRL LCTL_T(KC_5)
#define _6_CTRL RCTL_T(KC_6)
#define F5_SHFT LSFT_T(KC_F5)
#define F6_SHFT LSFT_T(KC_F6)
#define F11_GUI LGUI_T(KC_F11)
#define F12_GUI LGUI_T(KC_F12)

#define CTL_LF  LCTL(KC_LEFT)
#define CTL_RT  LCTL(KC_RGHT)

#define SHGUI_F SGUI(KC_F)
#define SHGUI_S SGUI(KC_S)
#define SHGUI_Q SGUI(KC_Q)
#define SHGUI__ SGUI(KC_MINS)

#define LGUI__  LGUI(KC_MINS)

#define LSA_UP  LSA(KC_UP)
#define LSA_DN  LSA(KC_DOWN)
#define LALT_UP LALT(KC_UP)
#define LALT_DN LALT(KC_DOWN)
#define RCS_U   RCS(KC_U)
#define FLASH   LALT(LCTL(QK_MAKE))

//========================================================================================
//  create an enum for keycodes I create
//========================================================================================
enum custom_keycodes {
  EXIT_VM1 = SAFE_RANGE,
  EXIT_VM2,
};

//========================================================================================
//  define macros
//========================================================================================
bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  switch (keycode) {
  case EXIT_VM1:
    // exit the VM and go to desktop 1
    if (record->event.pressed) {
      SEND_STRING(
          SS_TAP(X_RCTL)
          SS_LGUI("1")
      );
    }

    return false;

  case EXIT_VM2:
    if (record->event.pressed) {
      SEND_STRING(
          SS_TAP(X_RCTL)
          SS_LGUI(SS_TAP(X_LEFT))
      );
    }

    return false;
  }

  return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_3x5_2( // Letters and common punctuation
  //,--------------------------------------------.                    ,--------------------------------------------.
      KC_QUOT, KC_COMM,  KC_DOT,    KC_P,    KC_Y,                         KC_F,    KC_G,    KC_C,    KC_R,    KC_L,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
         KC_A,   O_ALT,   E_CTL,   U_GUI,   I_SFT,                        D_SFT,   H_GUI,   T_CTL,   N_ALT,    KC_S,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      KC_SCLN,    KC_Q,    KC_J,    KC_K,    KC_X,                         KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                           L2_TAB,  L1_ESC,    L4_ENTR,  KC_SPC
                                      //`-----------------'  `-----------------'
  ),

    [1] = LAYOUT_split_3x5_2( // Arrows
  //,--------------------------------------------.                    ,--------------------------------------------.
        TG(5), XXXXXXX, XXXXXXX, XXXXXXX, KC_LALT,                      KC_PGUP, KC_HOME,   KC_UP,  KC_END, XXXXXXX,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      KC_CAPS, XXXXXXX, XXXXXXX, XXXXXXX, KC_LCTL,                      KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, CW_TOGG,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, ZERO_SH,                      KC_RSFT,  KC_DEL, KC_BSPC,  LGUI__, SHGUI__,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                            MO(6), MO_LAYR,    KC_LGUI,   MO(3)
                                      //`-----------------'  `-----------------'
  ),

    [2] = LAYOUT_split_3x5_2( // numbers, shifted numbers, and function keys
  //,--------------------------------------------.                    ,--------------------------------------------.
      KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, PER_ALT,                      CAR_ALT, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
         KC_1,    KC_2,    KC_3,    KC_4, _5_CTRL,                      _6_CTRL,    KC_7,    KC_8,    KC_9,    KC_0,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
        KC_F1,   KC_F2,   KC_F3,   KC_F4, F5_SHFT,                      F6_SHFT,   KC_F7,   KC_F8,   KC_F9,  KC_F10,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                          MO_LAYR, F11_GUI,    F12_GUI,  KC_DOT
                                      //`-----------------'  `-----------------'
  ),

    [3] = LAYOUT_split_3x5_2( // discord and music
  //,--------------------------------------------.                    ,--------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,EXIT_VM1,                     EXIT_VM2, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      XXXXXXX,   KC_UP,  LSA_UP, LALT_UP,   RCS_U,                      XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      XXXXXXX, KC_DOWN,  LSA_DN, LALT_DN, XXXXXXX,                      XXXXXXX, KC_VOLD, KC_MUTE, KC_VOLU, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX,    XXXXXXX, MO_LAYR
                                      //`-----------------'  `-----------------'
  ),

    [4] = LAYOUT_split_3x5_2( // symbols
  //,--------------------------------------------.                    ,--------------------------------------------.
      XXXXXXX, KC_LALT, KC_LCTL, KC_LGUI, KC_LSFT,                      KC_RSFT, KC_RGUI, KC_LCTL, KC_RALT, XXXXXXX,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      KC_TILD, KC_SLSH, KC_MINS, KC_LBRC, KC_LSFT,                      KC_RSFT, KC_RBRC,  KC_EQL, KC_BSLS, XXXXXXX,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
       KC_GRV, KC_QUES, KC_UNDS, KC_LCBR, XXXXXXX,                      XXXXXXX, KC_RCBR, KC_PLUS, KC_PIPE, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                          KC_LSFT, ONE_SFT,    MO_LAYR, XXXXXXX
                                      //`-----------------'  `-----------------'
  ),

    [5] = LAYOUT_split_3x5_2( // Arrows permanent
  //,--------------------------------------------.                    ,--------------------------------------------.
        TG(5), XXXXXXX, XXXXXXX, XXXXXXX, KC_LALT,                      KC_PGUP, KC_HOME,   KC_UP,  KC_END, XXXXXXX,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LCTL,                      KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, CW_TOGG,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, ZERO_SH,                      KC_RSFT,  KC_DEL, KC_BSPC,  LGUI__, SHGUI__,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, MO_LAYR,    KC_LGUI,   MO(3)
                                      //`-----------------'  `-----------------'
  ),

    [6] = LAYOUT_split_3x5_2( // QMK functions
  //,--------------------------------------------.                    ,--------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX
                                      //`-----------------'  `-----------------'
  )
};

/*
  //,--------------------------------------------.                    ,--------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX
                                      //`-----------------'  `-----------------'
 */
