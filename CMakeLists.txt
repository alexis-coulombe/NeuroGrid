cmake_minimum_required(VERSION 3.28)
project(ASM)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)

# Find the SDL2 package
find_package(PkgConfig REQUIRED)
pkg_search_module(SDL2 REQUIRED sdl2)
pkg_search_module(SDL2_TTF REQUIRED SDL2_ttf)
pkg_search_module(SDL2_MIXER REQUIRED SDL2_mixer)
pkg_search_module(SDL2_IMAGE REQUIRED SDL2_image)

file(GLOB SOURCE_FILES
        "*.cpp" ,
        "src/engine/*.cpp" ,
        "src/engine/utility/*.cpp" ,
        "src/engine/ui/*.cpp" ,
        "src/game/*.cpp" ,
        "src/game/ui/menu/*.cpp" ,
)

file(GLOB ASSETS
        "assets/*" ,
        "assets/menu/*"
        "assets/music/*"
)

# Add your executable
add_executable(ASM ${SOURCE_FILES} ${ASSETS})

file(COPY ${ASSETS} DESTINATION assets)

# Include SDL2 directories
include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_TTF_INCLUDE_DIRS} ${SDL2_MIXER_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS})

# Link SDL2 libraries
target_link_libraries(ASM ${SDL2_LIBRARIES} ${SDL2_TTF_LIBRARIES} ${SDL2_MIXER_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})
