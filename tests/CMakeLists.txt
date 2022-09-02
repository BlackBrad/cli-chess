cmake_minimum_required(VERSION 3.0)

set(CHESS_TEST_TARGET chessTest)

set(CHESS_TEST_SRC_FILES chessTest.c
                         ../src/piece.c)

set(PIECE_TEST_TARGET pieceTest)

set(PIECE_TEST_SRC_FILES pieceTest.c)

# Turn off warnings about unused variables as gcc will complain about the
# void **state that is in every unit tests parameter list even though we don't
# use it
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wno-unused-parameter")

add_executable(${CHESS_TEST_TARGET} ${CHESS_TEST_SRC_FILES})

add_executable(${PIECE_TEST_TARGET} ${PIECE_TEST_SRC_FILES})

target_link_libraries(${CHESS_TEST_TARGET} cmocka)

target_link_libraries(${PIECE_TEST_TARGET} cmocka)
