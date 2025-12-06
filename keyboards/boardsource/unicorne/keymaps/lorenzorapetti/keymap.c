#include QMK_KEYBOARD_H

#define LCTL_KA LCTL_T(KC_A)
#define LCTL_KSCLN LCTL_T(KC_SCLN)
#define LALT_KR LALT_T(KC_R)
#define LALT_KS LALT_T(KC_S)
#define LALT_KL LALT_T(KC_L)
#define LGUI_KS LGUI_T(KC_S)
#define LGUI_KD LGUI_T(KC_D)
#define LGUI_KK LGUI_T(KC_K)
#define LSFT_KT LSFT_T(KC_T)
#define LSFT_KF LSFT_T(KC_F)
#define LSFT_KJ LSFT_T(KC_J)

#define LCTL_KO LCTL_T(KC_O)
#define LALT_KI LALT_T(KC_I)
#define LGUI_KE LGUI_T(KC_E)
#define LSFT_KN LSFT_T(KC_N)

#define LCTL_KZ LCTL_T(KC_Z)
#define LALT_KX LALT_T(KC_X)
#define LGUI_KC LGUI_T(KC_C)
#define LSFT_KD LSFT_T(KC_D)
#define LSFT_KV LSFT_T(KC_V)

#define LCTL_KSLSH LCTL_T(KC_SLSH)
#define LALT_KDOT LALT_T(KC_DOT)
#define LGUI_KCOMMA LGUI_T(KC_COMM)
#define LSFT_KH LSFT_T(KC_H)
#define LSFT_KM LSFT_T(KC_M)

#define TMUX_PRE C(KC_A)
#define VIM_WIN_PRE C(KC_W)

#define TAB_NUM LT(_NUM, KC_TAB)
#define TAB_NAV LT(_NAV, KC_TAB)
#define BSPC_NAV LT(_NAV, KC_BSPC)
#define SPC_SYM LT(_SYM, KC_SPC)
#define SPC_NAV LT(_NAV, KC_SPC)
#define ENT_FN LT(_FN, KC_ENT)
#define ENT_NUM LT(_NUM, KC_ENT)
#define ENT_NAV LT(_NAV, KC_ENT)
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
    _GRAPHITE_WRITE = 0,
    _GRAPHITE,
    _COLEMAK,
    _NUM,
    _SYM,
    _NAV,
    _FN,
    _WORLD
};

enum custom_keycodes {
    COPY = SAFE_RANGE,
    PASTE,
    SAFE_COPY,
    SAFE_PASTE,
    CUT,
    UNDO,
    REDO,
    FIND,
    SEL_ALL,
    GRAPHITE,
    COLEMAK
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//    ┌─────────┬───┬───┬───┬─────────┬─────────┐                        ┌─────┬─────┬───┬───┬───┬──────┐
//    │    `    │ b │ l │ d │    w    │    z    │                        │  '  │  f  │ o │ u │ j │  ;   │
//    ├─────────┼───┼───┼───┼─────────┼─────────┤                        ├─────┼─────┼───┼───┼───┼──────┤
//    │ ESC_WLD │ n │ r │ t │    s    │    g    │                        │  y  │  h  │ a │ e │ i │  ,   │
//    ├─────────┼───┼───┼───┼─────────┼─────────┤                        ├─────┼─────┼───┼───┼───┼──────┤
//    │  lsft   │ q │ x │ m │    c    │    v    │                        │  k  │  p  │ . │ - │ / │ rsft │
//    └─────────┴───┴───┴───┼─────────┼─────────┼──────────┐   ┌─────────┼─────┼─────┼───┴───┴───┴──────┘
//                          │ MO(_FN) │ TAB_NUM │ MO(_NAV) │   │ SPC_SYM │ ent │ del │
//                          └─────────┴─────────┴──────────┘   └─────────┴─────┴─────┘
[_GRAPHITE_WRITE] = LAYOUT_split_3x6_3(
  KC_GRV  , KC_B , KC_L , KC_D , KC_W    , KC_Z    ,                          KC_QUOT , KC_F   , KC_O   , KC_U    , KC_J    , KC_SCLN ,
  ESC_WLD , KC_N , KC_R , KC_T , KC_S    , KC_G    ,                          KC_Y    , KC_H   , KC_A   , KC_E    , KC_I    , KC_COMMA,
  KC_LSFT , KC_Q , KC_X , KC_M , KC_C    , KC_V    ,                          KC_K    , KC_P   , KC_DOT , KC_MINS , KC_SLSH , KC_RSFT ,
                                 MO(_FN) , TAB_NUM , MO(_NAV) ,     SPC_SYM , KC_ENT  , KC_DEL
),

//    ┌─────────┬───────────┬───────────┬───────────┬───────────┬─────────┐                        ┌─────┬───────────┬───────────┬───────────┬───────────┬──────┐
//    │    `    │     b     │     l     │     d     │     w     │    z    │                        │  '  │     f     │     o     │     u     │     j     │  ;   │
//    ├─────────┼───────────┼───────────┼───────────┼───────────┼─────────┤                        ├─────┼───────────┼───────────┼───────────┼───────────┼──────┤
//    │ ESC_WLD │ LCTL_T(n) │ LALT_T(r) │ LGUI_T(t) │ LSFT_T(s) │    g    │                        │  y  │ LSFT_T(h) │ LGUI_T(a) │ LALT_T(e) │ LCTL_T(i) │  ,   │
//    ├─────────┼───────────┼───────────┼───────────┼───────────┼─────────┤                        ├─────┼───────────┼───────────┼───────────┼───────────┼──────┤
//    │  lsft   │     q     │     x     │     m     │     c     │    v    │                        │  k  │     p     │     .     │     -     │     /     │ rsft │
//    └─────────┴───────────┴───────────┴───────────┼───────────┼─────────┼──────────┐   ┌─────────┼─────┼───────────┼───────────┴───────────┴───────────┴──────┘
//                                                  │  MO(_FN)  │ TAB_NUM │ MO(_NAV) │   │ SPC_SYM │ ent │    del    │
//                                                  └───────────┴─────────┴──────────┘   └─────────┴─────┴───────────┘
[_GRAPHITE] = LAYOUT_split_3x6_3(
  KC_GRV  , KC_B         , KC_L         , KC_D         , KC_W         , KC_Z    ,                          KC_QUOT , KC_F         , KC_O         , KC_U         , KC_J         , KC_SCLN ,
  ESC_WLD , LCTL_T(KC_N) , LALT_T(KC_R) , LGUI_T(KC_T) , LSFT_T(KC_S) , KC_G    ,                          KC_Y    , LSFT_T(KC_H) , LGUI_T(KC_A) , LALT_T(KC_E) , LCTL_T(KC_I) , KC_COMMA,
  KC_LSFT , KC_Q         , KC_X         , KC_M         , KC_C         , KC_V    ,                          KC_K    , KC_P         , KC_DOT       , KC_MINS      , KC_SLSH      , KC_RSFT ,
                                                         MO(_FN)      , TAB_NUM , MO(_NAV) ,     SPC_SYM , KC_ENT  , KC_DEL
),

//    ┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐                        ┌─────┬─────────┬─────────┬─────────┬─────────┬──────┐
//    │    `    │    q    │    w    │    f    │    p    │    b    │                        │  j  │    l    │    u    │    y    │    '    │ bspc │
//    ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤                        ├─────┼─────────┼─────────┼─────────┼─────────┼──────┤
//    │ ESC_WLD │ LCTL_KA │ LALT_KR │ LGUI_KS │ LSFT_KT │    g    │                        │  m  │ LSFT_KN │ LGUI_KE │ LALT_KI │ LCTL_KO │  ;   │
//    ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤                        ├─────┼─────────┼─────────┼─────────┼─────────┼──────┤
//    │  lsft   │    z    │    x    │    c    │    d    │    v    │                        │  k  │    h    │    ,    │    .    │    /    │ rsft │
//    └─────────┴─────────┴─────────┴─────────┼─────────┼─────────┼──────────┐   ┌─────────┼─────┼─────────┼─────────┴─────────┴─────────┴──────┘
//                                            │ MO(_FN) │ TAB_NUM │ MO(_NAV) │   │ SPC_SYM │ ent │   del   │
//                                            └─────────┴─────────┴──────────┘   └─────────┴─────┴─────────┘
[_COLEMAK] = LAYOUT_split_3x6_3(
  KC_GRV  , KC_Q    , KC_W    , KC_F    , KC_P    , KC_B    ,                          KC_J   , KC_L    , KC_U     , KC_Y    , KC_QUOT , KC_BSPC,
  ESC_WLD , LCTL_KA , LALT_KR , LGUI_KS , LSFT_KT , KC_G    ,                          KC_M   , LSFT_KN , LGUI_KE  , LALT_KI , LCTL_KO , KC_SCLN,
  KC_LSFT , KC_Z    , KC_X    , KC_C    , KC_D    , KC_V    ,                          KC_K   , KC_H    , KC_COMMA , KC_DOT  , KC_SLSH , KC_RSFT,
                                          MO(_FN) , TAB_NUM , MO(_NAV) ,     SPC_SYM , KC_ENT , KC_DEL
),

//    ┌────┬──────┬──────┬──────┬──────┬───────┐            ┌───┬───┬───┬───┬───┬────┐
//    │ no │ ent  │ spc  │ tab  │ bspc │  CUT  │            │ : │ 7 │ 8 │ 9 │ % │ no │
//    ├────┼──────┼──────┼──────┼──────┼───────┤            ├───┼───┼───┼───┼───┼────┤
//    │ no │ lctl │ lalt │ lgui │ lsft │ COPY  │            │ - │ 4 │ 5 │ 6 │ + │ k  │
//    ├────┼──────┼──────┼──────┼──────┼───────┤            ├───┼───┼───┼───┼───┼────┤
//    │ no │  no  │  no  │  no  │  no  │ PASTE │            │ / │ 1 │ 2 │ 3 │ * │ j  │
//    └────┴──────┴──────┴──────┼──────┼───────┼────┐   ┌───┼───┼───┼───┴───┴───┴────┘
//                              │  no  │       │ no │   │ 0 │ . │ , │
//                              └──────┴───────┴────┘   └───┴───┴───┘
[_NUM] = LAYOUT_split_3x6_3(
  XXXXXXX , KC_ENT  , KC_SPC  , KC_TAB  , KC_BSPC , CUT     ,                      KC_COLN , KC_7    , KC_8 , KC_9 , KC_PERC , XXXXXXX,
  XXXXXXX , KC_LCTL , KC_LALT , KC_LGUI , KC_LSFT , COPY    ,                      KC_MINS , KC_4    , KC_5 , KC_6 , KC_PLUS , KC_K   ,
  XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , PASTE   ,                      KC_SLSH , KC_1    , KC_2 , KC_3 , KC_ASTR , KC_J   ,
                                          XXXXXXX , _______ , XXXXXXX ,     KC_0 , KC_DOT  , KC_COMM
),

//    ┌───┬───┬───┬───┬───┬───┐             ┌────┬──────┬──────┬──────┬──────┬─────────────┐
//    │ ! │ { │ ' │ " │ } │ ? │             │ +  │  )   │  ]   │  [   │  (   │      `      │
//    ├───┼───┼───┼───┼───┼───┤             ├────┼──────┼──────┼──────┼──────┼─────────────┤
//    │ # │ $ │ = │ _ │ ^ │ * │             │ ~  │ bspc │ tab  │ spc  │ ent  │  TMUX_PRE   │
//    ├───┼───┼───┼───┼───┼───┤             ├────┼──────┼──────┼──────┼──────┼─────────────┤
//    │ @ │ > │ | │ - │ < │ / │             │ &  │ lsft │ lgui │ lalt │ lctl │ VIM_WIN_PRE │
//    └───┴───┴───┴───┼───┼───┼───┐   ┌─────┼────┼──────┼──────┴──────┴──────┴─────────────┘
//                    │ % │ : │ \ │   │     │ no │  no  │
//                    └───┴───┴───┘   └─────┴────┴──────┘
[_SYM] = LAYOUT_split_3x6_3(
  KC_EXLM , KC_LCBR , KC_QUOT , KC_DQUO , KC_RCBR , KC_QUES ,                         KC_PLUS , KC_RPRN , KC_RBRC , KC_LBRC , KC_LPRN , KC_GRV     ,
  KC_HASH , KC_DLR  , KC_EQL  , KC_UNDS , KC_CIRC , KC_ASTR ,                         KC_TILD , KC_BSPC , KC_TAB  , KC_SPC  , KC_ENT  , TMUX_PRE   ,
  KC_AT   , KC_RABK , KC_PIPE , KC_MINS , KC_LABK , KC_SLSH ,                         KC_AMPR , KC_LSFT , KC_LGUI , KC_LALT , KC_LCTL , VIM_WIN_PRE,
                                          KC_PERC , KC_COLN , KC_BSLS ,     _______ , XXXXXXX , XXXXXXX
),

//    ┌─────────┬──────┬──────┬──────┬──────┬───────┐              ┌─────────┬──────┬────┬───────────┬────────────┬─────────┐
//    │ QK_BOOT │ ent  │ spc  │ tab  │ bspc │  CUT  │              │   no    │ UNDO │ no │    no     │     no     │ QK_BOOT │
//    ├─────────┼──────┼──────┼──────┼──────┼───────┤              ├─────────┼──────┼────┼───────────┼────────────┼─────────┤
//    │  caps   │ lctl │ lalt │ lgui │ lsft │ COPY  │              │  left   │ down │ up │   rght    │    C(w)    │   no    │
//    ├─────────┼──────┼──────┼──────┼──────┼───────┤              ├─────────┼──────┼────┼───────────┼────────────┼─────────┤
//    │ CW_TOGG │ end  │ pgup │ pgdn │ home │ PASTE │              │ SEL_ALL │ FIND │ no │ SAFE_COPY │ SAFE_PASTE │   no    │
//    └─────────┴──────┴──────┴──────┼──────┼───────┼─────┐   ┌────┼─────────┼──────┼────┴───────────┴────────────┴─────────┘
//                                   │  no  │  no   │     │   │ no │   no    │  no  │
//                                   └──────┴───────┴─────┘   └────┴─────────┴──────┘
[_NAV] = LAYOUT_split_3x6_3(
  QK_BOOT , KC_ENT  , KC_SPC  , KC_TAB  , KC_BSPC , CUT     ,                         XXXXXXX , UNDO    , XXXXXXX , XXXXXXX   , XXXXXXX    , QK_BOOT,
  KC_CAPS , KC_LCTL , KC_LALT , KC_LGUI , KC_LSFT , COPY    ,                         KC_LEFT , KC_DOWN , KC_UP   , KC_RIGHT  , C(KC_W)    , XXXXXXX,
  CW_TOGG , KC_END  , KC_PGUP , KC_PGDN , KC_HOME , PASTE   ,                         SEL_ALL , FIND    , XXXXXXX , SAFE_COPY , SAFE_PASTE , XXXXXXX,
                                          XXXXXXX , XXXXXXX , _______ ,     XXXXXXX , XXXXXXX , XXXXXXX
),

//    ┌──────────┬──────┬──────┬──────┬──────┬────┐             ┌──────┬────┬────┬────┬─────┬─────┐
//    │ COLEMAK  │ mprv │  no  │ mply │ mnxt │ no │             │ mute │ f7 │ f8 │ f9 │ f10 │ f13 │
//    ├──────────┼──────┼──────┼──────┼──────┼────┤             ├──────┼────┼────┼────┼─────┼─────┤
//    │ GRAPHITE │ lctl │ lalt │ lgui │ lsft │ no │             │ volu │ f4 │ f5 │ f6 │ f11 │ f14 │
//    ├──────────┼──────┼──────┼──────┼──────┼────┤             ├──────┼────┼────┼────┼─────┼─────┤
//    │    no    │ bRID │  no  │  no  │ bRIU │ no │             │ vold │ f1 │ f2 │ f3 │ f12 │ f15 │
//    └──────────┴──────┴──────┴──────┼──────┼────┼────┐   ┌────┼──────┼────┼────┴────┴─────┴─────┘
//                                    │      │ no │ no │   │ no │  no  │ no │
//                                    └──────┴────┴────┘   └────┴──────┴────┘
[_FN] = LAYOUT_split_3x6_3(
  COLEMAK  , KC_MPRV , XXXXXXX , KC_MPLY , KC_MNXT , XXXXXXX ,                         KC_MUTE , KC_F7   , KC_F8 , KC_F9 , KC_F10 , KC_F13,
  GRAPHITE , KC_LCTL , KC_LALT , KC_LGUI , KC_LSFT , XXXXXXX ,                         KC_VOLU , KC_F4   , KC_F5 , KC_F6 , KC_F11 , KC_F14,
  XXXXXXX  , KC_BRID , XXXXXXX , XXXXXXX , KC_BRIU , XXXXXXX ,                         KC_VOLD , KC_F1   , KC_F2 , KC_F3 , KC_F12 , KC_F15,
                                           _______ , XXXXXXX , XXXXXXX ,     XXXXXXX , XXXXXXX , XXXXXXX
)
};


uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TAB_NUM:
        case TAB_NAV:
        case BSPC_NAV:
        case SPC_SYM:
        case SPC_NAV:
        case ENT_FN:
        case ENT_NUM:
        case ENT_NAV:
        case ESC_WLD:
            return 120;
        default:
            return TAPPING_TERM;
    }
}


const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
    LAYOUT(
        'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R',
                       '*', '*', '*',  '*', '*', '*'
    );

bool is_flow_tap_key(uint16_t keycode) {
    if ((get_mods() & (MOD_MASK_CG | MOD_BIT_LALT)) != 0) {
        return false; // Disable Flow Tap on hotkeys.
    }

    switch (get_tap_keycode(keycode)) {
        case KC_A:
        case KC_B:
        case KC_C:
        case KC_D:
        case KC_E:
        case KC_F:
        case KC_G:
        case KC_H:
        case KC_I:
        case KC_J:
        case KC_K:
        case KC_L:
        case KC_M:
        case KC_N:
        case KC_O:
        case KC_P:
        case KC_Q:
        case KC_R:
        case KC_S:
        case KC_T:
        case KC_U:
        case KC_V:
        case KC_W:
        case KC_X:
        case KC_Y:
        case KC_Z:
        case KC_DOT:
        case KC_COMM:
        case KC_SCLN:
        case KC_SLSH:
        case TAB_NUM:
        case TAB_NAV:
        case BSPC_NAV:
        case SPC_SYM:
        case SPC_NAV:
        case ENT_FN:
        case ENT_NUM:
        case ENT_NAV:
        case ESC_WLD:
            return true;
    }
    return false;
}

// bool get_chordal_hold(uint16_t tap_hold_keycode, keyrecord_t* tap_hold_record,
//                       uint16_t other_keycode, keyrecord_t* other_record) {
//     bool tap_hold_chordal = tap_hold_record->event.key.row < MATRIX_ROWS / 2;
//     bool other_chordal = other_record->event.key.row < MATRIX_ROWS / 2;
//
//     if ((tap_hold_chordal && other_chordal) || (!tap_hold_chordal && !other_chordal)) {
//         return false;
//     }
//
//
//     return get_chordal_hold_default(tap_hold_record, other_record);
// }

// Modify these values to adjust the scrolling speed
#define SCROLL_DIVISOR_H 12.0
#define SCROLL_DIVISOR_V 12.0

// Variables to store accumulated scroll values
float scroll_accumulated_h = 0;
float scroll_accumulated_v = 0;

// Function to handle mouse reports and perform drag scrolling
report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    // Calculate and accumulate scroll values based on mouse movement and divisors
    scroll_accumulated_h += (float)mouse_report.x / SCROLL_DIVISOR_H;
    scroll_accumulated_v += (float)mouse_report.y / SCROLL_DIVISOR_V;

    // Assign integer parts of accumulated scroll values to the mouse report
    mouse_report.h = (int8_t)scroll_accumulated_h;
    mouse_report.v = (int8_t)scroll_accumulated_v;

    // Update accumulated scroll values by subtracting the integer parts
    scroll_accumulated_h -= (int8_t)scroll_accumulated_h;
    scroll_accumulated_v -= (int8_t)scroll_accumulated_v;

    // Clear the X and Y values of the mouse report
    mouse_report.x = 0;
    mouse_report.y = 0;
    return mouse_report;
}

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
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
        case SAFE_COPY:
            if (record->event.pressed) {
                register_code16(use_ctrl ? C(S(KC_C)) : G(S(KC_C)));
            } else {
                unregister_code16(use_ctrl ? C(S(KC_C)) : G(S(KC_C)));
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
        case GRAPHITE:
            if (!record->event.pressed) {
                set_single_persistent_default_layer(_GRAPHITE);
            }
            return false;
        case COLEMAK:
            if (!record->event.pressed) {
                set_single_persistent_default_layer(_COLEMAK);
            }
            return false;
    }

  return true;
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
