#include <assert.h>
#include <stddef.h>

#include "chess.h"

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

#include <stdio.h>

static piece_t *create_new_piece(uint8_t colour, uint8_t type){
    piece_t *new_piece = calloc(1, sizeof(piece_t));

    if (!new_piece){
        printf("Unable to allocate memory!\n");
        return NULL;
    }

    new_piece->colour = colour;
    new_piece->type = type;

    return new_piece;
}

static void fill_board_with_empty_spaces(chess_t *chess_game) {
    assert(chess_game != NULL);

    for (uint8_t i = 0; i < BOARD_SIZE; i++){
        for (uint8_t j = 0; j < BOARD_SIZE; j++){
            chess_game->board[i][j] = create_new_piece(NO_COLOUR, EMPTY);
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

            chess_game->board[row][i]->colour = j;
            chess_game->board[row][i]->type = PAWN;
        }
    }
}

static void create_new_board(chess_t *chess_game){
    fill_board_with_empty_spaces(chess_game);
    populate_default_pawn_rows(chess_game);

    chess_game->board[DEFAULT_BLACK_OTHER_PIECE_ROW][DEFAULT_LEFT_ROOK] =
        create_new_piece(BLACK, ROOK);
    chess_game->board[DEFAULT_BLACK_OTHER_PIECE_ROW][DEFAULT_RIGHT_ROOK] =
        create_new_piece(BLACK, ROOK);
    chess_game->board[DEFAULT_BLACK_OTHER_PIECE_ROW][DEFAULT_LEFT_KNIGHT] =
        create_new_piece(BLACK, KNIGHT);
    chess_game->board[DEFAULT_BLACK_OTHER_PIECE_ROW][DEFAULT_RIGHT_KNIGHT] =
        create_new_piece(BLACK, KNIGHT);
    chess_game->board[DEFAULT_BLACK_OTHER_PIECE_ROW][DEFAULT_LEFT_BISHOP] =
        create_new_piece(BLACK, BISHOP);
    chess_game->board[DEFAULT_BLACK_OTHER_PIECE_ROW][DEFAULT_RIGHT_BISHOP] =
        create_new_piece(BLACK, BISHOP);
    chess_game->board[DEFAULT_BLACK_OTHER_PIECE_ROW][DEFAULT_QUEEN] =
        create_new_piece(BLACK, QUEEN);
    chess_game->board[DEFAULT_BLACK_OTHER_PIECE_ROW][DEFAULT_KING] =
        create_new_piece(BLACK, KING);


    chess_game->board[DEFAULT_WHITE_OTHER_PIECE_ROW][DEFAULT_LEFT_ROOK] =
        create_new_piece(WHITE, ROOK);
    chess_game->board[DEFAULT_WHITE_OTHER_PIECE_ROW][DEFAULT_RIGHT_ROOK] =
        create_new_piece(WHITE, ROOK);
    chess_game->board[DEFAULT_WHITE_OTHER_PIECE_ROW][DEFAULT_LEFT_KNIGHT] =
        create_new_piece(WHITE, KNIGHT);
    chess_game->board[DEFAULT_WHITE_OTHER_PIECE_ROW][DEFAULT_RIGHT_KNIGHT] =
        create_new_piece(WHITE, KNIGHT);
    chess_game->board[DEFAULT_WHITE_OTHER_PIECE_ROW][DEFAULT_LEFT_BISHOP] =
        create_new_piece(WHITE, BISHOP);
    chess_game->board[DEFAULT_WHITE_OTHER_PIECE_ROW][DEFAULT_RIGHT_BISHOP] =
        create_new_piece(WHITE, BISHOP);
    chess_game->board[DEFAULT_WHITE_OTHER_PIECE_ROW][DEFAULT_QUEEN] =
        create_new_piece(WHITE, QUEEN);
    chess_game->board[DEFAULT_WHITE_OTHER_PIECE_ROW][DEFAULT_KING] =
        create_new_piece(WHITE, KING);
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
}

