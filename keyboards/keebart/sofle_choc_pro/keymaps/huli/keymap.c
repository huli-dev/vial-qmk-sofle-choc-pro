// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layers {
    BASE,
    BASE_ARROW,
    NUM,
    GAME,
    FUNC,
    EXTRA
};

#define BASE_RGB 10, 10, 10
#define NUM_RGB 0, 0, 100
#define GAME_RGB 100, 0, 0

#define FUNC_RGB 0, 100, 0
#define EXTRA_RGB 0, 100, 100

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  [   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |ARROW |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|  GAME |    |  NUM  |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |  \   |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[BASE] = LAYOUT_split_4x6_5(
  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_BSPC,
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_LBRC,
  MO(BASE_ARROW), KC_A,   KC_S,    KC_D,    KC_F,    KC_G,               KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,  KC_QUOT,
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, TG(GAME),    TG(NUM), KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_NUBS,
                      KC_LGUI,KC_LALT,KC_LCTL, MO(FUNC), KC_ENT,      KC_SPC,  MO(EXTRA), KC_RCTL, KC_RALT, KC_RGUI
),
[BASE_ARROW] = LAYOUT_split_4x6_5(
  _______,  _______,  _______,   _______,  _______,  _______,              _______,  _______,  _______,  _______,  _______,  _______,
  _______,  _______,   KC_UP,    _______,  _______,  _______,              _______,  _______,  _______,  _______,  _______,  _______,
  _______,   KC_LEFT,  KC_DOWN,  KC_RGHT,  _______,  _______,              _______,  _______,  _______,  _______,  _______,  _______,
  _______, _______, _______, _______, _______, _______, TG(GAME),      TG(NUM), _______, _______, _______, _______, _______, _______,
                     _______, _______, _______, MO(FUNC), _______,      _______,  MO(EXTRA), _______, _______, _______
),

[NUM] = LAYOUT_split_4x6_5(
  _______, _______ , _______ , _______ , _______ , _______,                       _______,  KC_NUM, KC_PSLS,  KC_PAST,  KC_PMNS, _______,
  _______,  KC_INS,  KC_PSCR,   KC_APP,  XXXXXXX, XXXXXXX,                        KC_PGUP, KC_P7, KC_P8, KC_P9, KC_PPLS, KC_BSPC,
  _______, KC_LALT,  KC_LCTL,  KC_LSFT,  XXXXXXX, KC_CAPS,                        KC_PGDN,  KC_P4, KC_P5, KC_P6,  KC_PDOT, KC_BSPC,
  _______, C(KC_Z), C(KC_X), C(KC_C), C(KC_V), XXXXXXX,  _______,       _______,  XXXXXXX, KC_P1, KC_P2, KC_P3,  KC_P0, KC_PENT,
                    KC_LGUI,KC_LALT,KC_LCTL, MO(FUNC), KC_ENT,      KC_SPC,  MO(EXTRA), KC_RCTL, KC_RALT, KC_RGUI
),
[GAME] = LAYOUT_split_4x6_5(
  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_BSPC,
  KC_T, KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_LBRC,
  KC_G, KC_LCTL,  KC_A,   KC_S,    KC_D,    KC_F,                        KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,  KC_QUOT,
  KC_B, KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,     TG(GAME),    TG(NUM), KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_NUBS,
                    KC_LGUI,KC_LALT,KC_GRV, MO(FUNC), KC_SPC,      KC_ENT,  MO(EXTRA), KC_RCTL, KC_RALT, KC_RGUI
),
[FUNC] = LAYOUT_split_4x6_5(
  _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                       KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
  KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_F12,
  _______, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                       KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE,
  _______,  KC_EQL, KC_MINS, KC_PLUS, KC_LCBR, KC_RCBR, _______,       _______, KC_LBRC, KC_RBRC, KC_SCLN, KC_COLN, KC_BSLS, _______,
                       _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______
),
[EXTRA] = LAYOUT_split_4x6_5(
  _______, _______ , _______ , _______ , _______ , _______,                       _______,  _______, _______,  _______,  _______, _______,
  _______,  TO(BASE),  TO(NUM),  XXXXXXX,  XXXXXXX, XXXXXXX,                        KC_PGUP, XXXXXXX,   KC_UP, XXXXXXX,C(KC_BSPC), KC_BSPC,
  _______, KC_LALT,  KC_LCTL,  KC_LSFT,  XXXXXXX, KC_CAPS,                        KC_PGDN,  KC_LEFT, KC_DOWN, KC_RGHT,  KC_DEL, KC_BSPC,
  _______, C(KC_Z), C(KC_X), C(KC_C), C(KC_V), XXXXXXX,  _______,       _______,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, _______,
                         _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______
),
};

bool rgb_matrix_indicators_user(void) {
  uint8_t layer = biton32(layer_state);
  switch (layer) {
    case NUM:
      rgb_matrix_set_color_all(NUM_RGB);
      break;
    case GAME:
      rgb_matrix_set_color_all(GAME_RGB);
      break;
    case FUNC:
      rgb_matrix_set_color_all(FUNC_RGB);
      break;
    case EXTRA:
      rgb_matrix_set_color_all(EXTRA_RGB);
      break;
    case BASE_ARROW:
      rgb_matrix_set_color_all(BASE_RGB);
    //   uint8_t wasd[] = {14, 18, 19, 23};
    //   for (uint8_t i = 0; i < 4; i++){
    //     rgb_matrix_set_color(wasd[i],255,0,0);
    //   }
      break;
    default:
      rgb_matrix_set_color_all(BASE_RGB);
      break;
  }
  return true;
};
