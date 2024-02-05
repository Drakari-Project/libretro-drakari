#include "libretro.h"

const struct retro_system_info SYSTEM_INFO = {
    .library_name = "Drakari",
    .library_version = "0.1.0",
    .valid_extensions = "toml",
    .need_fullpath = true,
    .block_extract = false,
};

const struct retro_system_av_info SYSTEM_AV_INFO = {
    .geometry = {
        .base_width = 800,
        .base_height = 400,
        .max_width = 1024,
        .max_height = 768,
        .aspect_ratio = -1.0f,
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
