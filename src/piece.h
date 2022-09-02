#ifndef CLI_CHESS_PIECE_H
#define CLI_CHESS_PIECE_H

#include <stddef.h>
#include <stdint.h>

enum Piece_type {
    EMPTY      = 0,
    PAWN       = 1,
    ROOK       = 2,
    KNIGHT     = 3,
    BISHOP     = 4,
    QUEEN      = 5,
    KING       = 6,
    NUM_PIECES = 7
};

enum Piece_colours {
    WHITE       = 0,
    BLACK       = 1,
    NUM_COLOURS = 2,
    NO_COLOUR   = 3
};

typedef struct Piece {
    uint8_t colour;
    uint8_t type;
    uint8_t xpos;
    uint8_t ypos;
} piece_t;

/* new_piece
 *
 * Creates a new piece_t instance set with the given colour and type;
 *
 * Args:
 *     colour (uint8_t): The colour of the piece, see the enum Piece_colours
 *                       for valid values
 *     type (uint8_t): The type of the piece, see the enum Piece_type for valid
 *                     values
 *
 * Returns:
 *     *piece_t: A pointer to a new piece_t, returns NULL instead if something
 *               went wrong.
 */
piece_t *piece_new(uint8_t colour, uint8_t type, uint8_t xpos, uint8_t ypos);

#endif
