#include <assert.h>
#include <stddef.h>

#include "chess.h"
#include "piece.h"

#define DEFAULT_BLACK_PAWN_ROW 1
#define DEFAULT_BLACK_OTHER_PIECE_ROW 0

#define DEFAULT_WHITE_PAWN_ROW 6
#define DEFAULT_WHITE_OTHER_PIECE_ROW 7

// Pieces start position
#define DEFAULT_LEFT_ROOK 0
#define DEFAULT_RIGHT_ROOK 7
#define DEFAULT_LEFT_KNIGHT 1
#define DEFAULT_RIGHT_KNIGHT 6
#define DEFAULT_LEFT_BISHOP 2
#define DEFAULT_RIGHT_BISHOP 5
#define DEFAULT_QUEEN 3
#define DEFAULT_KING 4

static void fill_board_with_empty_spaces(chess_t *chess_game) {
    assert(chess_game != NULL);

    for (uint8_t i = 0; i < BOARD_SIZE; i++){
        for (uint8_t j = 0; j < BOARD_SIZE; j++){
            piece_t *new_piece = piece_new(NO_COLOUR, EMPTY, i, j);

            assert(new_piece != NULL);

            chess_game->board[i][j] = new_piece;
        }
    }
}

static void populate_default_pawn_rows(chess_t *chess_game){
    assert(chess_game != NULL);

    // Populate the PAWNS rows
    for (uint8_t i = 0; i < BOARD_SIZE; i++){
        for (uint8_t j = 0; j < NUM_COLOURS; j++){
            uint8_t row = DEFAULT_WHITE_PAWN_ROW;

            if (j == BLACK){
                row = DEFAULT_BLACK_PAWN_ROW;
            }

            // We don't need to create a new piece seeing as all entries of
            // the board are already set to a piece_t, all we need to do is
            // change the colour and type.
            chess_game->board[row][i]->colour = j;
            chess_game->board[row][i]->type = PAWN;
        }
    }
}

static void create_new_board(chess_t *chess_game){
    assert(chess_game != NULL);

    fill_board_with_empty_spaces(chess_game);
    populate_default_pawn_rows(chess_game);

    // Black pieces first as this is the top of the board
    chess_game->board[
        DEFAULT_BLACK_OTHER_PIECE_ROW][DEFAULT_LEFT_ROOK]->type = ROOK;
    chess_game->board[
        DEFAULT_BLACK_OTHER_PIECE_ROW][DEFAULT_RIGHT_ROOK]->type = ROOK;
    chess_game->board[
        DEFAULT_BLACK_OTHER_PIECE_ROW][DEFAULT_LEFT_KNIGHT]->type = KNIGHT;
    chess_game->board[
        DEFAULT_BLACK_OTHER_PIECE_ROW][DEFAULT_RIGHT_KNIGHT]->type = KNIGHT;
    chess_game->board[
        DEFAULT_BLACK_OTHER_PIECE_ROW][DEFAULT_LEFT_BISHOP]->type = BISHOP;
    chess_game->board[
        DEFAULT_BLACK_OTHER_PIECE_ROW][DEFAULT_RIGHT_BISHOP]->type = BISHOP;
    chess_game->board[
        DEFAULT_BLACK_OTHER_PIECE_ROW][DEFAULT_QUEEN]->type = QUEEN;
    chess_game->board[
        DEFAULT_BLACK_OTHER_PIECE_ROW][DEFAULT_KING]->type = KING;

    // Now set all the pieces in DEFAULT_BLACK_OTHER_PIECE_ROW to BLACK
    for (uint8_t i = 0; i < BOARD_SIZE; i++){
        chess_game->board[DEFAULT_BLACK_OTHER_PIECE_ROW][i]->colour = BLACK;
    }


    // Now the white pieces
    chess_game->board[
        DEFAULT_WHITE_OTHER_PIECE_ROW][DEFAULT_LEFT_ROOK]->type = ROOK;
    chess_game->board[
        DEFAULT_WHITE_OTHER_PIECE_ROW][DEFAULT_RIGHT_ROOK]->type = ROOK;
    chess_game->board[
        DEFAULT_WHITE_OTHER_PIECE_ROW][DEFAULT_LEFT_KNIGHT]->type = KNIGHT;
    chess_game->board[
        DEFAULT_WHITE_OTHER_PIECE_ROW][DEFAULT_RIGHT_KNIGHT]->type = KNIGHT;
    chess_game->board[
        DEFAULT_WHITE_OTHER_PIECE_ROW][DEFAULT_LEFT_BISHOP]->type = BISHOP;
    chess_game->board[
        DEFAULT_WHITE_OTHER_PIECE_ROW][DEFAULT_RIGHT_BISHOP]->type = BISHOP;
    chess_game->board[
        DEFAULT_WHITE_OTHER_PIECE_ROW][DEFAULT_QUEEN]->type = QUEEN;
    chess_game->board[
        DEFAULT_WHITE_OTHER_PIECE_ROW][DEFAULT_KING]->type = KING;

    // Now set all the pieces in DEFAULT_WHITE_OTHER_PIECE_ROW to WHITE
    for (uint8_t i = 0; i < BOARD_SIZE; i++){
        chess_game->board[DEFAULT_WHITE_OTHER_PIECE_ROW][i]->colour = WHITE;
    }
}

chess_t chess_new_game(){
    chess_t new_chess_game;

    create_new_board(&new_chess_game);

    return new_chess_game;
}


void free_chess(chess_t *chess_game){
    for (uint8_t i = 0; i < BOARD_SIZE; i++){
        for (uint8_t j = 0; j < BOARD_SIZE; j++){
            free(chess_game->board[i][j]);
        }
    }
    chess_game = NULL;
}
