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

#if 0
static void validate_board(chess_t *chess_game, uint8_t expected_board[BOARD_SIZE][BOARD_SIZE]){
    for (uint8_t i = 0; i < BOARD_SIZE; i++){
        for (uint8_t j = 0; j < BOARD_SIZE; j++){
            assert_int_equal(chess_game->board[i][j], expected_board[i][j]);
        }
    }
}
#endif

static void test_fill_board_with_empty_spaces(void **state){
    chess_t test_chess;

    fill_board_with_empty_spaces(&test_chess);

    for (uint8_t i = 0; i < BOARD_SIZE; i++){
        for (uint8_t j = 0; j < BOARD_SIZE; j++){
            assert_int_equal(test_chess.board[i][i]->type, EMPTY);
            assert_int_equal(test_chess.board[i][i]->colour, NO_COLOUR);
        }
    }
}

// As chess_t.board has it's memory allocated by fill_board_with_empty_spaces we are actually unable to test
// populate_default_pawn_rows in isolation. So we must call fill_board_with_empty_spaces before we call
// populate_default_pawn_rows
static void test_populate_default_pawn_row_with_empty_spaces(void **state){
    chess_t test_chess;

    fill_board_with_empty_spaces(&test_chess);
    populate_default_pawn_rows(&test_chess);

    // Ensure that all the pawns are where they belong, and other board squares are set to EMPTY
    for (uint8_t i = 0; i < BOARD_SIZE; i++){
        for (uint8_t j = 0; j < BOARD_SIZE; j++){
            // We expect any square that is not a PAWN to be empty
            uint8_t expected_type = EMPTY;

            // If the current row is the WHITE or BLACK pawn rows then the expected type is PAWN
            if (i == DEFAULT_WHITE_PAWN_ROW || i == DEFAULT_BLACK_PAWN_ROW){
                expected_type = PAWN;
            }
            assert_int_equal(test_chess.board[i][j]->type, expected_type);
        }
    }
}

#if 0
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
#endif
int main(void){
    const struct CMUnitTest tests[] = {
      cmocka_unit_test(test_fill_board_with_empty_spaces),
      cmocka_unit_test(test_populate_default_pawn_row_with_empty_spaces),
      //  cmocka_unit_test(test_create_new_board),
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}
