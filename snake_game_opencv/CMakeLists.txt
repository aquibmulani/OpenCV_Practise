cmake_minimum_required(VERSION 2.8)
project( snake_game_opencv )
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )
add_executable( snake_game_opencv game.cpp )
target_link_libraries( snake_game_opencv ${OpenCV_LIBS} )
