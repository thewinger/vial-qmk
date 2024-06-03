// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// Initialize variable holding the binary
// representation of active modifiers.
uint8_t mod_state;

enum layer_names {
    _BASE,
    _LOWER,
    _RAISE,
    _ADJUST,
};

enum custom_keycodes {
    B_NTIL = QK_KB_0,
    B_MUTE,
};



#define CTL_ESC LCTL_T(KC_ESC)
#define LT1_BSPC LT(1, KC_BSPC)
#define LT1_SPC LT(1, KC_SPC)
#define LT2_SPC LT(2, KC_SPC)
#define LT2_BSPC LT(2, KC_BSPC)
#define LT3_BSPC LT(3, KC_BSPC)
#define LT3_DEL LT(3, KC_DEL)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    //,-------,-------,-------,-------,-------,-------,-------,-------,               ,-------,-------,-------,-------,-------,-------,-------,-------,-------,
    //|       |       |       |       |       |       |       |       |               |       |       |       |       |       |       |       |       |       |
    //|-------+       --------+-------+-------+-------+-------+-------+               ,-------+-------+-------+-------+-------+-------+-------+-------+-------`
    //|       |               |       |       |       |       |       |               |       |       |       |       |       |       |       |
    //|-------+               +-------+-------+-------+-------+-------+-------,-------,-------+-------+-------+-------+-------+-------+-------+
    //|       |               |       |       |       |       |       |       |       |       |       |       |       |       |       |       |
    //|-------+               +-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
    //|       |               |       |       |       |       |               |               |       |       |       |       |       |       |
    //`-------`               `-------`       `-------`-------`---------------`---------------`-------`-------`-------`-------`-------`-------

    [0] = LAYOUT(
        KC_MPLY,    CW_TOGG, KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5,                KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, KC_DEL,
        KC_PGUP,             KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T,                KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS,
        KC_MPLY,      LCTL_T(KC_ESC),KC_A, KC_S, KC_D, KC_F, KC_G,                KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT,
                            SC_LSPO, KC_Z, KC_X, KC_C, KC_V, KC_B, MO(1),  MO(2), KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, SC_RSPC, KC_UP,
        B_MUTE,                   KC_LCTL, KC_LALT, KC_LGUI, KC_SPC, LT2_BSPC, KC_RGUI, KC_RALT,    KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT),

    [1] = LAYOUT(
        _______,    _______, _______, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,            KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, _______, _______,
        KC_HOME, _______, _______, KC_UP, _______, _______, _______, _______, KC_P7, KC_P8, KC_P9, _______,	_______, _______, _______,
                 KC_END, _______, KC_LEFT, KC_DOWN, KC_RIGHT, _______, _______, _______, KC_P4, KC_P5, KC_P6, _______, _______, _______,
                 _______, _______, _______, _______, _______, _______, _______, _______, B_NTIL, KC_P1, KC_P2, KC_P3, KC_P0, _______, _______,
                 _______, _______, _______, _______, _______, LT3_BSPC, _______, _______, _______, _______, _______, _______),

    [2] = LAYOUT(_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MPRV, KC_MNXT, KC_MPLY,
                 _______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_VOLD, KC_VOLU, _______,
                 _______, _______, _______, _______, _______, _______, _______, _______, B_NTIL, _______, _______, _______, _______, _______, _______,
                 _______, _______, _______, _______, LT3_DEL, _______, _______, _______, _______, _______, _______, _______),

    [3] = LAYOUT(_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, QK_BOOT,
                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),
};

// clang-format on
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Store the current modifier state in the variable for later reference
    mod_state = get_mods();
    switch (keycode) {
        case B_NTIL:
            if (record->event.pressed) {
                if (mod_state & MOD_MASK_SHIFT) {
                    register_code(KC_GRV);
                    unregister_code(KC_GRV);
                    tap_code(KC_N);
                } else {
                    register_code(KC_LSFT);
                    register_code(KC_GRV);
                    unregister_code(KC_GRV);
                    unregister_code(KC_LSFT);
                    tap_code(KC_N);
                }
            }
            return false;
            break;
        case B_MUTE:
            if (record->event.pressed) {
                register_code(KC_LSFT);
                register_code(KC_LGUI);
                tap_code(KC_M);
                unregister_code(KC_LSFT);
                unregister_code(KC_LGUI);
            }
            return false;
            break;
    }
    return true;
}

// const uint16_t PROGMEM combo_mo1[] = {KC_SPC, KC_LGUI, COMBO_END};
// combo_t key_combos[COMBO_COUNT] = {
//     COMBO(combo_mo1, MO(1)),
// };

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [1] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [2] = {ENCODER_CCW_CW(LGUI(KC_Z), LSG(KC_Z))},
    [3] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
};
#endif

#if defined(RGBLIGHT_ENABLE)
void keyboard_post_init_user(void) {
    rgb_matrix_enable_noeeprom(); // Enables RGB, without saving settings
    rgb_matrix_mode_noeeprom(RGB_MATRIX_TYPING_HEATMAP);
}
#endif
