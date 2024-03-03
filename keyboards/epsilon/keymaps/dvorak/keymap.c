// Copyright 2022 Diego Palacios (@diepala)
// SPDX-License-Identifier: GPL-2.0

#include QMK_KEYBOARD_H

// Aliases.
#define OS_LGUI OSM(MOD_LGUI)
#define OS_LALT OSM(MOD_LALT)
#define OS_LCTL OSM(MOD_LCTL)
#define OS_LSFT OSM(MOD_LSFT)

#define CUT LCTL(KC_X)
#define COPY LCTL(KC_C)
#define PASTE LCTL(KC_V)

enum layers {
    DVORAK,
    QWERTY,
    NUMBERS,
    NAVIGATION,
    SYMBOLS,
    FUNCTIONS,
    MOUSE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     /*
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │Tab│ Q │ W │ E │ R │ T │       │ Y │ U │ I │ O │ P │Bsp│
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │Ctl│ A │ S │ D │ F │ G │       │ H │ J │ K │ L │ ; │ ' │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │Sft│ Z │ X │ C │ V │ B │       │ N │ M │ , │ . │ / │Sft│
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │GUI├───┐           ┌───┤Alt│
      *               └───┤   ├───┐   ┌───┤   ├───┘
      *                   └───┤Bsp│   │Ent├───┘
      *                       └───┘   └───┘
      */
    [DVORAK] = LAYOUT_split_3x6_3(
         KC_ESC, KC_QUOT, KC_COMMA,   KC_DOT,    KC_P,    KC_Y,                            KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSPC,
         KC_TAB,    KC_A,     KC_O,     KC_E,    KC_U,    KC_I,                            KC_D,    KC_H,    KC_T,    KC_N,    KC_S,     KC_ENT,
        KC_LSFT, KC_SCLN,     KC_Q,     KC_J,    KC_K,    KC_X,                            KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_RSFT,
                                  TT(NAVIGATION), KC_LSFT, TT(NUMBERS),             TT(SYMBOLS),  KC_SPC, TT(FUNCTIONS)
    ),
    [NUMBERS] = LAYOUT_split_3x6_3(
        _______, _______, _______, _______, _______, _______,                          _______,    KC_7,    KC_8,    KC_9, _______, _______,
        _______, OS_LGUI, OS_LALT, OS_LCTL, OS_LSFT, _______,                          _______,    KC_4,    KC_5,    KC_6, _______, _______,
        _______, _______, _______, _______, _______, _______,                          _______,    KC_1,    KC_2,    KC_3, _______, _______,
                                            _______, _______, _______,        _______, KC_LCTL,    KC_0
    ),
    [SYMBOLS] = LAYOUT_split_3x6_3(
        _______, KC_BSLS,   KC_LT,   KC_GT,  KC_EQL,  KC_GRV,                          _______, KC_RBRC, KC_RPRN, KC_RCBR, _______, _______,
        _______, KC_SLSH, KC_LCBR, KC_LPRN, KC_LBRC, KC_MINS,                          _______, OS_LSFT, OS_LCTL, OS_LALT, OS_LGUI, _______,
        _______, _______, _______, KC_NUHS, KC_PLUS, KC_EXLM,                          _______, _______, _______, _______, _______, _______,
                                            _______, KC_LCTL, _______,        _______, _______, _______
    ),
    [NAVIGATION] = LAYOUT_split_3x6_3(
        _______, _______, _______, _______, _______, _______,                          _______, KC_HOME,   KC_UP,  KC_END, _______, _______,
        _______, OS_LGUI, OS_LALT, OS_LCTL, OS_LSFT, _______,                          _______, KC_LEFT, KC_DOWN, KC_RGHT,  KC_ENT, _______,
        _______, _______,     CUT,    COPY,   PASTE, _______,                          _______, KC_PGDN, KC_PGUP, _______, _______, _______,
                                            _______, _______, _______,        _______, KC_LCTL, _______
    ),
    [FUNCTIONS] = LAYOUT_split_3x6_3(
          KC_F1,   KC_F2,   KC_F3,   KC_F4,  KC_F10,  KC_F11,                          _______, _______, _______, _______, _______, _______,
          KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F12,                          _______, OS_LSFT, OS_LCTL, OS_LALT, OS_LGUI, _______,
        _______, _______, _______, _______, _______, _______,                          _______, _______, _______, _______, _______, _______,
                                            _______, KC_LCTL, _______,        _______, _______, _______
    ),
};


/*
  [2] = LAYOUT_split_3x6_3(
        _______, _______, _______, _______, _______, _______,                          _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                          _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                          _______, _______, _______, _______, _______, _______,
                                            _______, _______, _______,        _______, _______, _______
    )
*/