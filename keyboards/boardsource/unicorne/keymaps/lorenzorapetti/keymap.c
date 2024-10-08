#include QMK_KEYBOARD_H
#include "features/achordion.h"

#define LCTL_KA LCTL_T(KC_A)
#define LALT_KR LALT_T(KC_R)
#define LGUI_KS LGUI_T(KC_S)
#define LSFT_KT LSFT_T(KC_T)

#define LCTL_KO LCTL_T(KC_O)
#define LALT_KI LALT_T(KC_I)
#define LGUI_KE LGUI_T(KC_E)
#define LSFT_KN LSFT_T(KC_N)

#define TMUX_PRE C(KC_A)
#define VIM_WIN_PRE C(KC_W)

#define TAB_NUM LT(_NUM, KC_TAB)
#define BSPC_NAV LT(_NAV, KC_BSPC)
#define SPC_SYM LT(_SYM, KC_SPC)
#define ENT_FN LT(_FN, KC_ENT)
#define ESC_WLD LT(_WORLD, KC_ESC)

#define A_GRAVE UC(0x00E0)
#define A_ACUTE UC(0x00E1)
#define A_GRAVEU UC(0x00C0)
#define A_ACUTEU UC(0x00C1)
#define E_GRAVE UC(0x00E8)
#define E_ACUTE UC(0x00E9)
#define E_GRAVEU UC(0x00C8)
#define E_ACUTEU UC(0x00C9)
#define I_GRAVE UC(0x00EC)
#define I_ACUTE UC(0x00ED)
#define I_GRAVEU UC(0x00CC)
#define I_ACUTEU UC(0x00CD)
#define O_GRAVE UC(0x00F2)
#define O_ACUTE UC(0x00F3)
#define O_GRAVEU UC(0x00D2)
#define O_ACUTEU UC(0x00D3)
#define U_GRAVE UC(0x00F9)
#define U_ACUTE UC(0x00FA)
#define U_GRAVEU UC(0x00D9)
#define U_ACUTEU UC(0x00DA)

enum layers {
    _COLEMAK = 0,
    _QWERTY,
    _NUM,
    _SYM,
    _NAV,
    _FN,
    _WORLD
};

enum custom_keycodes {
    COPY = SAFE_RANGE,
    PASTE,
    SAFE_PASTE,
    CUT,
    UNDO,
    REDO,
    FIND,
    SEL_ALL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//    ┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐                                 ┌──────┬─────────┬─────────┬─────────┬─────────┬──────┐
//    │    `    │    q    │    w    │    f    │    p    │    b    │                                 │  j   │    l    │    u    │    y    │    '    │ bspc │
//    ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤                                 ├──────┼─────────┼─────────┼─────────┼─────────┼──────┤
//    │ ESC_WLD │ LCTL_KA │ LALT_KR │ LGUI_KS │ LSFT_KT │    g    │                                 │  m   │ LSFT_KN │ LGUI_KE │ LALT_KI │ LCTL_KO │  ;   │
//    ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤                                 ├──────┼─────────┼─────────┼─────────┼─────────┼──────┤
//    │  lsft   │    z    │    x    │    c    │    d    │    v    │                                 │  k   │    h    │    ,    │    .    │    /    │ rsft │
//    └─────────┴─────────┴─────────┴─────────┼─────────┼─────────┼──────────┐   ┌─────────┬────────┼──────┼─────────┴─────────┴─────────┴─────────┴──────┘
//                                            │  lgui   │ TAB_NUM │ BSPC_NAV │   │ SPC_SYM │ ENT_FN │ ralt │
//                                            └─────────┴─────────┴──────────┘   └─────────┴────────┴──────┘
[_COLEMAK] = LAYOUT_split_3x6_3(
  KC_GRV  , KC_Q    , KC_W    , KC_F    , KC_P    , KC_B    ,                                   KC_J    , KC_L    , KC_U    , KC_Y    , KC_QUOT , KC_BSPC,
  ESC_WLD , LCTL_KA , LALT_KR , LGUI_KS , LSFT_KT , KC_G    ,                                   KC_M    , LSFT_KN , LGUI_KE , LALT_KI , LCTL_KO , KC_SCLN,
  KC_LSFT , KC_Z    , KC_X    , KC_C    , KC_D    , KC_V    ,                                   KC_K    , KC_H    , KC_COMM , KC_DOT  , KC_SLSH , KC_RSFT,
                                          KC_LGUI , TAB_NUM , BSPC_NAV ,     SPC_SYM , ENT_FN , KC_RALT
),

//    ┌──────┬───┬───┬───┬──────┬───────┐                       ┌──────┬───┬───┬───┬───┬──────┐
//    │ tab  │ q │ w │ e │  r   │   t   │                       │  y   │ u │ i │ o │ p │ bspc │
//    ├──────┼───┼───┼───┼──────┼───────┤                       ├──────┼───┼───┼───┼───┼──────┤
//    │ lctl │ a │ s │ d │  f   │   g   │                       │  h   │ j │ k │ l │ ; │  '   │
//    ├──────┼───┼───┼───┼──────┼───────┤                       ├──────┼───┼───┼───┼───┼──────┤
//    │ lsft │ z │ x │ c │  v   │   b   │                       │  n   │ m │ , │ . │ / │ esc  │
//    └──────┴───┴───┴───┼──────┼───────┼─────┐   ┌─────┬───────┼──────┼───┴───┴───┴───┴──────┘
//                       │ lgui │ MO(1) │ spc │   │ ent │ MO(2) │ ralt │
//                       └──────┴───────┴─────┘   └─────┴───────┴──────┘
[_QWERTY] = LAYOUT_split_3x6_3(
  KC_TAB  , KC_Q , KC_W , KC_E , KC_R    , KC_T  ,                               KC_Y    , KC_U , KC_I    , KC_O   , KC_P    , KC_BSPC,
  KC_LCTL , KC_A , KC_S , KC_D , KC_F    , KC_G  ,                               KC_H    , KC_J , KC_K    , KC_L   , KC_SCLN , KC_QUOT,
  KC_LSFT , KC_Z , KC_X , KC_C , KC_V    , KC_B  ,                               KC_N    , KC_M , KC_COMM , KC_DOT , KC_SLSH , KC_ESC ,
                                 KC_LGUI , MO(1) , KC_SPC ,     KC_ENT , MO(2) , KC_RALT
),

//    ┌────┬──────┬──────────┬──────┬──────┬─────┐                ┌───┬───┬───┬───┬───┬──────┐
//    │ no │ ent  │   spc    │ tab  │ bspc │ no  │                │ % │ 7 │ 8 │ 9 │ : │ bspc │
//    ├────┼──────┼──────────┼──────┼──────┼─────┤                ├───┼───┼───┼───┼───┼──────┤
//    │ no │ lctl │   lalt   │ lgui │ lsft │  k  │                │ + │ 4 │ 5 │ 6 │ - │  no  │
//    ├────┼──────┼──────────┼──────┼──────┼─────┤                ├───┼───┼───┼───┼───┼──────┤
//    │ no │  no  │ TMUX_PRE │  no  │  no  │  j  │                │ * │ 1 │ 2 │ 3 │ / │  no  │
//    └────┴──────┴──────────┴──────┼──────┼─────┼────┐   ┌───┬───┼───┼───┴───┴───┴───┴──────┘
//                                  │  no  │     │ no │   │ , │ . │ 0 │
//                                  └──────┴─────┴────┘   └───┴───┴───┘
[_NUM] = LAYOUT_split_3x6_3(
  XXXXXXX , KC_ENT  , KC_SPC   , KC_TAB  , KC_BSPC , XXXXXXX ,                                  KC_PERC , KC_7 , KC_8 , KC_9 , KC_COLN , KC_BSPC,
  XXXXXXX , KC_LCTL , KC_LALT  , KC_LGUI , KC_LSFT , KC_K    ,                                  KC_PLUS , KC_4 , KC_5 , KC_6 , KC_MINS , XXXXXXX,
  XXXXXXX , XXXXXXX , TMUX_PRE , XXXXXXX , XXXXXXX , KC_J    ,                                  KC_ASTR , KC_1 , KC_2 , KC_3 , KC_SLSH , XXXXXXX,
                                           XXXXXXX , _______ , XXXXXXX ,     KC_COMM , KC_DOT , KC_0
),

//    ┌───┬───┬───┬───┬───┬───┐                  ┌────┬──────┬──────┬──────┬──────┬─────────────┐
//    │ ! │ { │ ' │ " │ } │ ? │                  │ +  │ lsft │ lgui │ lalt │ lctl │      `      │
//    ├───┼───┼───┼───┼───┼───┤                  ├────┼──────┼──────┼──────┼──────┼─────────────┤
//    │ # │ ^ │ = │ _ │ $ │ * │                  │ ~  │ bspc │ tab  │ spc  │ ent  │  TMUX_PRE   │
//    ├───┼───┼───┼───┼───┼───┤                  ├────┼──────┼──────┼──────┼──────┼─────────────┤
//    │ @ │ < │ | │ - │ > │ / │                  │ &  │  (   │  [   │  ]   │  )   │ VIM_WIN_PRE │
//    └───┴───┴───┴───┼───┼───┼───┐   ┌────┬─────┼────┼──────┴──────┴──────┴──────┴─────────────┘
//                    │ % │ : │ \ │   │ no │     │ no │
//                    └───┴───┴───┘   └────┴─────┴────┘
[_SYM] = LAYOUT_split_3x6_3(
  KC_EXLM , KC_LCBR , KC_QUOT , KC_DQUO , KC_RCBR , KC_QUES ,                                   KC_PLUS , KC_LSFT , KC_LGUI , KC_LALT , KC_LCTL , KC_GRV     ,
  KC_HASH , KC_CIRC , KC_EQL  , KC_UNDS , KC_DLR  , KC_ASTR ,                                   KC_TILD , KC_BSPC , KC_TAB  , KC_SPC  , KC_ENT  , TMUX_PRE   ,
  KC_AT   , KC_LABK , KC_PIPE , KC_MINS , KC_RABK , KC_SLSH ,                                   KC_AMPR , KC_LPRN , KC_LBRC , KC_RBRC , KC_RPRN , VIM_WIN_PRE,
                                          KC_PERC , KC_COLN , KC_BSLS ,     XXXXXXX , _______ , XXXXXXX
),

//    ┌─────────┬─────────┬──────┬──────┬────────────┬───────┐                     ┌──────┬──────┬──────┬──────┬──────┬────┐
//    │ QK_BOOT │   no    │  no  │ REDO │    UNDO    │  CUT  │                     │  no  │ bspc │ tab  │ spc  │ ent  │ no │
//    ├─────────┼─────────┼──────┼──────┼────────────┼───────┤                     ├──────┼──────┼──────┼──────┼──────┼────┤
//    │ CW_TOGG │  lctl   │ lalt │ lgui │    lsft    │ COPY  │                     │ left │ down │  up  │ rght │ C(w) │ no │
//    ├─────────┼─────────┼──────┼──────┼────────────┼───────┤                     ├──────┼──────┼──────┼──────┼──────┼────┤
//    │   no    │ SEL_ALL │  no  │ FIND │ SAFE_PASTE │ PASTE │                     │  no  │ home │ pgdn │ pgup │ end  │ no │
//    └─────────┴─────────┴──────┴──────┼────────────┼───────┼─────┐   ┌─────┬─────┼──────┼──────┴──────┴──────┴──────┴────┘
//                                      │     no     │  no   │     │   │ ent │     │ ralt │
//                                      └────────────┴───────┴─────┘   └─────┴─────┴──────┘
[_NAV] = LAYOUT_split_3x6_3(
  QK_BOOT , XXXXXXX , XXXXXXX , REDO    , UNDO       , CUT     ,                                  XXXXXXX , KC_BSPC , KC_TAB  , KC_SPC   , KC_ENT  , XXXXXXX,
  CW_TOGG , KC_LCTL , KC_LALT , KC_LGUI , KC_LSFT    , COPY    ,                                  KC_LEFT , KC_DOWN , KC_UP   , KC_RIGHT , C(KC_W) , XXXXXXX,
  XXXXXXX , SEL_ALL , XXXXXXX , FIND    , SAFE_PASTE , PASTE   ,                                  XXXXXXX , KC_HOME , KC_PGDN , KC_PGUP  , KC_END  , XXXXXXX,
                                          XXXXXXX    , XXXXXXX , _______ ,     KC_ENT , _______ , KC_RALT
),

//    ┌────┬──────┬──────┬──────┬──────┬─────┐                     ┌──────┬────┬────┬────┬─────┬─────┐
//    │ no │ mprv │  no  │ mply │ mnxt │ no  │                     │ mute │ f7 │ f8 │ f9 │ f10 │ f13 │
//    ├────┼──────┼──────┼──────┼──────┼─────┤                     ├──────┼────┼────┼────┼─────┼─────┤
//    │ no │ lctl │ lalt │ lgui │ lsft │ no  │                     │ volu │ f4 │ f5 │ f6 │ f11 │ f14 │
//    ├────┼──────┼──────┼──────┼──────┼─────┤                     ├──────┼────┼────┼────┼─────┼─────┤
//    │ no │ bRID │  no  │  no  │ bRIU │ no  │                     │ vold │ f1 │ f2 │ f3 │ f12 │ f15 │
//    └────┴──────┴──────┴──────┼──────┼─────┼─────┐   ┌─────┬─────┼──────┼────┴────┴────┴─────┴─────┘
//                              │ lgui │     │ spc │   │ ent │     │ ralt │
//                              └──────┴─────┴─────┘   └─────┴─────┴──────┘
[_FN] = LAYOUT_split_3x6_3(
  XXXXXXX , KC_MPRV , XXXXXXX , KC_MPLY , KC_MNXT , XXXXXXX ,                                 KC_MUTE , KC_F7 , KC_F8 , KC_F9 , KC_F10 , KC_F13,
  XXXXXXX , KC_LCTL , KC_LALT , KC_LGUI , KC_LSFT , XXXXXXX ,                                 KC_VOLU , KC_F4 , KC_F5 , KC_F6 , KC_F11 , KC_F14,
  XXXXXXX , KC_BRID , XXXXXXX , XXXXXXX , KC_BRIU , XXXXXXX ,                                 KC_VOLD , KC_F1 , KC_F2 , KC_F3 , KC_F12 , KC_F15,
                                          KC_LGUI , _______ , KC_SPC ,     KC_ENT , _______ , KC_RALT
),

//    ┌─────┬────┬────┬────┬────┬────┐                      ┌─────────┬─────────┬─────────┬─────────┬────┬────┐
//    │ no  │ no │ no │ no │ no │ no │                      │   no    │   no    │   no    │   no    │ no │ no │
//    ├─────┼────┼────┼────┼────┼────┤                      ├─────────┼─────────┼─────────┼─────────┼────┼────┤
//    │     │ no │ no │ no │ no │ no │                      │ A_GRAVE │ E_GRAVE │ I_GRAVE │ O_GRAVE │ no │ no │
//    ├─────┼────┼────┼────┼────┼────┤                      ├─────────┼─────────┼─────────┼─────────┼────┼────┤
//    │ no  │ no │ no │ no │ no │ no │                      │   no    │   no    │   no    │   no    │ no │ no │
//    └─────┴────┴────┴────┼────┼────┼──────┐   ┌─────┬─────┼─────────┼─────────┴─────────┴─────────┴────┴────┘
//                         │ no │ no │ lgui │   │ ent │     │  ralt   │
//                         └────┴────┴──────┘   └─────┴─────┴─────────┘
[_WORLD] = LAYOUT_split_3x6_3(
  XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,                                  XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX,
  _______ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,                                  A_GRAVE , E_GRAVE , I_GRAVE , O_GRAVE , XXXXXXX , XXXXXXX,
  XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,                                  XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX,
                                          XXXXXXX , XXXXXXX , KC_LGUI ,     KC_ENT , _______ , KC_RALT
)
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case ESC_WLD:
        case TAB_NUM:
        case BSPC_NAV:
        case SPC_SYM:
        case ENT_FN:
            return 120;
        default:
            return TAPPING_TERM;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  if (!process_achordion(keycode, record)) { return false; }

    os_variant_t detected_os = detected_host_os();
    bool use_ctrl = true;

    if (detected_os == OS_MACOS || detected_os == OS_IOS) {
        use_ctrl = false;
    }

    switch (keycode) {
        case COPY:
            if (record->event.pressed) {
                register_code16(use_ctrl ? C(KC_C) : G(KC_C));
            } else {
                unregister_code16(use_ctrl ? C(KC_C) : G(KC_C));
            }
            return false;
        case PASTE:
            if (record->event.pressed) {
                register_code16(use_ctrl ? C(KC_V) : G(KC_V));
            } else {
                unregister_code16(use_ctrl ? C(KC_V) : G(KC_V));
            }
            return false;
        case SAFE_PASTE:
            if (record->event.pressed) {
                register_code16(use_ctrl ? C(S(KC_V)) : G(S(KC_V)));
            } else {
                unregister_code16(use_ctrl ? C(S(KC_V)) : G(S(KC_V)));
            }
            return false;
        case CUT:
            if (record->event.pressed) {
                register_code16(use_ctrl ? C(KC_X) : G(KC_X));
            } else {
                unregister_code16(use_ctrl ? C(KC_X) : G(KC_X));
            }
            return false;
        case UNDO:
            if (record->event.pressed) {
                register_code16(use_ctrl ? C(KC_Z) : G(KC_Z));
            } else {
                unregister_code16(use_ctrl ? C(KC_Z) : G(KC_Z));
            }
            return false;
        case REDO:
            if (record->event.pressed) {
                register_code16(use_ctrl ? C(S(KC_Z)) : G(S(KC_Z)));
            } else {
                unregister_code16(use_ctrl ? C(S(KC_Z)) : G(S(KC_Z)));
            }
            return false;
        case FIND:
            if (record->event.pressed) {
                register_code16(use_ctrl ? C(KC_F) : G(KC_F));
            } else {
                unregister_code16(use_ctrl ? C(KC_F) : G(KC_F));
            }
            return false;
        case SEL_ALL:
            if (record->event.pressed) {
                register_code16(use_ctrl ? C(KC_A) : G(KC_A));
            } else {
                unregister_code16(use_ctrl ? C(KC_A) : G(KC_A));
            }
            return false;
    }

  return true;
}

void matrix_scan_user(void) {
  achordion_task();
}

bool achordion_chord(uint16_t tap_hold_keycode,
                     keyrecord_t* tap_hold_record,
                     uint16_t other_keycode,
                     keyrecord_t* other_record) {
  // Exceptionally consider the following chords as holds, even though they
  // are on the same hand in Dvorak.
  switch (tap_hold_keycode) {
    case TAB_NUM:
    case BSPC_NAV:
    case SPC_SYM:
    case ENT_FN:
        return true;
  }

  // Otherwise, follow the opposite hands rule.
  return achordion_opposite_hands(tap_hold_record, other_record);
}

uint16_t achordion_streak_chord_timeout(
    uint16_t tap_hold_keycode, uint16_t next_keycode) {
  if (IS_QK_LAYER_TAP(tap_hold_keycode)) {
    return 0;  // Disable streak detection on layer-tap keys.
  }

  // Otherwise, tap_hold_keycode is a mod-tap key.
  uint8_t mod = mod_config(QK_MOD_TAP_GET_MODS(tap_hold_keycode));
  if ((mod & MOD_LSFT) != 0) {
    return 80;  // A shorter streak timeout for Shift mod-tap keys.
  } else {
    return 180;  // A longer timeout otherwise.
  }
}

bool process_detected_host_os_kb(os_variant_t detected_os) {
    if (!process_detected_host_os_user(detected_os)) {
        return false;
    }
    switch (detected_os) {
        case OS_MACOS:
        case OS_IOS:
            rgb_matrix_set_color_all(RGB_WHITE);
            break;
        case OS_WINDOWS:
            rgb_matrix_set_color_all(RGB_BLUE);
            break;
        case OS_LINUX:
            rgb_matrix_set_color_all(RGB_ORANGE);
            break;
        case OS_UNSURE:
            rgb_matrix_set_color_all(RGB_RED);
            break;
    }

    return true;
}
