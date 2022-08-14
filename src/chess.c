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

static void create_new_board(chess_t* chess_game){
    assert(chess_game != NULL);

    // Populate the PAWNS rows
    for (uint8_t i = 0; i < BOARD_SIZE; i++){
        chess_game->board[DEFAULT_BLACK_PAWN_ROW][i] = PAWN;
        chess_game->board[DEFAULT_WHITE_PAWN_ROW][i] = PAWN;
    }

    chess_game->board[DEFAULT_BLACK_OTHER_PIECE_ROW][DEFAULT_LEFT_ROOK]    = ROOK;
    chess_game->board[DEFAULT_BLACK_OTHER_PIECE_ROW][DEFAULT_RIGHT_ROOK]   = ROOK;
    chess_game->board[DEFAULT_BLACK_OTHER_PIECE_ROW][DEFAULT_LEFT_KNIGHT]  = KNIGHT;
    chess_game->board[DEFAULT_BLACK_OTHER_PIECE_ROW][DEFAULT_RIGHT_KNIGHT] = KNIGHT;
    chess_game->board[DEFAULT_BLACK_OTHER_PIECE_ROW][DEFAULT_LEFT_BISHOP]  = BISHOP;
    chess_game->board[DEFAULT_BLACK_OTHER_PIECE_ROW][DEFAULT_RIGHT_BISHOP] = BISHOP;
    chess_game->board[DEFAULT_BLACK_OTHER_PIECE_ROW][DEFAULT_QUEEN]        = QUEEN;
    chess_game->board[DEFAULT_BLACK_OTHER_PIECE_ROW][DEFAULT_KING]         = KING;

    chess_game->board[DEFAULT_WHITE_OTHER_PIECE_ROW][DEFAULT_LEFT_ROOK]    = ROOK;
    chess_game->board[DEFAULT_WHITE_OTHER_PIECE_ROW][DEFAULT_RIGHT_ROOK]   = ROOK;
    chess_game->board[DEFAULT_WHITE_OTHER_PIECE_ROW][DEFAULT_LEFT_KNIGHT]  = KNIGHT;
    chess_game->board[DEFAULT_WHITE_OTHER_PIECE_ROW][DEFAULT_RIGHT_KNIGHT] = KNIGHT;
    chess_game->board[DEFAULT_WHITE_OTHER_PIECE_ROW][DEFAULT_LEFT_BISHOP]  = BISHOP;
    chess_game->board[DEFAULT_WHITE_OTHER_PIECE_ROW][DEFAULT_RIGHT_BISHOP] = BISHOP;
    chess_game->board[DEFAULT_WHITE_OTHER_PIECE_ROW][DEFAULT_QUEEN]        = QUEEN;
    chess_game->board[DEFAULT_WHITE_OTHER_PIECE_ROW][DEFAULT_KING]         = KING;

    for (uint8_t i = DEFAULT_BLACK_PAWN_ROW + 1; i < DEFAULT_WHITE_PAWN_ROW; i++){
        for (uint8_t j = 0; j < BOARD_SIZE; j++){
            chess_game->board[i][j] = EMPTY;
        }
    }
}

chess_t chess_new_game(){
    chess_t new_chess_game;

    create_new_board(&new_chess_game);


    return new_chess_game;
}
