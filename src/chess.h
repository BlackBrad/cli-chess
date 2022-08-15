#ifndef BLACKBRAD_CLI_CHESS
#define BLACKBRAD_CLI_CHESS

#define BOARD_SIZE 8

#include <stdint.h>

enum PIECES {
    EMPTY      = 0, // No pieces on board
    PAWN       = 1,
    ROOK       = 2,
    KNIGHT     = 3,
    BISHOP     = 4,
    QUEEN      = 5,
    KING       = 6,
    NUM_PIECES = 7
};

enum Colours {
    WHITE       = 0,
    BLACK       = 1,
    NUM_COLOURS = 2,
    NO_COLOUR   = 3
};

typedef struct Piece{
    uint8_t colour;
    uint8_t type;
} piece_t;

typedef struct Player{
    uint8_t colour;
    uint8_t points;
    uint8_t pieces[];
} player_t;

typedef struct Chess{
    piece_t *board[BOARD_SIZE][BOARD_SIZE];
    player_t players[NUM_COLOURS];
} chess_t;

/* chess_new_game
 *
 * Sets a chess_t instance to default values
 *
 * Returns:
 *     chess_t: A new chess struct
 */
chess_t chess_new_game();

/* chess_free
 *
 * Clears all memory allocated by the chess library
 *
 * Args:
 *     chess_game (chess_t*): The chess_t instance to free all allocated memory from
 *
 * Returns:
 *     void
 */
void chess_free(chess_t *chess_game);
#endif
