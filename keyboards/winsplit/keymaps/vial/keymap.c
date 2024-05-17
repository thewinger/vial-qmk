// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// enum layer_names {
//     BASE,
// };

enum custom_keycodes {
    NTILDE = QK_KB_0,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
       KC_MPLY,  KC_ESC, KC_GRV, KC_1,  KC_2,  KC_3,  KC_4,  KC_5,                      KC_6,  KC_7,  KC_8,   KC_9,  KC_0,   KC_MINS,  KC_EQL,  KC_BSPC,  KC_DEL,
         KC_PGUP,   KC_TAB,  KC_Q,    KC_W,  KC_E,  KC_R,  KC_T,                      KC_Y,  KC_U,  KC_I,   KC_O,   KC_P,   KC_LBRC,  KC_RBRC,  KC_BSLS,
         KC_PGDN,  CTL_T(KC_ESC), KC_A,     KC_S,  KC_D,  KC_F,  KC_G,                      KC_H,  KC_J,  KC_K,   KC_L,    KC_SCLN, KC_QUOT,  KC_ENT,
                  SC_LSPO, KC_Z,      KC_X,  KC_C,  KC_V,  KC_B,  TO(1),   TO(2),  KC_N,  KC_M,  KC_COMM,KC_DOT,   KC_SLSH,  SC_RSPC,  KC_UP,
       KC_KB_MUTE,   KC_LCTL,                KC_LALT, KC_LGUI,  KC_SPC,             KC_SPC,           KC_RGUI,   KC_RALT,   KC_RCTL,   KC_LEFT,   KC_DOWN,   KC_RGHT
    ),

    [1] = LAYOUT(
           RGB_TOG,  _______, _______, KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,                      KC_F6,  KC_F7,  KC_F8,   KC_F9,  KC_F10,   KC_F11,  KC_F12,  KC_PSCR,  KC_HOME,
         RGB_MOD,    _______,       _______,   _______,  _______,  _______,  _______,                      _______,  KC_P7,  KC_P8,   KC_P9,   _______,   _______,  _______,  _______,
           _______,  _______,     _______,    _______,  _______,  _______,  _______,                      _______,  KC_4,  KC_P5,   KC_P6,    _______, _______,  _______,
                     _______,    _______,     _______,  _______,  _______,  _______,  _______,  _______,  NTILDE,  KC_P3,  KC_P2, KC_P1,   KC_P0,  _______,  _______,
       _______,   _______,                _______, _______,  _______,             _______,           _______,   _______,   _______,   _______,   _______,   _______
    ),

    [2] = LAYOUT(
           _______,  _______, _______, _______,  _______,  _______,  _______,  _______,                      _______,  _______,  _______,   _______,  _______,   _______,  _______,  _______,  _______,
         _______,    _______,       _______,   _______,  _______,  _______,  _______,                      _______,  _______,  _______,   _______,   _______,   _______,  _______,  _______,
           _______,  _______,     _______,    _______,  _______,  _______,  _______,                      _______,  _______,  _______,   _______,    _______, _______,  _______,
                     _______,    _______,     _______,  _______,  _______,  _______,  _______,  _______,  NTILDE,  _______,  _______,_______,   _______,  _______,  _______,
       _______,   _______,                _______, _______,  _______,             _______,           _______,   _______,   _______,   _______,   _______,   _______
    ),

    [3] = LAYOUT(
           _______,  _______, _______, _______,  _______,  _______,  _______,  _______,                      _______,  _______,  _______,   _______,  _______,   _______,  _______,  _______,  _______,
         _______,    _______,       _______,   _______,  _______,  _______,  _______,                      _______,  _______,  _______,   _______,   _______,   _______,  _______,  _______,
           _______,  _______,     _______,    _______,  _______,  _______,  _______,                      _______,  _______,  _______,   _______,    _______, _______,  _______,
                     _______,    _______,     _______,  _______,  _______,  _______,  _______,  _______,  NTILDE,  _______,  _______,_______,   _______,  _______,  _______,
       _______,   _______,                _______, _______,  _______,             _______,           _______,   _______,   _______,   _______,   _______,   _______
    ),
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] =   { ENCODER_CCW_CW(KC_VOLU, KC_VOLD) },
    [1] =   { ENCODER_CCW_CW(KC_VOLU, KC_VOLD) },
    [2] =   { ENCODER_CCW_CW(KC_VOLU, KC_VOLD) },
    [3] =   { ENCODER_CCW_CW(KC_VOLU, KC_VOLD) },
};
#endif


bool process_record_user (uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case NTILDE: // if the user toggled per-layer RGB, update the config and refresh the RGB color
            if(record->event.pressed) {
                if ((get_mods() & MOD_BIT(KC_LSFT)) == MOD_BIT(KC_LSFT)) {
                    register_code (KC_GRV);
                    unregister_code (KC_GRV);
                    tap_code(KC_N);
                } else {
                    register_code (KC_LSFT);
                    register_code (KC_GRV);
                    unregister_code (KC_GRV);
                    unregister_code (KC_LSFT);
                    tap_code(KC_N);
                }
            }
            return false;
            break;
    }
    return true;
}


#if defined(RGBLIGHT_ENABLE)
void keyboard_post_init_user(void) {
  rgb_matrix_enable_noeeprom(); // Enables RGB, without saving settings
  rgb_matrix_mode_noeeprom(RGB_MATRIX_TYPING_HEATMAP);
}
#endif
