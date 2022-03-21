#include QMK_KEYBOARD_H
#include "keymap_german.h"
#include "./aliases.h"

/*
#define _DEFAULT 0
#define _SPECIAL 1
#define _FN 2
#define _QWERTZ 3
#define _GAMING 4
#define _PRACT 5
#define _PRACTSP 6
#define _NAV 7*/

enum custom_keycodes{
    _COLEMAK,
    _SPECIAL,
    _FN,
    _QWERTZ,
    _GAMING,
    _PRACT,
    _PRACTSP,
    _NAV,
};

#define DEFAULT MO(_DEFAULT)
#define SPECIAL MO(_SPECIAL)
#define NAV MO(_NAV)
#define FN MO(_FN)
#define QWERTZ TG(_QWERTZ)
#define GAMING TG(_GAMING)
#define PRACT TG(_PRACT)
#define PRACTSP MO(_PRACTSP)

const key_override_t bigss_key_override = ko_make_with_layers_negmods_and_options(MOD_MASK_SHIFT, DE_SS, S(RALT(DE_SS)), ~0, KC_NO, ko_option_no_reregister_trigger);
// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
	&bigss_key_override,
	NULL // Null terminate the array of overrides!
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	
    [_COLEMAK] = LAYOUT_5x6(
        KC_ESC , KC_1  , KC_2  , KC_3  , KC_4  , KC_5  ,                         KC_6  , KC_7  , KC_8  , KC_9  , KC_0  ,XXXXXXX,
        KC_TAB , DE_Q  , DE_W  , DE_F  , DE_P  , DE_B  ,                         DE_J  , DE_L  , DE_U  , DE_Y  ,DE_SCLN,XXXXXXX,
        KC_LSFT, DE_A  , DE_R  , DE_S  , DE_T  , DE_G  ,                         DE_M  , DE_N  , DE_E  , DE_I  , DE_O  ,KC_ENT ,
        KC_LCTL, DE_Z  , DE_X  , DE_C  , DE_D  , DE_V  ,                         DE_K  , DE_H  ,DE_COMM,DE_DOT ,DE_SLSH,XXXXXXX,
                        XXXXXXX,XXXXXXX,                                                        XXXXXXX,XXXXXXX,
                                KC_LCTL,KC_SPC ,                                        KC_LSFT,SPECIAL,
                                        GAMING ,  NAV  ,                          FN   ,XXXXXXX,
                                         PRACT ,KC_LGUI,                        KC_LALT,QWERTZ 
    ),
	
    [_QWERTZ] = LAYOUT_5x6(
        KC_ESC , KC_1  , KC_2  , KC_3  , KC_4  , KC_5  ,                         KC_6  , KC_7  , KC_8  , KC_9  , KC_0  ,XXXXXXX,
        KC_TAB , DE_Q  , DE_W  , DE_E  , DE_R  , DE_T  ,                         DE_Z  , DE_U  , DE_I  , DE_O  , KC_P  ,KC_PLUS,
        KC_LSFT, DE_A  , DE_S  , DE_D  , DE_F  , DE_G  ,                         DE_H  , DE_J  , DE_K  , DE_L  ,DE_HASH,KC_ENT ,
        KC_LCTL, DE_Y  , DE_X  , DE_C  , DE_V  , DE_B  ,                         DE_N  , DE_M  ,DE_COMM,DE_DOT ,DE_MINS,DE_HASH,
                        DE_LABK,DE_CIRC,                                                        XXXXXXX,XXXXXXX,
                                _______,_______,                                        _______,_______,
                                        _______,_______,                        _______,_______,
                                        _______,_______,                        _______,_______
    ),
	
    [_GAMING] = LAYOUT_5x6(
         KC_5  ,KC_ESC , KC_1  , KC_2  , KC_3  , KC_4  ,                        _______,_______,_______,_______,_______,_______,
         DE_T  ,KC_TAB , DE_Q  , DE_W  , DE_E  , DE_R  ,                        _______,_______,_______,_______,_______,_______,
         DE_G  ,KC_LSFT, DE_A  , DE_S  , DE_D  , DE_F  ,                        _______,_______,_______,_______,_______,_______,
         DE_B  ,KC_LCTL, DE_Y  , DE_X  , DE_C  , DE_V  ,                        _______,_______,_______,_______,_______,_______,
                        _______,_______,                                                        _______,_______,
                                _______,_______,                                        _______,_______,
                                        _______,_______,                        _______,_______,
                                        _______,_______,                        _______,_______
    ),

    [_SPECIAL] = LAYOUT_5x6(
        DE_CIRC,DE_DEG ,DE_SUP2,DE_SUP3,DE_DLR ,DE_EURO,                        XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
        XXXXXXX, DE_AT ,DE_UNDS,DE_LBRC,DE_RBRC,DE_SECT,                        DE_EXLM,DE_LABK,DE_RABK,DE_EQL ,DE_COLN,XXXXXXX,
        XXXXXXX,DE_BSLS,DE_SLSH,DE_LCBR,DE_RCBR,DE_ASTR,                        DE_QUES,DE_LPRN,DE_RPRN,DE_MINS,DE_AMPR,XXXXXXX,
        XXXXXXX,DE_HASH,DE_DLR ,DE_PIPE,DE_ACUT,DE_GRV ,                        DE_PLUS,DE_PERC,DE_DQUO,DE_QUOT,DE_TILD,XXXXXXX,
                        XXXXXXX,XXXXXXX,                                                        XXXXXXX,XXXXXXX,
                                _______,_______,                                        _______,_______,
                                        _______,_______,                        _______,_______,
                                        _______,_______,                        _______,_______
    ),
	
    [_NAV] = LAYOUT_5x6(
        KC_ESC ,XXXXXXX,XXXXXXX,XXXXXXX,KC_AF4 ,XXXXXXX,                        KC_NUM ,KC_PEQL,KC_PSLS,KC_PAST,KC_PMNS,XXXXXXX,
        KC_ATAB,KC_PGUP,KC_BSPC, KC_UP ,KC_DEL ,KC_PGDN,                        XXXXXXX, KC_P7 , KC_P8 , KC_P9 ,DE_PDOT,XXXXXXX,
        XXXXXXX,KC_HOME,KC_LEFT,KC_DOWN,KC_RGHT,KC_END ,                        KC_CALC, KC_P4 , KC_P5 , KC_P6 ,KC_PPLS,XXXXXXX,
        XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,KC_UNDO,XXXXXXX,                        XXXXXXX, KC_P1 , KC_P2 , KC_P3 ,KC_PENT,XXXXXXX,
                        XXXXXXX,XXXXXXX,                                                         KC_P0 ,DE_PCMM,
                                _______,_______,                                        _______,_______,
                                        _______,_______,                        _______,_______,
                                        _______,_______,                        _______,_______
    ),
	
    [_FN] = LAYOUT_5x6(
        KC_F12 , KC_F1 , KC_F2 , KC_F3 , KC_F4 , KC_F5 ,                         KC_F6 , KC_F7 , KC_F8 , KC_F9 ,KC_F10 ,KC_F11 ,
        XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,                        XXXXXXX,XXXXXXX, DE_UE ,XXXXXXX,XXXXXXX,KC_F13 ,
        KC_CAPS, DE_AE ,XXXXXXX, DE_SS ,XXXXXXX,XXXXXXX,                        XXXXXXX,KC_MPRV,KC_MPLY,KC_MNXT, DE_OE ,KC_F14 ,
        XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,                        XXXXXXX,KC_VOLD,KC_MUTE,KC_VOLU,XXXXXXX,KC_F15 ,
                        XXXXXXX,XXXXXXX,                                                        XXXXXXX,XXXXXXX,
                                _______,_______,                                        _______,_______,
                                        _______,_______,                        _______,_______,
                                        _______,_______,                        _______,_______
    ),
	
    [_PRACT] = LAYOUT_5x6(
        KC_ESC , KC_1  , KC_2  , KC_3  , KC_4  , KC_5  ,                         KC_6  , KC_7  , KC_8  , KC_9  , KC_0  ,XXXXXXX,
        KC_TAB , KC_Q  , KC_W  , KC_E  , KC_R  , KC_B  ,                         KC_Y  , KC_U  , KC_I  , KC_O  , KC_P  ,XXXXXXX,
        KC_LSFT, KC_A  , KC_S  , KC_D  , KC_F  , KC_T  ,                         KC_M  , KC_J  , KC_K  , KC_L  ,KC_SCLN,KC_ENT ,
        KC_LCTL, KC_Z  , KC_X  , KC_C  , KC_G  , KC_V  ,                         KC_N  , KC_H  ,KC_COMM,KC_DOT ,KC_SLSH,XXXXXXX,
                        XXXXXXX,XXXXXXX,                                                        XXXXXXX,XXXXXXX,
                                _______,_______,                                        _______,PRACTSP,
                                        _______,_______,                        _______,_______,
                                        _______,_______,                        _______,_______
    ),

    [_PRACTSP] = LAYOUT_5x6(
        KC_CIRC,XXXXXXX,XXXXXXX,XXXXXXX,KC_DLR ,XXXXXXX,                        XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
        XXXXXXX, KC_AT ,KC_UNDS,KC_LBRC,KC_RBRC,XXXXXXX,                        KC_EXLM,KC_LABK,KC_RABK,KC_EQL ,S(KC_P),XXXXXXX,
        XXXXXXX,KC_BSLS,KC_SLSH,KC_LCBR,KC_RCBR,KC_ASTR,                        KC_QUES,KC_LPRN,KC_RPRN,KC_MINS,KC_AMPR,XXXXXXX,
        XXXXXXX,KC_HASH,KC_DLR ,KC_PIPE,XXXXXXX,KC_GRV ,                        KC_PLUS,KC_PERC,KC_DQUO,KC_QUOT,KC_TILD,XXXXXXX,
                        XXXXXXX,XXXXXXX,                                                        XXXXXXX,XXXXXXX,
                                _______,_______,                                        _______,_______,
                                        _______,_______,                        _______,_______,
                                        _______,_______,                        _______,_______
    )
};

//KC_CALC

/*
Missing Keys:
    KC_CAPS
	
    KC_PSCR
    KC_SCRL
    KC_PAUS
	
    KC_INS
	
    KC_NUM
*/
