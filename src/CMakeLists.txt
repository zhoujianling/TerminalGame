cmake_minimum_required(VERSION 3.5) #设置CMake最小版本
project (terminal_game) #设置工程名

set (
    SRC_FILES
    Main.cpp
    core/GameCore.cpp
    core/Input.cpp
    core/Terminal.cpp
    core/TerminalController.cpp
    gameplay/Entity.cpp
    gameplay/Game.cpp
    scene/Camera.cpp
    scene/Node.cpp
    scene/Scene.cpp
    scene/Sprite.cpp
    scene/Transform.cpp
    utils/Math.cpp
)
add_executable(TerminalGame ${SRC_FILES}) #生成可执行文件
set(CXX_STANDARD 14)