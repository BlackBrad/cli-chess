#include <stdarg.h>
#include <stdint.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include <string.h>

//For utilities
#include <stdlib.h>


// Include the .c file so that we can test static functions
#include "../src/piece.c"


static void test_piece_representation_pawn(void **state){
    piece_t new_piece;
    new_piece.colour = BLACK;
    new_piece.type = PAWN;
    char *expected = "BP";

    char *pawn = piece_representation(&new_piece);
    assert_string_equal(pawn, expected);

    free(pawn);

    new_piece.colour = WHITE;
    expected = "WP";

    pawn = piece_representation(&new_piece);
    assert_string_equal(pawn, expected);
}

static void test_piece_representation_knight(void **state){
    piece_t new_piece;
    new_piece.colour = BLACK;
    new_piece.type = KNIGHT;
    char *expected_black = "BN";
    char *expected_white = "WN";

    char *pawn = piece_representation(&new_piece);
    assert_string_equal(pawn, expected);

    new_piece.colour = WHITE;

    pawn = piece_representation(&new_piece);
    assert_string_equal(pawn, expected);
}

int main(void){
    const struct CMUnitTest tests[] = {
      cmocka_unit_test(test_piece_representation_pawn),
      cmocka_unit_test(test_piece_representation_knight),
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}
