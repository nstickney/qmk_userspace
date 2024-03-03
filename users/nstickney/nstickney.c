/* Copyright 2021 @nstickney
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
#include "nstickney.h"

// Tap Dancing
void dance_layer(tap_dance_state_t *state, void *user_data) {
    switch (state->count) {
        case 1:
            tap_code(KC_APP);
            break;
        case 2:
            layer_invert(NUMP);
            break;
        case 3:
            layer_invert(SYMB);
            break;
        default:
            break;
    }
};

void dance_lock_finished(tap_dance_state_t *state, void *user_data) {
    switch (state->count) {
        case 1:
            register_code(KC_LGUI);
            break;
        case 2:
            register_code(KC_NUM);
            break;
        case 3:
            register_code(KC_CAPS);
            break;
        case 4:
            register_code(KC_SCRL);
            break;
        default:
            break;
    }
};

void dance_lock_reset(tap_dance_state_t *state, void *user_data) {
    switch (state->count) {
        case 1:
            unregister_code(KC_LGUI);
            break;
        case 2:
            register_code(KC_NUM);
            break;
        case 3:
            register_code(KC_CAPS);
            break;
        case 4:
            register_code(KC_SCRL);
            break;
        default:
            break;
    }
};

tap_dance_action_t tap_dance_actions[] = {[LOCKS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_lock_finished, dance_lock_reset), [LAYERS] = ACTION_TAP_DANCE_FN(dance_layer)};

// RGB underglow per-layer hue values
const uint16_t LAYER_HUE[] = {6, 197, 133, 69};

// Initialize RGB underglow (colorful)
void keyboard_post_init_user(void) {
    rgblight_enable_noeeprom();
    rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
    for (uint16_t i = 0; i < 256; ++i) {
        rgblight_sethsv_noeeprom((i + LAYER_HUE[BASE]) % 256, 255, 136);
        wait_ms(8);
    }
};

// Turn on RGB underglow according to active layer
layer_state_t layer_state_set_user(layer_state_t state) {
    uint8_t user_val = rgblight_get_val();
    rgblight_sethsv_noeeprom(LAYER_HUE[get_highest_layer(state)], 255, user_val);
    return state;
};

// Unicode Map
const uint32_t unicode_map[] PROGMEM = {
    [IEX] = 0xA1,   // ¡
    [SS2] = 0xB2,   // ²
    [SS3] = 0xB3,   // ³
    [CUR] = 0xA4,   // ¤
    [EUR] = 0x20AC, // €
    [V14] = 0xBC,   // ¼
    [V12] = 0xBD,   // ½
    [V34] = 0xBE,   // ¾
    [LSQ] = 0x2018, // ‘
    [RSQ] = 0x2019, // ’
    [YEN] = 0xA5,   // ¥
    [MLT] = 0xD7,   // ×
    [A_D] = 0xE4,   // ä
    [A_R] = 0xE5,   // å
    [E_A] = 0xE9,   // é
    [REG] = 0xAE,   // ®
    [THR] = 0xFE,   // þ
    [U_D] = 0xFC,   // ü
    [U_A] = 0xFA,   // ú
    [I_A] = 0xED,   // í
    [O_A] = 0xF3,   // ó
    [O_D] = 0xF6,   // ö
    [O_C] = 0xF4,   // ô
    [LDA] = 0xAB,   // «
    [RDA] = 0xBB,   // »
    [NOT] = 0xAC,   // ¬
    [A_A] = 0xE1,   // á
    [S_S] = 0xDF,   // ß
    [ETH] = 0xF0,   // ð
    [EMD] = 0x2014, // —
    [OEL] = 0x153,  // œ
    [O_S] = 0xF8,   // ø
    [PLC] = 0xB6,   // ¶
    [ACT] = 0xB4,   // ´
    [AEL] = 0xE6,   // æ
    [CPR] = 0xA9,   // ©
    [N_T] = 0xF1,   // ñ
    [MCR] = 0xB5,   // µ
    [C_C] = 0xE7,   // ç
    [IQM] = 0xBF,   // ¿
                    // SHIFTED
    [SS1] = 0xB9,   // ¹
    [GBP] = 0xA3,   // £
    [DIV] = 0xF7,   // ÷
    [AXD] = 0xC4,   // Ä
    [ACR] = 0xC5,   // Å
    [ECA] = 0xC9,   // É
    [UCD] = 0xDC,   // Ü
    [UCA] = 0xDA,   // Ú
    [ICA] = 0xCD,   // Í
    [OCA] = 0xD3,   // Ó
    [OCD] = 0xD6,   // Ö
    [OCC] = 0xD4,   // Ô
    [BKB] = 0xA6,   // ¦
    [ACA] = 0xC1,   // Á
    [SEC] = 0xA7,   // §
    [ETC] = 0xD0,   // Ð
    [END] = 0x2013, // –
    [OEC] = 0x152,  // Œ
    [OCS] = 0xD8,   // Ø
    [DEG] = 0xB0,   // °
    [DIS] = 0xA8,   // ¨
    [AEC] = 0xC6,   // Æ
    [CNT] = 0xA2,   // ¢
    [NCT] = 0xD1,   // Ñ
    [CCC] = 0xC7,   // Ç
    [LDQ] = 0x201C, // “
    [RDQ] = 0x201D, // ”
    [CPL] = 0x1F12F // 🄯
};
