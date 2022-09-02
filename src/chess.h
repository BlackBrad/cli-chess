#ifndef BLACKBRAD_CLI_CHESS
#define BLACKBRAD_CLI_CHESS

#define BOARD_SIZE 8
#define MAX_CAPUTRED_PIECES 15

#include <stdint.h>

#include "piece.h"

typedef struct Player{
    uint8_t colour;
    uint8_t points;
    uint8_t captured_pieces[MAX_CAPUTRED_PIECES];
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
