#ifndef WORD_UTILS_H
#define WORD_UTILS_H
#include "typedefs.h"

SelectedWord choose_random_word(char **word, int total_words);
int longest_word_in_array(char **word, int total_words);
// Generate random character from A to Z;
char generate_random_character();

#endif // WORD_UTILS_H
