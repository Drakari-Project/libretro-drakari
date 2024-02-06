#include <stdio.h>
#include "libretro.h"
#include "system_info.h"

 retro_environment_t environ_cb;
 retro_video_refresh_t video_cb;
 retro_audio_sample_t audio_cb;
 retro_audio_sample_batch_t audio_batch_cb;
 retro_input_poll_t input_poll_cb;
 retro_input_state_t input_state_cb;
 retro_log_printf_t log_cb;

void retro_set_environment(retro_environment_t cb) {
    environ_cb = cb;
    bool no_rom = true;
    cb(RETRO_ENVIRONMENT_SET_SUPPORT_NO_GAME, &no_rom);
    int pixel_format = RETRO_PIXEL_FORMAT_RGB565;
    cb(RETRO_ENVIRONMENT_SET_PIXEL_FORMAT, &pixel_format);
    struct retro_log_callback log;
    unsigned level = 4;

    if (environ_cb(RETRO_ENVIRONMENT_GET_LOG_INTERFACE, &log)) {
        log_cb = log.log;
    } else {
        log_cb = NULL;
    }

    environ_cb(RETRO_ENVIRONMENT_SET_PERFORMANCE_LEVEL, &level);
}
void retro_set_video_refresh(retro_video_refresh_t cb) {video_cb = cb;}
void retro_set_audio_sample(retro_audio_sample_t cb) {audio_cb = cb;}
void retro_set_audio_sample_batch(retro_audio_sample_batch_t cb) { audio_batch_cb = cb;}
void retro_set_input_poll(retro_input_poll_t cb) {input_poll_cb = cb;}
void retro_set_input_state(retro_input_state_t cb) {input_state_cb = cb;}

const struct retro_system_info SYSTEM_INFO = {
    .library_name = "Drakari",
    .library_version = "0.1.0",
    .valid_extensions = "toml",
    .need_fullpath = true,
    .block_extract = false,
};

const struct retro_system_av_info SYSTEM_AV_INFO = {
    .geometry = {
        .base_width = 128,
        .base_height = 64,
        .max_width = 128,
        .max_height = 64,
        .aspect_ratio = 2.0f,
    },
    .timing = {
        .fps = 60.0,
        .sample_rate = 44100,
    },
};

RETRO_API unsigned retro_api_version() {
    return RETRO_API_VERSION;
}

RETRO_API void retro_get_system_info(struct retro_system_info *info) {
    *info = SYSTEM_INFO;
}

RETRO_API void retro_get_system_av_info(struct retro_system_av_info *info) {
    *info = SYSTEM_AV_INFO;
}

//IDK
unsigned retro_get_region(void) { return RETRO_REGION_NTSC; }

//Unused Functions BREAK IF REMOVED
void retro_unload_game(void) {}
void retro_reset(void) {}
void retro_cheat_reset(void) {}
void retro_cheat_set(unsigned index, bool enabled, const char* code) {}
bool retro_load_game_special(unsigned game_type, const struct retro_game_info* info, size_t num_info) { return false; }
void retro_set_controller_port_device(unsigned port, unsigned device) {}
void* retro_get_memory_data(unsigned id) { return NULL; }
size_t retro_get_memory_size(unsigned id) { return 0; }
size_t retro_serialize_size(void) { return 0; }
bool retro_serialize(void* data, size_t size) { return false; }
bool retro_unserialize(const void* data, size_t size) { return false; }
void retro_deinit(void) {}