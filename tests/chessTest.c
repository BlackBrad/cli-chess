#include <stdarg.h>
#include <stdint.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include <string.h>

//For utilities
#include <stdlib.h>


// Include the .c file so that we can test static functions
#include "../src/chess.c"

static void validate_board(chess_t *chess_game, uint8_t expected_board[BOARD_SIZE][BOARD_SIZE]){
    for (uint8_t i = 0; i < BOARD_SIZE; i++){
        for (uint8_t j = 0; j < BOARD_SIZE; j++){
            assert_int_equal(chess_game->board[i][j], expected_board[i][j]);
        }
    }
}

static void test_create_new_board(void **state){
    chess_t test_chess;
    uint8_t expected_chess_board[BOARD_SIZE][BOARD_SIZE] = {
    {ROOK, KNIGHT, BISHOP, QUEEN, KING, BISHOP, KNIGHT, ROOK},
    {PAWN, PAWN,   PAWN,   PAWN,  PAWN, PAWN,   PAWN,   PAWN},
    {EMPTY, EMPTY, EMPTY,  EMPTY, EMPTY, EMPTY, EMPTY,  EMPTY},
    {EMPTY, EMPTY, EMPTY,  EMPTY, EMPTY, EMPTY, EMPTY,  EMPTY},
    {EMPTY, EMPTY, EMPTY,  EMPTY, EMPTY, EMPTY, EMPTY,  EMPTY},
    {EMPTY, EMPTY, EMPTY,  EMPTY, EMPTY, EMPTY, EMPTY,  EMPTY},
    {PAWN, PAWN,   PAWN,   PAWN,  PAWN, PAWN,   PAWN,   PAWN},
    {ROOK, KNIGHT, BISHOP, QUEEN, KING, BISHOP, KNIGHT, ROOK},
    };

    create_new_board(&test_chess);

    validate_board(&test_chess, expected_chess_board);
}

int main(void){
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_create_new_board),
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}
