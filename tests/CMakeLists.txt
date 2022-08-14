cmake_minimum_required(VERSION 3.0)

set(CHESS_TEST_TARGET chessTest)

set(CHESS_TEST_SRC_FILES chessTest.c)

set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Werror -Wall -g")

add_executable(${CHESS_TEST_TARGET} ${CHESS_TEST_SRC_FILES})

target_link_libraries(${CHESS_TEST_TARGET} cmocka)
