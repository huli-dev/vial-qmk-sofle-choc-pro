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
#define DEFAULT_RGB 10, 10, 10
#define GAME_RGB 100, 0, 0

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
  KC_ESC,   KC_1,   KC_2,   KC_3,   KC_4,   KC_5,                           KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_BSPC,
  KC_TAB,   KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,                           KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC,
  MO(BASE_ARROW),KC_A,KC_S, KC_D,   KC_F,   KC_G,                           KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,
  KC_LSFT,  KC_Z,   KC_X,   KC_C,   KC_V,   KC_B, TG(GAME),         TG(NUM),KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,KC_NUBS,
            KC_LGUI,KC_LALT,KC_LCTL,MO(FUNC),KC_ENT,                        KC_SPC, MO(EXTRA),KC_RCTL,KC_RALT,KC_RGUI
),
[BASE_ARROW] = LAYOUT_split_4x6_5(
  _______,  _______,    _______,    _______,    _______, _______,                _______, _______, _______, _______, _______, _______,
  _______, _______,  KC_UP,  _______, _______, _______,                _______, _______, _______, _______, _______, _______,
  _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,                _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______, _______, _______,
                    _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______
),

[NUM] = LAYOUT_split_4x6_5(
  _______, _______, _______, _______, _______, _______,                 _______,  KC_NUM, KC_PSLS,  KC_PAST,  KC_PMNS, _______,
  _______, _______, _______, _______, _______, _______,                  KC_PGUP, KC_P7, KC_P8, KC_P9, KC_PPLS, KC_BSPC,
  _______, _______, _______, _______, _______, _______,                  KC_PGDN,  KC_P4, KC_P5, KC_P6,  KC_PDOT, KC_BSPC,
  _______, _______, _______, _______, _______, _______, _______,      _______,  XXXXXXX, KC_P1, KC_P2, KC_P3,  KC_P0, KC_PENT,
                    _______, _______, _______, _______, _______,      _______,  _______, _______, _______, _______
),
[GAME] = LAYOUT_split_4x6_5(
  KC_GRV,   KC_1,     KC_2,   KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_BSPC,
  KC_TAB,   KC_T,     KC_Q,   KC_W,    KC_E,    KC_R,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_LBRC,
  KC_G,     KC_B,     KC_A,   KC_S,    KC_D,    KC_F,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,  KC_QUOT,
  KC_M,     KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,   _______,     _______, KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_NUBS,
                    KC_LCTL, KC_ESC, KC_LALT, MO(FUNC), KC_SPC,      KC_ENT,  MO(EXTRA), KC_RCTL, KC_RALT, KC_RGUI
),
[FUNC] = LAYOUT_split_4x6_5(
  _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                      KC_F1,   KC_F2,   KC_F3,   KC_F4,  KC_F5,  KC_F6,
  KC_GRV,    KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,                     KC_F7,   KC_F8,   KC_F9,   KC_F10, KC_F11, KC_F12,
  _______, KC_EXLM,LSFT(KC_MINS), KC_TILDE,  KC_AT, KC_PERC,                 _______, _______, _______, _______, _______, _______,
  _______,  KC_EQL, KC_MINS, KC_PLUS, KC_LCBR, KC_RCBR, _______,       _______, RM_VALD, RM_VALU, RALT(KC_MINS), KC_RBRC, KC_BSLS, _______,
                    _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______
),
[EXTRA] = LAYOUT_split_4x6_5(
  A(KC_F4), _______, _______, _______, _______, LCA(KC_DEL),                RM_TOGG,  _______, _______,  _______,  _______, KC_PSCR,
  _______,  TO(BASE),  TO(NUM),  TO(GAME),  XXXXXXX, XXXXXXX,               KC_PGUP,  KC_INS,  KC_UP,   KC_DEL, C(KC_BSPC), KC_BSPC,
  _______, C(KC_Y), C(KC_Z),  XXXXXXX,  XXXXXXX, KC_CAPS,                   KC_PGDN,  KC_LEFT, KC_DOWN, KC_RGHT,  KC_DEL, KC_BSPC,
  _______, C(KC_X), C(KC_C), C(KC_V), XXXXXXX, XXXXXXX,  _______,      _______,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, KC_PWR,
                    _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______
),
};


/*
 * RGB Mapping (other side mirrored)
 * ,-----------------------------------------.
 * |  26  |  25  |  17  |  16  |   7  |   6  |
 * |------+------+------+------+------+------|
 * |  27  |  24  |  18  |  15  |   8  |   5  |
 * |------+------+------+------+------+------|
 * |  28  |  23  |  19  |  14  |   9  |   4  |-------.
 * |------+------+------+------+------+------|  0    |
 * |  29  |  22  |  20  |  13  |  l0  |   3  |-------|
 * `-----------------------------------------/       /
 *            |  21  |  12  |  11  |  2   | /   1   /
 *            |      |      |      |      |/       /
 *            `----------------------------------'
 */

uint8_t wasd[] = {18, 23, 19, 14};
uint8_t numNum[] = {22, 20, 13, 10, 19, 14, 9, 18, 15, 8};
uint8_t numOp[] = {7, 16, 17, 25, 24};
uint8_t funcKeysMaster[] = {25, 17, 16, 7, 6, 24, 18, 15, 8, 5};
uint8_t funcKeySlave[] = {6, 7, 16, 17, 25, 26, 27, 24, 18, 15, 8, 5};
uint8_t centeredArrow[] = {9, 14, 15, 19};

void set_key_color(bool isMaster, uint8_t leds[], uint8_t length, uint8_t red, uint8_t green, uint8_t blue) {
    if (is_keyboard_master() == !isMaster) {
        return;
    }
    for (uint8_t i = 0; i < (int)length; i++) {
        rgb_matrix_set_color(leds[i], red, green, blue);
    }
};

void set_single_key_color(bool isMaster, uint8_t led, uint8_t red, uint8_t green, uint8_t blue) {
    if (is_keyboard_master() == isMaster) {
        rgb_matrix_set_color(led, red, green, blue);
    }
};

void set_base_arrow_key_color(void) {
    rgb_matrix_set_color_all(DEFAULT_RGB);
    set_key_color(true, wasd, 4, 100, 0, 0);
};

void set_game_key_color(void) {
    rgb_matrix_set_color_all(GAME_RGB);
    set_key_color(true, centeredArrow, 4, 100, 100, 100);
};

void set_num_key_color(void) {
    rgb_matrix_set_color_all(DEFAULT_RGB);
    set_key_color(false, numNum, 10, 0, 0, 100);
    set_key_color(false, numOp, 5, 0, 100, 100);
    set_key_color(false, (uint8_t[]) { 27,28 }, 2, 100, 0, 0);
    set_single_key_color(false, 23, 0, 100, 50); // dot
    set_single_key_color(false, 29, 0, 100, 0); // Enter
};

void set_func_key_color(void) {
    rgb_matrix_set_color_all(DEFAULT_RGB);
    set_key_color(true, funcKeysMaster, 10, 100, 0, 0);
    set_key_color(false, funcKeySlave, 12, 100, 0, 0);
};

void set_extra_key_color(void) {
    rgb_matrix_set_color_all(DEFAULT_RGB);
    set_key_color(false, centeredArrow, 4, 0, 0, 100);
    set_single_key_color(false, 5, 0, 100, 100); // Page up
    set_single_key_color(false, 4, 100, 100, 0); // Page down
    set_single_key_color(false, 8, 0, 100, 0); // Insert
    set_single_key_color(false, 18, 100, 0, 0); // Delete
    set_single_key_color(false, 24, 100, 0, 40); // CTRL+Backspace
    set_single_key_color(false, 26, 0, 100, 100); // Print
    set_single_key_color(false, 29, 100, 0, 0); // Poweroff


};

bool rgb_matrix_indicators_user(void) {
    uint8_t layer = get_highest_layer(layer_state);
    switch (layer) {
        case NUM:
            set_num_key_color();
            break;
        case GAME:
            set_game_key_color();
            break;
        case FUNC:
            set_func_key_color();
            break;
        case EXTRA:
            set_extra_key_color();
            break;
        case BASE_ARROW:
            set_base_arrow_key_color();
            break;
        default:
            rgb_matrix_set_color_all(DEFAULT_RGB);
            break;
    }
    return true;
};
