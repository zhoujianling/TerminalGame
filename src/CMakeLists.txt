cmake_minimum_required(VERSION 3.5) #设置CMake最小版本
project (terminal_game) #设置工程名

set (
    SRC_FILES
    Main.cpp
    TankGame.cpp # temp
    core/GameCore.cpp
    core/Input.cpp
    core/Game.cpp
    view/Terminal.cpp
    view/TerminalController.cpp
    view/Appearance.cpp
    view/Element.cpp
    scene/Camera.cpp
    scene/Component.cpp
    scene/Node.cpp
    scene/Scene.cpp
    scene/Sprite.cpp
    scene/Transform.cpp
    scene/HeroController.cpp # temp
    utils/Math.cpp
)
add_executable(TerminalGame ${SRC_FILES}) #生成可执行文件
set(CXX_STANDARD 14)