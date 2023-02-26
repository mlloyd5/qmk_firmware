/**
 * Copyright 2021 Charly Delay <charly@codesink.dev> (@0xcharly)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

enum charybdis_keymap_layers {
    LAYER_BASE = 0,
    LAYER_LOWER,
    LAYER_RAISE,
    LAYER_MOUSE,
    LAYER_RESET,
    LAYER_MOVEMENT,
    LAYER_WINBASE,
};

#define LOWER MO(LAYER_LOWER)
#define RAISE MO(LAYER_RAISE)
#define MOUSE MO(LAYER_MOUSE)
#define RESET MO(LAYER_RESET)
#define MOVMT MO(LAYER_MOVEMENT)
#define WINBASE DF(LAYER_WINBASE)

// for all base layers
#define Q_ALT LALT_T(KC_Q)
#define SC_ALT LALT_T(KC_SCLN)
#define MSE_DOT LT(MOUSE, KC_DOT)
#define MINS_MEH MEH_T(KC_MINS)
#define BSLS_HYPR HYPR_T(KC_BSLS)

// for default layer
#define G_ESC LGUI_T(KC_ESC)
#define G_QUOT RGUI_T(KC_QUOTE)
#define Z_CTRL LCTL_T(KC_Z)
#define SLSH_CTRL RCTL_T(KC_SLSH)

// for winbase default
#define CTRL_ESC LCTL_T(KC_ESC)
#define CTRL_QUOT RCTL_T(KC_QUOTE)
#define Z_GUI LGUI_T(KC_Z)
#define SLSH_GUI RGUI_T(KC_SLSH)

#define DPI_MOD POINTER_DEFAULT_DPI_FORWARD
#define DPI_RMOD POINTER_DEFAULT_DPI_REVERSE
#define SNIPING SNIPING_MODE
#define DRGSCRL DRAGSCROLL_MODE
#define CHARYBDIS_AUTO_SNIPING_ON_LAYER LAYER_MOUSE

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_BASE] = LAYOUT_charybdis_4x6(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       KC_HYPR,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,       KC_6,    KC_7,    KC_8,    KC_9,   KC_0,   KC_MEH,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       BSLS_HYPR,  Q_ALT,   KC_W,    KC_F,    KC_P,    KC_B,       KC_J,    KC_L,    KC_U,    KC_Y,   SC_ALT, MINS_MEH,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        G_ESC,     KC_A,    KC_R,    KC_S,    KC_T,    KC_G,       KC_M,    KC_N,    KC_E,    KC_I,   KC_O,   G_QUOT,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       SC_LSPO,    Z_CTRL,  KC_X,    KC_C,    KC_D,    KC_V,       KC_K,    KC_H, KC_COMM, MSE_DOT, SLSH_CTRL, SC_RSPC,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                   KC_UNDS, KC_SPC,   KC_EQL,    KC_TAB,  KC_ENT,
                                           KC_BSPC,   LOWER,     RAISE
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [LAYER_LOWER] = LAYOUT_charybdis_4x6(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       KC_TILD, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,    KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_UNDS,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       RGB_MOD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    KC_LBRC,   KC_P7,   KC_P8,   KC_P9, KC_RBRC, KC_NUM,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       RGB_TOG, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,    KC_PPLS,   KC_P4,   KC_P5,   KC_P6, KC_PMNS, KC_PEQL,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
      RGB_RMOD, MOVMT,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    KC_PAST,   KC_P1,   KC_P2,   KC_P3, KC_PSLS, KC_PDOT,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, KC_P0,
                                           XXXXXXX, _______,    _______
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [LAYER_RAISE] = LAYOUT_charybdis_4x6(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
        KC_F12,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,      KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       _______, KC_EXLM, KC_AT, KC_BSLS,  KC_CIRC,  KC_PIPE,    RESET,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_VOLU,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       _______, KC_HASH,  KC_DLR, KC_LCBR, KC_RCBR, KC_GRV,     XXXXXXX, KC_RGUI, KC_RCTL, KC_RSFT, KC_RALT, KC_MUTE,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       _______, KC_PERC, KC_COLN, KC_LBRC, KC_RBRC, KC_TILD,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_VOLD,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  _______, _______, _______,    _______, _______,
                                           _______, _______,    _______
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),

    [LAYER_MOUSE] = LAYOUT_charybdis_4x6(
    // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
          KC_F12,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,      KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
    // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DPI_MOD, DPI_RMOD,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
         _______, XXXXXXX, XXXXXXX, KC_DOWN, KC_UP,   KC_HOME,    KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX, XXXXXXX, KC_WH_U,
    // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
         _______, XXXXXXX, XXXXXXX, KC_PGDN,  KC_PGUP, KC_END,    SNIPING, KC_BTN1, KC_BTN2, _______, XXXXXXX, KC_WH_D,
    // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                    DRGSCRL, KC_BTN1, KC_BTN2,    XXXXXXX, G(KC_V),
                                             KC_LEFT, KC_RGHT,    G(KC_C)
    //                            ╰───────────────────────────╯ ╰──────────────────╯
    ),

    [LAYER_RESET] = LAYOUT_charybdis_4x6(
    // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,
    // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,
    // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
         XXXXXXX, XXXXXXX, EE_CLR,  QK_BOOT,  DB_TOGG, XXXXXXX,    XXXXXXX, DB_TOGG, QK_BOOT, EE_CLR,  XXXXXXX, XXXXXXX,
    // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
         XXXXXXX, XXXXXXX, XXXXXXX, QK_RBT,  XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, QK_RBT,  XXXXXXX,  XXXXXXX, XXXXXXX,
    // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                    CG_TOGG, WINBASE, XXXXXXX,    XXXXXXX, XXXXXXX,
                                             XXXXXXX, XXXXXXX,    _______
    //                            ╰───────────────────────────╯ ╰──────────────────╯
    ),

    [LAYER_MOVEMENT] = LAYOUT_charybdis_4x6(
    // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,
    // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, S(G(KC_TAB)), G(KC_TAB), G(KC_TILD), S(G(KC_TILD)),  XXXXXXX, XXXXXXX,
    // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
         XXXXXXX, XXXXXXX, XXXXXXX, KC_PGDN,  KC_PGUP, KC_HOME,  KC_LEFT, KC_UP,  KC_DOWN, KC_RIGHT, XXXXXXX, XXXXXXX,
    // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
         XXXXXXX, _______, KC_LALT, KC_LCTL,  KC_LGUI, KC_END,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, KC_RSFT,
    // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                    XXXXXXX, XXXXXXX, XXXXXXX,    KC_RCTL, KC_RGUI,
                                             XXXXXXX, _______,    KC_RALT
    //                            ╰───────────────────────────╯ ╰──────────────────╯
    ),

    [LAYER_WINBASE] = LAYOUT_charybdis_4x6(
    // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       KC_HYPR,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,       KC_6,    KC_7,    KC_8,    KC_9,   KC_0,   KC_MEH,
    // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       BSLS_HYPR,    Q_ALT,   KC_W,    KC_F,    KC_P,    KC_B,       KC_J,    KC_L,    KC_U,    KC_Y,   SC_ALT, MINS_MEH,
    // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       CTRL_ESC,   KC_A,    KC_R,    KC_S,    KC_T,    KC_G,       KC_M,    KC_N,    KC_E,    KC_I,   KC_O,   CTRL_QUOT,
    // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       SC_LSPO,    Z_GUI,  KC_X,    KC_C,    KC_D,    KC_V,       KC_K,    KC_H, KC_COMM, MSE_DOT, SLSH_GUI,  SC_RSPC,
    // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                   KC_UNDS, KC_SPC,   KC_EQL,    KC_TAB,  KC_ENT,
                                           KC_BSPC,   LOWER,     RAISE
    //                            ╰───────────────────────────╯ ╰──────────────────╯
    ),
};

// Shift + backspace = delete
uint8_t mod_state;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Store the current modifier state in the variable for later reference
    mod_state = get_mods();
    switch (keycode) {

    case KC_BSPC:
        {
        // Initialize a boolean variable that keeps track
        // of the delete key status: registered or not?
        static bool delkey_registered;
        if (record->event.pressed) {
            // Detect the activation of either shift keys
            if (mod_state & MOD_MASK_SHIFT) {
                // First temporarily canceling both shifts so that
                // shift isn't applied to the KC_DEL keycode
                del_mods(MOD_MASK_SHIFT);
                register_code(KC_DEL);
                // Update the boolean variable to reflect the status of KC_DEL
                delkey_registered = true;
                // Reapplying modifier state so that the held shift key(s)
                // still work even after having tapped the Backspace/Delete key.
                set_mods(mod_state);
                return false;
            }
        } else { // on release of KC_BSPC
            // In case KC_DEL is still being sent even after the release of KC_BSPC
            if (delkey_registered) {
                unregister_code(KC_DEL);
                delkey_registered = false;
                return false;
            }
        }
        // Let QMK process the KC_BSPC keycode as usual outside of shift
        return true;
    }

    }
    return true;
};
// clang-format on
