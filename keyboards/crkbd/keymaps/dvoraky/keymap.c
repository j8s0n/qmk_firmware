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

#define ALT_COM LALT_T(KC_COMM)
#define CTL_DOT LCTL_T(KC_DOT)
#define GUI_P   LGUI_T(KC_P)

#define ALT_R   RALT_T(KC_R)
#define CTL_C   LCTL_T(KC_C)
#define GUI_G   RGUI_T(KC_G)

#define SH_ESC  LSFT_T(KC_ESC)
#define L1_TAB  LT(1, KC_TAB)
#define L4_SPC  LT(4, KC_SPC)
#define SH_ENTR RSFT_T(KC_ENT)

#define SH_TAB  LSFT_T(KC_TAB)
#define L1_ESC  LT(1, KC_ESC)
#define L4_ENTR LT(4, KC_ENT)
#define SH_SPC  RSFT_T(KC_SPC)

#define ALT_UP  LALT(KC_UP)
#define ALT_LF  LALT(KC_LEFT)
#define ALT_RT  LALT(KC_RGHT)
#define ALT_DN  LALT(KC_DOWN)

#define CTL_LF  LCTL(KC_LEFT)
#define CTL_RT  LCTL(KC_RGHT)

#define SHGUI_F SGUI(KC_F)
#define SHGUI_S SGUI(KC_S)
#define SHGUI_Q SGUI(KC_Q)
#define SHGUI__ SGUI(KC_MINS)

#define LGUI_UP LGUI(KC_UP)
#define LGUI_DN LGUI(KC_DOWN)
#define LGUI_RT LGUI(KC_RGHT)
#define LGUI_LF LGUI(KC_LEFT)
#define LGUI__  LGUI(KC_MINS)

#define LGUI_1  LGUI(KC_1)
#define LGUI_2  LGUI(KC_2)
#define LGUI_3  LGUI(KC_3)
#define LGUI_4  LGUI(KC_4)
#define LGUI_5  LGUI(KC_5)
#define LGUI_6  LGUI(KC_6)
#define LGUI_7  LGUI(KC_7)
#define LGUI_8  LGUI(KC_8)
#define LGUI_9  LGUI(KC_9)
#define LGUI_0  LGUI(KC_0)

#define LSA_UP  LSA(KC_UP)
#define LSA_DN  LSA(KC_DOWN)
#define LALT_UP LALT(KC_UP)
#define LALT_DN LALT(KC_DOWN)
#define RCS_U   RCS(KC_U)

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
    [0] = LAYOUT_split_3x6_3( // Letters and common punctuation
  //,---------/**/--------------------------------------------.                    ,---------------------------------------------/**/--------.
      XXXXXXX,/**/ KC_QUOT, ALT_COM, CTL_DOT,   GUI_P,    KC_Y,                         KC_F,   GUI_G,   CTL_C,   ALT_R,    KC_L,/**/ XXXXXXX,
  //|--------+/**/--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+/**/--------|
      XXXXXXX,/**/    KC_A,    KC_O,    KC_E,    KC_U,    KC_I,                         KC_D,    KC_H,    KC_T,    KC_N,    KC_S,/**/ XXXXXXX,
  //|--------+/**/--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+/**/--------|
      XXXXXXX,/**/ KC_SCLN,    KC_Q,    KC_J,    KC_K,    KC_X,                         KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,/**/ XXXXXXX,
  //|--------+/**/--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+/**/--------|
                                               KC_DEL,  SH_TAB,  L1_ESC,    L4_ENTR,  SH_SPC, KC_BSPC
                                          //`--------------------------'  `--------------------------'
  ),

    [1] = LAYOUT_split_3x6_3( // Numbers and arrows
  //,---------/**/--------------------------------------------.                    ,---------------------------------------------/**/--------.
      XXXXXXX,/**/ KC_PGUP, XXXXXXX,  ALT_UP, KC_HOME,  KC_END,                      KC_LCTL,  CTL_LF,   KC_UP,  CTL_RT, XXXXXXX,/**/ XXXXXXX,
  //|--------+/**/--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+/**/--------|
      XXXXXXX,/**/ KC_PGDN,  ALT_LF,  ALT_DN,  ALT_RT, KC_LSFT,                      KC_RSFT, KC_LEFT, KC_DOWN, KC_RGHT, CW_TOGG,/**/ XXXXXXX,
  //|--------+/**/--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+/**/--------|
      XXXXXXX,/**/    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,/**/ XXXXXXX,
  //|--------+/**/--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+/**/--------|
                                              CW_TOGG,   MO(2), XXXXXXX,      MO(5),   MO(3), KC_CAPS
                                          //`--------------------------'  `--------------------------'
  ),

    [2] = LAYOUT_split_3x6_3( // i3
  //,---------/**/--------------------------------------------.                    ,---------------------------------------------/**/--------.
      XXXXXXX,/**/ XXXXXXX, XXXXXXX, XXXXXXX, KC_RCTL, XXXXXXX,                      SHGUI_F, XXXXXXX, LGUI_UP, XXXXXXX, SHGUI_Q,/**/ XXXXXXX,
  //|--------+/**/--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+/**/--------|
      XXXXXXX,/**/ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, SHGUI__,                       LGUI__, LGUI_LF, LGUI_DN, LGUI_RT, SHGUI_S,/**/ XXXXXXX,
  //|--------+/**/--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+/**/--------|
      XXXXXXX,/**/  LGUI_1,  LGUI_2,  LGUI_3,  LGUI_4,  LGUI_5,                       LGUI_6,  LGUI_7,  LGUI_8,  LGUI_9,  LGUI_0,/**/ XXXXXXX,
  //|--------+/**/--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+/**/--------|
                                              XXXXXXX, XXXXXXX, KC_LSFT,    KC_RSFT, XXXXXXX, XXXXXXX
                                          //`--------------------------'  `--------------------------'
  ),

    [3] = LAYOUT_split_3x6_3( // discord and music
  //,---------/**/--------------------------------------------.                    ,---------------------------------------------/**/--------.
      XXXXXXX,/**/ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,EXIT_VM1,                     EXIT_VM2, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,/**/ XXXXXXX,
  //|--------+/**/--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+/**/--------|
      XXXXXXX,/**/ XXXXXXX,   KC_UP,  LSA_UP, LALT_UP,   RCS_U,                      XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX,/**/ XXXXXXX,
  //|--------+/**/--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+/**/--------|
      XXXXXXX,/**/ XXXXXXX, KC_DOWN,  LSA_DN, LALT_DN, XXXXXXX,                      XXXXXXX, KC_VOLD, KC_MUTE, KC_VOLU, XXXXXXX,/**/ XXXXXXX,
  //|--------+/**/--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+/**/--------|
                                              XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
                                          //`--------------------------'  `--------------------------'
  ),

    [4] = LAYOUT_split_3x6_3( // functions and symbols
  //,---------/**/--------------------------------------------.                    ,---------------------------------------------/**/--------.
      XXXXXXX,/**/  KC_GRV, KC_LALT, KC_LCTL, KC_LGUI, KC_LSFT,                      KC_RSFT, KC_RGUI, KC_LCTL, KC_RALT,  KC_F12,/**/ XXXXXXX,
  //|--------+/**/--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+/**/--------|
      XXXXXXX,/**/ KC_TILD, KC_SLSH, KC_MINS, KC_LBRC, KC_LSFT,                      KC_RSFT, KC_RBRC,  KC_EQL, KC_BSLS,  KC_F11,/**/ XXXXXXX,
  //|--------+/**/--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+/**/--------|
      XXXXXXX,/**/   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                        KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,/**/ XXXXXXX,
  //|--------+/**/--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+/**/--------|
                                              XXXXXXX,   MO(2), XXXXXXX,    XXXXXXX,   MO(3), XXXXXXX
                                          //`--------------------------'  `--------------------------'
  ),

    [5] = LAYOUT_split_3x6_3( // mouse
  //,---------/**/--------------------------------------------.                    ,---------------------------------------------/**/--------.
      XXXXXXX,/**/ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, KC_MS_U, XXXXXXX, XXXXXXX,/**/ XXXXXXX,
  //|--------+/**/--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+/**/--------|
      XXXXXXX,/**/ XXXXXXX, KC_BTN2, KC_BTN3, KC_BTN1, KC_WH_D,                      XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX,/**/ XXXXXXX,
  //|--------+/**/--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+/**/--------|
      XXXXXXX,/**/ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_WH_U,                      XXXXXXX, KC_ACL0, KC_ACL1, KC_ACL2, XXXXXXX,/**/ XXXXXXX,
  //|--------+/**/--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+/**/--------|
                                              XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
                                          //`--------------------------'  `--------------------------'
  )
};

#if 0
  //,---------/**/--------------------------------------------.                    ,---------------------------------------------/**/--------.
      XXXXXXX,/**/ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,/**/ XXXXXXX,
  //|--------+/**/--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+/**/--------|
      XXXXXXX,/**/ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,/**/ XXXXXXX,
  //|--------+/**/--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+/**/--------|
      XXXXXXX,/**/ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,/**/ XXXXXXX,
  //|--------+/**/--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+/**/--------|
                                              XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
                                          //`--------------------------'  `--------------------------'
#endif // 0
