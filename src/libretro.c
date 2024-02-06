#include <stdio.h>
#include "libretro.h"
#include "system_info.h"

extern retro_environment_t environ_cb;
extern retro_video_refresh_t video_cb;

static inline uint16_t rgb565(uint8_t r, uint8_t g, uint8_t b) {
    return ((r >> 3U) << 11U) | ((g >> 2U) << 5U) | ((b >> 3U) << 0U);
}
#define WHITE rgb565(255, 255, 255)
#define BLACK rgb565(0, 0, 0)

void retro_init(void) {
    
}

bool retro_load_game(const struct retro_game_info* info) {
    struct retro_input_descriptor desc[] = {
        {0, RETRO_DEVICE_JOYPAD, 0, RETRO_DEVICE_ID_JOYPAD_LEFT, "Left"},
        {0, RETRO_DEVICE_JOYPAD, 0, RETRO_DEVICE_ID_JOYPAD_UP, "Up"},
        {0, RETRO_DEVICE_JOYPAD, 0, RETRO_DEVICE_ID_JOYPAD_DOWN, "Down"},
        {0, RETRO_DEVICE_JOYPAD, 0, RETRO_DEVICE_ID_JOYPAD_RIGHT, "Right"},
        {0, RETRO_DEVICE_JOYPAD, 0, RETRO_DEVICE_ID_JOYPAD_A, "A"},
        {0, RETRO_DEVICE_JOYPAD, 0, RETRO_DEVICE_ID_JOYPAD_B, "B"},
        {0, RETRO_DEVICE_NONE, 0, 0, NULL},
    };

    environ_cb(RETRO_ENVIRONMENT_SET_INPUT_DESCRIPTORS, desc);

    return true;
}

void retro_run(void) {
    uint16_t fb[64 * 128];
    for (uint16_t i = 0; i < (128 * 64) - 1; i++)
    {
        fb[i] = BLACK;
    }
    
    fb[0] = rgb565(255, 0, 0);
    fb[768 + 1] = rgb565(0, 255, 0);
    fb[768 + 2] = rgb565(0, 0, 255);
    video_cb((void*)fb, 64, 64, 128 * sizeof(uint16_t));
}

