/* QMK */
#define TAPPING_TERM 180
// #define PERMISSIVE_HOLD

#define CHORDAL_HOLD
#define FLOW_TAP_TERM 150

/* Unicode */
#define UNICODE_SELECTED_MODES UNICODE_MODE_LINUX

/* Mouse */
#define SPLIT_POINTING_ENABLE
#define POINTING_DEVICE_RIGHT
#define POINTING_DEVICE_ROTATION_270
#define ANALOG_JOYSTICK_SPEED_REGULATOR 5
#define ANALOG_JOYSTICK_SPEED_MAX 5

#define DEFAULT_LAYER_SONGS { SONG(QWERTY_SOUND), \
                              SONG(COLEMAK_SOUND), \
                              SONG(DVORAK_SOUND) \
                            }
