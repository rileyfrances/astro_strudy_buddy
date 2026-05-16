cmake_minimum_required(VERSION 3.10)
project(AstroStudyBuddy)
set(CMAKE_CXX_STANDARD 11)
enable_testing()

add_library(game_lib
    src/Game.cpp
    src/Level.cpp
    src/Player.cpp
    src/Question.cpp
)
add_executable(game
    src/main.cpp
)
target_link_libraries(game game_lib)
add_executable(tests
    tests/test_main.cpp
)
target_link_libraries(tests game_lib)
add_test(NAME GameTests COMMAND tests)