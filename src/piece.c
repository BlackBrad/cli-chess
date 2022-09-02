#include <stdlib.h>

#include "piece.h"

#define MAX_POS 8

#define ROOK_REPRESENTATION   'R'
#define KNIGHT_REPRESENTATION 'N'
#define BISHOP_REPRESENTATION 'B'
#define QUEEN_REPRESENTATION  'Q'
#define KING_REPRESENTATION   'K'
#define PAWN_REPRESENTATION   'P'

#define BLACK_REPRESNETATION  'B'
#define WHITE_REPRESENTATION  'W'

piece_t *piece_new(uint8_t colour, uint8_t type, uint8_t xpos, uint8_t ypos){
    piece_t *new_piece = NULL;

    // Ensure that the colour and type are within valid bounds
    if ((colour > NO_COLOUR || colour < 0) ||
        (type >= NUM_PIECES || type < 0)){
        // We can't create a piece if the colour and/or piece type are invalid
        // so return NULL instead
        return NULL;
    }

    if (xpos > MAX_POS || ypos > MAX_POS){
        return NULL;
    }

    // The colour and type are valid, now we can try to allocate some memory
    // to store the new piece struct into.
    new_piece = calloc(1, sizeof(piece_t));

    // Ensure that memory was actually allocated
    if (!new_piece){
        // If no memory was allocated then just return NULL
        return NULL;
    }

    new_piece->colour = colour;
    new_piece->type = type;

    return new_piece;
}

char *piece_representation(piece_t *piece){
    char *return_val = NULL;

    // Ensure that piece_t is not null
    if (piece == NULL){
        return NULL;
    }

    return_val = calloc(2, sizeof(char));

    switch(piece->colour){
        case WHITE:
            return_val[0] = WHITE_REPRESENTATION;
            break;
        case BLACK:
            return_val[0] = BLACK_REPRESNETATION;
            break;
        default:
            free(return_val);
            return NULL;
    }

    switch(piece->type){
        case ROOK:
            return_val[1] = ROOK_REPRESENTATION;
            break;
        case KNIGHT:
            return_val[1] = KNIGHT_REPRESENTATION;
            break;
        case BISHOP:
            return_val[1] = BISHOP_REPRESENTATION;
            break;
        case QUEEN:
            return_val[1] = QUEEN_REPRESENTATION;
            break;
        case KING:
            return_val[1] = KING_REPRESENTATION;
            break;
        case PAWN:
            return_val[1] = PAWN_REPRESENTATION;
            break;
        default:
            free(return_val);
            return NULL;
    }

    return return_val;
}
