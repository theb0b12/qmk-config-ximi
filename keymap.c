#include QMK_KEYBOARD_H
#include "quantum/pointing_device/pointing_device_auto_mouse.h"

enum layer_names {
    _QWERTY,  // 0
    _LOWER,    // 1
    _RAISE,    // 2
    _ADJUST,   // 3
    _MOUSE     // 4
};

enum custom_keycodes {
    LOWER = SAFE_RANGE,
    RAISE,
    ADJUST
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // ┌─────────────────────────────────────────────────────────────────────────────┐
    // │  LAYER 0 — QWERTY                                                           │
    // ├────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬─────┤
    // │  TAB   │   Q    │   W    │   E    │   R    │   T    │   Y    │   U    │  I  │
    // │  LSFT  │   A    │   S    │   D    │   F    │   G    │   H    │   J    │  K  │
    // │  LCTL  │   Z    │   X    │   C    │   V    │   B    │   N    │   M    │  ,  │
    // │                [MUTE] [LGUI] [LOWER] [ENT]  [SPC] [RAISE] [RALT] [MUTE]     │
    // │                              [BTN3] [BTN1] [BTN2]                           │
    // └─────────────────────────────────────────────────────────────────────────────┘
    [_QWERTY] = LAYOUT_ximi(
        // ┌────────┬────────┬────────┬────────┬────────┐   ┌────────┬────────┬────────┬────────┬────────┬────────┐
        //   Row 0 — left                                      Row 0 — right
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        // ├────────┼────────┼────────┼────────┼────────┤   ├────────┼────────┼────────┼────────┼────────┼────────┤
        //   Row 1 — left                                      Row 1 — right
        KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        // ├────────┼────────┼────────┼────────┼────────┤   ├────────┼────────┼────────┼────────┼────────┼────────┤
        //   Row 2 — left                                      Row 2 — right
        KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ESC,
        // └────────┴────────┴────────┴────────┴────────┘   └────────┴────────┴────────┴────────┴────────┴────────┘
        //   Left thumb fan:  [encoder] [GUI]  [LOWER] [ENT]    Right thumb fan: [SPC] [RAISE] [RALT] [encoder]
        KC_MUTE, KC_LGUI, LOWER,   KC_ENT,                      KC_SPC,  RAISE,   KC_RALT, KC_MUTE,
        //   Trackball buttons: [BTN3] [BTN1] [BTN2] [--] [--] [--]
        KC_MS_BTN3, KC_MS_BTN1, KC_MS_BTN2, KC_NO, KC_NO, KC_NO
    ),
 
    // ┌─────────────────────────────────────────────────────────────────────────────┐
    // │  LAYER 1 — LOWER  (numbers + arrows)                                        │
    // ├────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬─────┤
    // │  trns  │   1    │   2    │   3    │   4    │   5    │   6    │   7    │  8  │
    // │  trns  │  ---   │  ---   │  ---   │  ---   │  ---   │  ---   │   ↑    │ --- │
    // │  trns  │  trns  │  trns  │  trns  │  trns  │  trns  │   ←    │   ↓    │  →  │
    // │                [MUTE] [LGUI] [trns] [ENT]   [SPC] [trns] [RALT] [MUTE]      │
    // └─────────────────────────────────────────────────────────────────────────────┘
    [_LOWER] = LAYOUT_ximi(
        // Row 0 — numbers
        KC_TRNS, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
        // Row 1 — arrows (up on home row, rest blank)
        KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_UP,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS,
        // Row 2 — left/down/right on bottom row
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_TRNS, KC_TRNS, KC_TRNS,
        // Thumb fan
        KC_MUTE, KC_LGUI, KC_TRNS, KC_ENT,                      KC_SPC,  KC_TRNS, KC_RALT, KC_MUTE,
        // Trackball buttons (pass-through)
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
    ),
 
    // ┌─────────────────────────────────────────────────────────────────────────────┐
    // │  LAYER 2 — RAISE  (symbols)                                                 │
    // ├────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬─────┤
    // │  ---   │   !    │   @    │   #    │   $    │   %    │   ^    │   &    │  *  │
    // │  ---   │  trns  │  trns  │  trns  │  trns  │  trns  │   -    │   =    │  [  │
    // │  trns  │  trns  │  trns  │  trns  │  trns  │  trns  │   _    │   +    │  {  │
    // │                [MUTE] [LGUI] [trns] [ENT]   [SPC] [trns] [RALT] [MUTE]      │
    // └─────────────────────────────────────────────────────────────────────────────┘
    [_RAISE] = LAYOUT_ximi(
        // Row 0 — shifted number row symbols
        KC_NO,   KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
        // Row 1 — punctuation/brackets
        KC_NO,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, KC_GRV,
        // Row 2 — shifted punctuation/brackets
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_TILD,
        // Thumb fan
        KC_MUTE, KC_LGUI, KC_TRNS, KC_ENT,                      KC_SPC,  KC_TRNS, KC_RALT, KC_MUTE,
        // Trackball buttons
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
    ),
 
    // ┌─────────────────────────────────────────────────────────────────────────────┐
    // │  LAYER 3 — ADJUST  (LOWER + RAISE simultaneously)                           │
    // │  Currently mirrors RAISE — customise for RGB, reset, media, etc.            │
    // └─────────────────────────────────────────────────────────────────────────────┘
    [_ADJUST] = LAYOUT_ximi(
        // Row 0
        KC_NO,   KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
        // Row 1
        KC_NO,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, KC_GRV,
        // Row 2
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_TILD,
        // Thumb fan
        KC_MUTE, KC_LGUI, KC_TRNS, KC_ENT,                      KC_SPC,  KC_TRNS, KC_RALT, KC_MUTE,
        // Trackball buttons
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
    ),
 
    // ┌─────────────────────────────────────────────────────────────────────────────┐
    // │  LAYER 4 — MOUSE  (auto-activated by trackball movement)                    │
    // │  All keys transparent — only thumb BTN1/BTN2 are remapped for convenience   │
    // └─────────────────────────────────────────────────────────────────────────────┘
    [_MOUSE] = LAYOUT_ximi(
        // Row 0
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        // Row 1
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        // Row 2
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        // Thumb fan — BTN1/BTN2 on inner thumb keys for comfortable clicking
        KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_BTN1,                  KC_MS_BTN2, KC_TRNS, KC_TRNS, KC_TRNS,
        // Trackball buttons
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
    )};

#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
};
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LOWER:
            if (record->event.pressed) {
                layer_on(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
        case RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
        case ADJUST:
            if (record->event.pressed) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            return false;
        default:
            break;
    }
    return true;
}

void pointing_device_init_user(void) {
    set_auto_mouse_layer(_MOUSE);
}