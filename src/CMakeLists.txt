cmake_minimum_required(VERSION 3.0)

set (CHESS_TARGET cli-chess)

set (CHESS_SRC_FILES chess.c)

set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Werror -Wall")

add_executable(${CHESS_TARGET} ${CHESS_SRC_FILES})
