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

typedef struct Chess{
    uint8_t board[BOARD_SIZE][BOARD_SIZE];
} chess_t;

/* chess_new_game
 *
 * Sets a chess_t instance to default values
 *
 * Returns:
 *     chess_t: A new chess struct
 */
chess_t chess_new_game();

#endif
