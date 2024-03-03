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
#pragma once
#include QMK_KEYBOARD_H

// Specialty keycodes
#define CC_ESC LCTL_T(KC_ESC)
#define CC_QUOT RCTL_T(KC_QUOT)
#define AC_SLSH LALT_T(KC_SLSH)
#define AC_EQL RALT_T(KC_EQL)
#define FC_BSLS LT(FCTN, KC_BSLS)
#define FC_MINS LT(FCTN, KC_MINS)

// Layers
enum layers {
    BASE,  // Base layer
    SYMB,  // Symbols
    NUMP,  // Numpad
    FCTN   // Function
};

// Tap dance
enum dances {
    LOCKS,  // Activate NUM/CAPS/SCROLL lock
    LAYERS  // Activate NUMP and SYMB layers
};

// Unicode Map
enum unicode_names {
	// Used on base

	// Used on US-International
	IEX, SS2, SS3, CUR, EUR, V14, V12, V34, LSQ, RSQ, YEN, MLT,
	A_D, A_R, E_A, REG, THR, U_D, U_A, I_A, O_A, O_D, O_C, LDA, RDA, NOT,
	A_A, S_S, ETH, EMD, OEL, O_S, PLC, ACT,
	AEL, CPR, N_T, MCR, C_C, IQM,

	// Used on US-International with Shift
	SS1, GBP, DIV,
	AXD, ACR, ECA, UCD, UCA, ICA, OCA, OCD, OCC, BKB,
	ACA, SEC, ETC, END, OEC, OCS, DEG, DIS,
	AEC, CNT, NCT, CCC,

	// Added to US-International

	// Added to US-International with Shift
	LDQ, RDQ,
	CPL
};
