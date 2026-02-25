cmake_minimum_required(VERSION 4.1)
project(2hu)

# Always copy the assets folder every build
add_custom_target(copy_assets ALL
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/assets
        ${CMAKE_BINARY_DIR}/assets
        COMMENT "Copying assets folder to build directory"
)

set(CMAKE_CXX_STANDARD 20)

add_executable(2hu main.cpp
        classes/GameObject.cpp
        classes/GameObject.h
        GameObjects/Sprite.cpp
        GameObjects/Sprite.h
        GameObjects/Player.cpp
        GameObjects/Player.h
        classes/Scene.cpp
        classes/Scene.h
        Game.cpp
        Game.h
        math/Vector2.h
        GameObjects/PlayerBullet.cpp
        GameObjects/PlayerBullet.h
        GameObjects/Enemy.cpp
        GameObjects/Enemy.h
        GameObjects/Enemies/WaveFairy.cpp
        GameObjects/Enemies/WaveFairy.h
        GameObjects/Bullet.cpp
        GameObjects/Bullet.h
        CONFIG.h
        classes/FontObject.cpp
        classes/FontObject.h
        GLOBAL.h
)

# Ensure assets are copied before building the executable
add_dependencies(2hu copy_assets)

find_package(SDL3 CONFIG REQUIRED)
target_link_libraries(2hu PRIVATE SDL3::SDL3)

find_package(SDL3_image CONFIG REQUIRED)
target_link_libraries(2hu PRIVATE SDL3_image::SDL3_image)

find_package(SDL3_ttf CONFIG REQUIRED)
target_link_libraries(2hu PRIVATE SDL3_ttf::SDL3_ttf)

