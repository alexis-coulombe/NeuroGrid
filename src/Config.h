#ifndef ASM_SRC_CONFIG_H_
#define ASM_SRC_CONFIG_H_

#define GAME_TITLE ("NeuroGrid")

// Mechanics
#define MAX_TEXTAREA_LINES (20)
#define MAX_TEXTAREA_LINE_LENGTH (20)

#define MAX_MISSIONS (40)

// Engine
#define TARGET_FPS (50)

// Window
#define WINDOW_TITLE (GAME_TITLE)
#define WINDOW_WIDTH_RESOLUTION (1600)
#define WINDOW_HEIGHT_RESOLUTION (900)
#define WINDOW_FULLSCREEN (0)

// Audio
#define AUDIO_FREQUENCY (44100)
#define AUDIO_CHANNELS (2)
#define AUDIO_CHUNKSIZE (1024)
#define AUDIO_CHANNEL_COUNT (8)

// Save
#define SAVE_FILE_VERSION (0x00)
#define CONFIG_FILE_VERSION (1)

#define LINUX_SAVE_FILE_PATH (std::string(std::getenv("HOME")) + "/.local/share/" + GAME_TITLE + "/")
#define WINDOWS_SAVE_FILE_PATH (std::string(std::getenv("USERPROFILE")) + "/AppData/Roaming/" + GAME_TITLE + "/")
#define MACOS_SAVE_FILE_PATH (std::string(std::getenv("HOME")) + "/Library/Application Support/" + GAME_TITLE + "/")
#define UNKNOWN_SAVE_FILE_PATH (std::string(std::getenv("HOME")) + "/" + GAME_TITLE + "/")

#define LINUX_CONFIG_FILE_PATH (LINUX_SAVE_FILE_PATH)
#define WINDOWS_CONFIG_FILE_PATH (WINDOWS_SAVE_FILE_PATH)
#define MACOS_CONFIG_FILE_PATH (MACOS_SAVE_FILE_PATH)
#define UNKNOWN_CONFIG_FILE_PATH (UNKNOWN_SAVE_FILE_PATH)

#endif //ASM_SRC_CONFIG_H_
