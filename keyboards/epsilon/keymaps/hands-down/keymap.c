#include QMK_KEYBOARD_H

// Aliases.
// One shot mods
#define OS_LGUI OSM(MOD_LGUI)
#define OS_LALT OSM(MOD_LALT)
#define OS_LCTL OSM(MOD_LCTL)
#define OS_LSFT OSM(MOD_LSFT)

#define LFT_GUI MT(MOD_LGUI, KC_R)
#define LFT_ALT MT(MOD_LALT, KC_S)
#define LFT_CTL MT(MOD_LCTL, KC_N)
#define LFT_SFT MT(MOD_LSFT, KC_T)

#define RGT_SFT MT(MOD_LSFT, KC_A)
#define RGT_CTL MT(MOD_LCTL, KC_E)
#define RGT_ALT MT(MOD_LALT, KC_I)
#define RGT_GUI MT(MOD_LGUI, KC_H)

// dvorak home row mods
#define D_LFT_GUI MT(MOD_LGUI, KC_A)
#define D_LFT_ALT MT(MOD_LALT, KC_O)
#define D_LFT_CTL MT(MOD_LCTL, KC_E)
#define D_LFT_SFT MT(MOD_LSFT, KC_U)

#define D_RGT_SFT MT(MOD_LSFT, KC_H)
#define D_RGT_CTL MT(MOD_LCTL, KC_T)
#define D_RGT_ALT MT(MOD_LALT, KC_N)
#define D_RGT_GUI MT(MOD_LGUI, KC_S)

// shortcuts
#define OPN_DBG LALT(KC_5)
#define OPN_RUN LALT(KC_4)
#define NAV_TO LCTL(KC_B)

#define CUT LCTL(KC_X)
#define COPY LCTL(KC_C)
#define PASTE LCTL(KC_V)
#define UNDO LCTL(KC_Z)
// IntelliJ delete line shortcut
#define DEL_LIN LCTL(KC_Y)

enum layers {
    HANDS_DOWN,
    DVORAK,
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

const uint16_t PROGMEM sn_combo[] = {RGT_GUI, RGT_ALT, COMBO_END};
const uint16_t PROGMEM th_combo[] = {RGT_CTL, RGT_SFT, COMBO_END};
const uint16_t PROGMEM ao_combo[] = {LFT_GUI, LFT_ALT, COMBO_END};
const uint16_t PROGMEM eu_combo[] = {LFT_CTL, LFT_SFT, COMBO_END};
const uint16_t PROGMEM lesc_combo[] = {KC_F, KC_M, COMBO_END};
const uint16_t PROGMEM resc_combo[] = {KC_Q, KC_QUOT, COMBO_END};
const uint16_t PROGMEM mouse_combo[] = {QK_REP, KC_SPC, COMBO_END};


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
    [HANDS_DOWN] = LAYOUT_split_3x6_3(
           CW_TOGG, KC_SCLN,    KC_F,    KC_M,    KC_P,    KC_V,                          KC_SLSH,  KC_DOT,    KC_Q, KC_QUOT,    KC_Z,  KC_EQL,
           KC_W,    LFT_GUI, LFT_ALT, LFT_CTL, LFT_SFT,    KC_B,                         KC_COMMA, RGT_SFT, RGT_CTL, RGT_ALT, RGT_GUI,    KC_J,
        TO(DVORAK),    KC_X,    KC_C,    KC_L,    KC_D,    KC_G,                         KC_MINUS,    KC_U,    KC_O,    KC_Y,    KC_K, KC_EXLM,
                                  TT(NAVIGATION), QK_REP, TT(NUMBERS),             TT(SYMBOLS),  KC_SPC, TT(FUNCTIONS)
    ),
    [DVORAK] = LAYOUT_split_3x6_3(
        CW_TOGG, KC_QUOT, KC_COMMA,   KC_DOT,    KC_P,    KC_Y,                            KC_F,    KC_G,    KC_C,    KC_R,    KC_SLSH,  KC_EQL,
        KC_MINUS, D_LFT_GUI,  D_LFT_ALT,  D_LFT_CTL, D_LFT_SFT,    KC_I,                            KC_D, D_RGT_SFT, D_RGT_CTL, D_RGT_ALT, D_RGT_GUI, KC_L,
        TO(HANDS_DOWN), KC_SCLN,     KC_Q,     KC_J,    KC_K,    KC_X,                            KC_B,    KC_M,    KC_W,    KC_V,    KC_Z, KC_EXLM,
                                TT(NAVIGATION), QK_REP, TT(NUMBERS),             TT(SYMBOLS),  KC_SPC, TT(FUNCTIONS)
        ),
    [NUMBERS] = LAYOUT_split_3x6_3(
        _______, _______, KC_LCBR, KC_LPRN, KC_LBRC, _______,                          KC_PSLS,    KC_7,    KC_8,    KC_9, KC_PPLS, _______,
        _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_COMMA,                         KC_PAST,    KC_4,    KC_5,    KC_6, KC_PMNS, KC_X,
        _______, _______, KC_RCBR, KC_RPRN, KC_RBRC, _______,                           KC_EQL,    KC_1,    KC_2,    KC_3, KC_CIRC, KC_UNDS,
                                            _______, _______, _______,         KC_DOT,  KC_SPC,    KC_0
    ),
    [SYMBOLS] = LAYOUT_split_3x6_3(
        _______, KC_PERC,   KC_LT,   KC_GT,  KC_EQL,  KC_GRV,                          _______, KC_RBRC, KC_RPRN, KC_RCBR, _______, _______,
        KC_CIRC, KC_SLSH, KC_LCBR, KC_LPRN, KC_LBRC, KC_MINS,                          _______, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, _______,
        _______, KC_ASTR, KC_HASH, KC_BSLS, KC_PLUS, KC_EXLM,                          _______, _______, _______, _______, _______, _______,
                                            _______,  KC_SPC, _______,        _______, _______, _______
    ),
    [NAVIGATION] = LAYOUT_split_3x6_3(
        _______, _______, DEL_LIN,KC_PAUSE, KC_MUTE, KC_VOLU,                          _______, _______, KC_HOME,  KC_END,  KC_INS, _______,
        _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_VOLD,                           NAV_TO, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT,  KC_ENT,
        _______,    UNDO,     CUT,    COPY,   PASTE, _______,                          _______, _______, KC_PGDN, KC_PGUP, _______, _______,
                                            _______, _______, _______,        _______, _______, _______
    ),
    [FUNCTIONS] = LAYOUT_split_3x6_3(
          KC_F1,   KC_F2,   KC_F3,   KC_F4,  KC_F10,  KC_F11,                          _______, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, _______,
          KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F12,                           NAV_TO, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, _______,
        _______, _______, _______, _______, _______, _______,                          _______, OPN_DBG, OPN_RUN, _______, _______, _______,
                                            _______,  KC_TAB, _______,        _______, _______, _______
    ),
    [MOUSE] = LAYOUT_split_3x6_3(
        TG(MOUSE), _______, _______, _______, KC_BTN2, _______,                          _______, _______, KC_WH_D, KC_WH_U, _______, _______,
          _______, KC_ACL0, KC_ACL1, KC_ACL2, KC_BTN1, _______,                          _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______,
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
