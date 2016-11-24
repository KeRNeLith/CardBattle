cmake_minimum_required(VERSION 2.8)
project(CardBattle CXX)

set(CMAKE_CXX_STANDARD 11)

file(GLOB_RECURSE card_battle_headers ${PROJECT_SOURCE_DIR}/src/*.h)
file(GLOB_RECURSE card_battle_src ${PROJECT_SOURCE_DIR}/src/*.cpp)
set(SOURCE_FILES main.cpp ${card_battle_headers} ${card_battle_src})

add_executable(CardBattle ${SOURCE_FILES})