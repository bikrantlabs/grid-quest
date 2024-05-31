#ifndef WORD_UTILS_H
#define WORD_UTILS_H
#include "typedefs.h"

SelectedWord choose_random_word(char **word, int total_words);
int longest_word_in_array(char **word, int total_words);
// Generate random character from A to Z;
char generate_random_character(char **words, int total_words);
char *uppercase(char *str);
int is_number_in_array(int arr[], int size, int number);
bool is_subset(int array_one[], int size_one, int array_two[], int size_two);
#endif // WORD_UTILS_H
