// Copyright 2022 beekeeb
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layer_names {
    BASE_LAYER,
    NUMBER_LAYER,
    SYMBOL_LAYER,
    NAVIGATION_LAYER
};

// Left-hand home row mods
#define HOME_TAB LGUI_T(KC_A)
#define HOME_S LALT_T(KC_S)
#define HOME_D LCTL_T(KC_D)
#define HOME_F LSFT_T(KC_F)

// Right-hand home row mods
#define HOME_J RSFT_T(KC_J)
#define HOME_K RCTL_T(KC_K)
#define HOME_L LALT_T(KC_L)
#define HOME_SCLN RGUI_T(KC_SCLN)

// Left-hand home row mods
#define NUM_LGUI LGUI_T(KC_1)
#define NUM_LALT LALT_T(KC_2)
#define NUM_LCTL LCTL_T(KC_3)
#define NUM_LSFT LSFT_T(KC_4)

// Right-hand home row mods
#define NUM_RSFT RSFT_T(KC_DOWN)
#define NUM_RCTL RCTL_T(KC_UP)
#define NUM_RALT RALT_T(KC_RIGHT)
#define NUM_RGUI RGUI_T(XXXXXXX)

#define LAY_UP_ENT LT(NUMBER_LAYER, KC_ENT)
#define LAY_DN_ENT LT(SYMBOL_LAYER, KC_ENT)


/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
 *  You can use _______ in place for KC_TRNS (transparent)   *
 *  Or you can use XXXXXXX for KC_NO (NOOP)                  *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

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
      *               └───┤Bsp├───┐   ┌───┤Ent├───┘
      *                   └───┤   │   │   ├───┘
      *                       └───┘   └───┘
      */
    [BASE_LAYER] = LAYOUT_split_3x6_3(
        KC_ESCAPE,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,      XXXXXXX,
        KC_TAB, KC_A,  HOME_S,  HOME_D,  HOME_F,  KC_G,                                       KC_H,    HOME_J,  HOME_K,  HOME_L,  KC_SCLN, KC_QUOT,
        KC_LEFT_GUI, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                                       KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,   XXXXXXX,
                                            XXXXXXX, KC_BSPC, LAY_DN_ENT,           LAY_UP_ENT,  KC_SPC,  DF(NAVIGATION_LAYER)
    ),

    [NUMBER_LAYER] = LAYOUT_split_3x6_3(
        _______,  KC_1,     KC_2,       KC_3,       KC_4,       KC_5,                                    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  _______,
        _______,  NUM_LGUI, NUM_LALT,   NUM_LCTL,   NUM_LSFT,   KC_5,                                   KC_6,     KC_7,    KC_8,    KC_9,    KC_0, _______,
        _______,  _______,  _______,    _______,    _______,    _______,                                 _______, _______, _______, _______, _______, _______,
                                                    _______,    _______,    _______,           _______,  _______,  _______
    ),

    [SYMBOL_LAYER] = LAYOUT_split_3x6_3(
        _______, _______, _______, _______, LSFT(KC_LEFT_BRACKET), _______,                             _______,    RSFT(KC_RIGHT_BRACKET),  _______,    KC_MINUS,    KC_EQUAL,  _______,
        _______, _______, _______, _______, LSFT(KC_9),            _______,                             _______,    RSFT(KC_0),             _______,  _______,  _______, _______,
        DT_DOWN, DT_PRNT, DT_UP, _______, KC_LEFT_BRACKET,       _______,                             _______,    KC_RIGHT_BRACKET,       _______, _______, _______, _______,
                                            _______,               _______, KC_ESCAPE,        _______,  _______,    _______
    ),
    [NAVIGATION_LAYER] = LAYOUT_split_3x6_3(
        _______, _______, _______, KC_PGUP, _______, _______,                             _______, _______, KC_UP,    _______,  _______, _______,
        KC_TAB, _______, KC_HOME, KC_PGDN, KC_END, _______,                             _______, KC_LEFT, KC_DOWN,  KC_RIGHT, _______, _______,
        _______, _______, _______, _______, _______, _______,                             _______, _______, _______,  _______,  _______, _______,
                                            _______, _______, KC_ESCAPE,        _______,  _______, DF(BASE_LAYER)
    )
};