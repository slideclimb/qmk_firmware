// Copyright 2022 Diego Palacios (@diepala)
// SPDX-License-Identifier: GPL-2.0

#include QMK_KEYBOARD_H
#include "oneshot.h"

// Aliases.
#define OS_LGUI OSM(MOD_LGUI)
#define OS_LALT OSM(MOD_LALT)
#define OS_LCTL OSM(MOD_LCTL)
#define OS_LSFT OSM(MOD_LSFT)

#define CUT LCTL(KC_X)
#define COPY LCTL(KC_C)
#define PASTE LCTL(KC_V)
#define UNDO LCTL(KC_Z)

enum keycodes {
    OS_SFT = SAFE_RANGE,
    OS_CTL,
    OS_ALT,
    OS_GUI,
};

enum layers {
    DVORAK,
    QWERTY,
    NUMBERS,
    NAVIGATION,
    SYMBOLS,
    FUNCTIONS,
    MOUSE
};

enum combos {
    SN_ENTER,
    TH_BSPC,
    AO_TAB,
    EU_DEL,
    LEFT_ESC,
    RIGHT_ESC,
    THUMBS_MOUSE
};

const uint16_t PROGMEM sn_combo[] = {KC_S, KC_N, COMBO_END};
const uint16_t PROGMEM th_combo[] = {KC_T, KC_H, COMBO_END};
const uint16_t PROGMEM ao_combo[] = {KC_A, KC_O, COMBO_END};
const uint16_t PROGMEM eu_combo[] = {KC_E, KC_U, COMBO_END};
const uint16_t PROGMEM lesc_combo[] = {KC_COMMA, KC_DOT, COMBO_END};
const uint16_t PROGMEM resc_combo[] = {KC_R, KC_C, COMBO_END};
const uint16_t PROGMEM mouse_combo[] = {KC_LSFT, KC_SPC, COMBO_END};


combo_t key_combos[] = {
    [SN_ENTER] = COMBO(sn_combo, KC_ENT),
    [TH_BSPC] = COMBO(th_combo, KC_BSPC),
    [AO_TAB] = COMBO(ao_combo, KC_TAB),
    [EU_DEL] = COMBO(eu_combo, KC_DEL),
    [LEFT_ESC] = COMBO(lesc_combo, KC_ESC),
    [RIGHT_ESC] = COMBO(resc_combo, KC_ESC),
    [THUMBS_MOUSE] = COMBO(mouse_combo, TG(MOUSE)),
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
         KC_MINUS,    KC_A,     KC_O,     KC_E,    KC_U,    KC_I,                            KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_SLSH,
       TG(QWERTY), KC_SCLN,     KC_Q,     KC_J,    KC_K,    KC_X,                            KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_EXLM,
                                   TT(NAVIGATION), KC_LSFT, TT(NUMBERS),             TT(SYMBOLS),  KC_SPC, TT(FUNCTIONS)
    ),
    [QWERTY] = LAYOUT_split_3x6_3(
            KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
            KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
            KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                               KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, TG(QWERTY),
                                                KC_LGUI, KC_SPC, KC_BSPC,          KC_ENT, KC_SPC, KC_RALT
        ),
    [NUMBERS] = LAYOUT_split_3x6_3(
        _______, _______, KC_LCBR, KC_LPRN, KC_LBRC, _______,                          KC_PSLS,    KC_7,    KC_8,    KC_9, KC_PPLS, _______,
        _______, OS_GUI, OS_ALT, OS_CTL, OS_SFT, _______,                          KC_PAST,    KC_4,    KC_5,    KC_6, KC_PMNS, KC_X,
        _______, _______, KC_RCBR, KC_RPRN, KC_RBRC, _______,                           KC_EQL,    KC_1,    KC_2,    KC_3, KC_CIRC, KC_UNDS,
                                            _______, _______, _______,         KC_DOT,  KC_SPC,    KC_0
    ),
    [SYMBOLS] = LAYOUT_split_3x6_3(
        KC_PERC, KC_BSLS,   KC_LT,   KC_GT,  KC_EQL,  KC_GRV,                          _______, KC_RBRC, KC_RPRN, KC_RCBR, _______, _______,
        KC_CIRC, KC_SLSH, KC_LCBR, KC_LPRN, KC_LBRC, KC_MINS,                          _______, OS_SFT, OS_CTL, OS_ALT, OS_GUI, _______,
        KC_ASTR, _______, _______, KC_NUHS, KC_PLUS, KC_EXLM,                          _______, _______, _______, _______, _______, _______,
                                            _______,  KC_SPC, KC_LCTL,        _______, _______, _______
    ),
    [NAVIGATION] = LAYOUT_split_3x6_3(
        _______, _______, _______, _______, _______, _______,                          _______, KC_HOME,   KC_UP,  KC_END,  KC_INS, _______,
        _______, OS_GUI, OS_ALT, OS_CTL, OS_SFT, _______,                          _______, KC_LEFT, KC_DOWN, KC_RGHT,  KC_ENT, _______,
        _______,    UNDO,     CUT,    COPY,   PASTE, _______,                          _______, KC_PGUP, KC_PGDN, _______, _______, _______,
                                            _______, _______, _______,        _______, KC_LCTL, _______
    ),
    [FUNCTIONS] = LAYOUT_split_3x6_3(
          KC_F1,   KC_F2,   KC_F3,   KC_F4,  KC_F10,  KC_F11,                          _______, _______, _______, _______, _______, _______,
          KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F12,                          _______, OS_SFT, OS_CTL, OS_ALT, OS_GUI, _______,
        _______, _______, _______, _______, _______, _______,                          _______, _______, _______, _______, _______, _______,
                                            _______, KC_LCTL, _______,        _______, _______, _______
    ),
    [MOUSE] = LAYOUT_split_3x6_3(
        TG(MOUSE), _______, _______, _______, KC_BTN2, _______,                          _______, KC_WH_D, KC_MS_U, KC_WH_U, _______, _______,
          _______, KC_ACL2, KC_ACL1, KC_ACL0, KC_BTN1, _______,                          _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______,
          _______, _______, _______, _______, KC_BTN3, _______,                          _______, _______, _______, _______, _______, _______,
                                              _______, _______, _______,        _______, _______, _______
    )
};


/*
  [2] = LAYOUT_split_3x6_3(
        _______, _______, _______, _______, _______, _______,                          _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                          _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                          _______, _______, _______, _______, _______, _______,
                                            _______, _______, _______,        _______, _______, _______
    )
*/

bool is_oneshot_cancel_key(uint16_t keycode) {
    switch (keycode) {
    case NUMBERS:
        return true;
    default:
        return false;
    }
}

bool is_oneshot_layer_cancel_key(uint16_t keycode) {
    switch (keycode) {
    case NUMBERS:
        return true;
    default:
        return false;
    }
}

bool is_oneshot_ignored_key(uint16_t keycode) {
    switch (keycode) {
    case NUMBERS:
    case OS_CTL:
    case OS_ALT:
    case OS_GUI:
    case OS_SFT:
        return true;
    default:
        return false;
    }
}

bool is_oneshot_mod_key(uint16_t keycode) {
    switch (keycode) {
    case OS_CTL:
    case OS_ALT:
    case OS_GUI:
    case OS_SFT:
        return true;
    default:
        return false;
    }
}

oneshot_state os_ctrl_state = os_up_unqueued;
oneshot_state os_alt_state = os_up_unqueued;
oneshot_state os_cmd_state = os_up_unqueued;
oneshot_state os_sft_state = os_up_unqueued;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    update_oneshot(
        &os_ctrl_state, KC_LCTL, OS_CTL,
        keycode, record
    );
    update_oneshot(
        &os_alt_state, KC_LALT, OS_ALT,
        keycode, record
    );
    update_oneshot(
        &os_cmd_state, KC_LGUI, OS_GUI,-
        keycode, record
    );
    update_oneshot(
        &os_sft_state, KC_LSFT, OS_SFT,
        keycode, record
    );

    return true;
}

void keyboard_post_init_user(void) {
    debug_enable=true;
}