#include QMK_KEYBOARD_H

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

enum layers {
    _COLEMAK = 0,
    _QWERTY,
    _NUM,
    _SYM,
    _NAV,
    _FN
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//    ┌──────┬─────────┬─────────┬─────────┬─────────┬───────────────┐                                                   ┌──────┬─────────┬─────────┬─────────┬─────────┬──────┐
//    │  `   │    q    │    w    │    f    │    p    │       b       │                                                   │  j   │    l    │    u    │    y    │    '    │ bspc │
//    ├──────┼─────────┼─────────┼─────────┼─────────┼───────────────┤                                                   ├──────┼─────────┼─────────┼─────────┼─────────┼──────┤
//    │ esc  │ LCTL_KA │ LALT_KR │ LGUI_KS │ LSFT_KT │       g       │                                                   │  m   │ LSFT_KN │ LGUI_KE │ LALT_KI │ LCTL_KO │  ;   │
//    ├──────┼─────────┼─────────┼─────────┼─────────┼───────────────┤                                                   ├──────┼─────────┼─────────┼─────────┼─────────┼──────┤
//    │ lsft │    z    │    x    │    c    │    d    │       v       │                                                   │  k   │    h    │    ,    │    .    │    /    │ rsft │
//    └──────┴─────────┴─────────┴─────────┼─────────┼───────────────┼────────────────┐   ┌───────────────┬──────────────┼──────┼─────────┴─────────┴─────────┴─────────┴──────┘
//                                         │  lgui   │ LT(_NUM, tab) │ LT(_NAV, bspc) │   │ LT(_SYM, spc) │ LT(_FN, ent) │ ralt │
//                                         └─────────┴───────────────┴────────────────┘   └───────────────┴──────────────┴──────┘
[_COLEMAK] = LAYOUT_split_3x6_3(
  KC_GRV  , KC_Q    , KC_W    , KC_F    , KC_P    , KC_B             ,                                                              KC_J    , KC_L    , KC_U    , KC_Y    , KC_QUOT , KC_BSPC,
  KC_ESC  , LCTL_KA , LALT_KR , LGUI_KS , LSFT_KT , KC_G             ,                                                              KC_M    , LSFT_KN , LGUI_KE , LALT_KI , LCTL_KO , KC_SCLN,
  KC_LSFT , KC_Z    , KC_X    , KC_C    , KC_D    , KC_V             ,                                                              KC_K    , KC_H    , KC_COMM , KC_DOT  , KC_SLSH , KC_RSFT,
                                          KC_LGUI , LT(_NUM, KC_TAB) , LT(_NAV, KC_BSPC) ,     LT(_SYM, KC_SPC) , LT(_FN, KC_ENT) , KC_RALT
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

//    ┌─────────┬─────────┬─────────┬─────────┬──────┬────┐                     ┌──────┬──────┬──────┬──────┬──────┬────┐
//    │ QK_BOOT │   no    │   no    │   no    │  no  │ no │                     │  no  │  no  │  no  │  no  │  no  │ no │
//    ├─────────┼─────────┼─────────┼─────────┼──────┼────┤                     ├──────┼──────┼──────┼──────┼──────┼────┤
//    │ CW_TOGG │  lctl   │  lalt   │  lgui   │ lsft │ no │                     │ left │ down │  up  │ rght │ C(w) │ no │
//    ├─────────┼─────────┼─────────┼─────────┼──────┼────┤                     ├──────┼──────┼──────┼──────┼──────┼────┤
//    │ RGB_MOD │ RGB_HUD │ RGB_SAD │ RGB_VAD │  no  │ no │                     │  no  │ home │ pgdn │ pgup │ end  │ no │
//    └─────────┴─────────┴─────────┴─────────┼──────┼────┼─────┐   ┌─────┬─────┼──────┼──────┴──────┴──────┴──────┴────┘
//                                            │  no  │ no │     │   │ ent │     │ ralt │
//                                            └──────┴────┴─────┘   └─────┴─────┴──────┘
[_NAV] = LAYOUT_split_3x6_3(
  QK_BOOT , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,                                  XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX  , XXXXXXX , XXXXXXX,
  CW_TOGG , KC_LCTL , KC_LALT , KC_LGUI , KC_LSFT , XXXXXXX ,                                  KC_LEFT , KC_DOWN , KC_UP   , KC_RIGHT , C(KC_W) , XXXXXXX,
  RGB_MOD , RGB_HUD , RGB_SAD , RGB_VAD , XXXXXXX , XXXXXXX ,                                  XXXXXXX , KC_HOME , KC_PGDN , KC_PGUP  , KC_END  , XXXXXXX,
                                          XXXXXXX , XXXXXXX , _______ ,     KC_ENT , _______ , KC_RALT
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
)
};
