#include <stdlib.h>

#include "piece.h"

piece_t *piece_new(uint8_t colour, uint8_t type){
    piece_t *new_piece = NULL;

    // Ensure that the colour and type are within valid bounds
    if ((colour > NO_COLOUR || colour < 0) ||
        (type >= NUM_PIECES || type < 0)){
        // We can't create a piece if the colour and/or piece type are invalid
        // so return NULL instead
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
