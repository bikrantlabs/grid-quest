/**
 * Source file for word related utilities functions
 */

#include "word_utils.h"
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int longest_word_in_array(char **word, int total_words) {
  int max_length = 0;
  for (int i = 0; i < total_words; i++) {
    int current_length = strlen(word[i]);
    if (current_length > max_length) {
      max_length = current_length;
    }
  }
  return max_length;
}

/**
 * Function to generate random characters from words array.
 */
char generate_random_character(char **words, int total_words) {

  // Choose a random string from the array
  int random_index = rand() % total_words;
  char *selected_string = words[random_index];

  // Choose a random character from the selected string
  int string_length = strlen(selected_string);
  int random_char_index = rand() % string_length;

  return toupper(selected_string[random_char_index]);
}

SelectedWord choose_random_word(char **word, int total_words) {
  int random_index = rand() % total_words;
  SelectedWord word_data = {.word = word[random_index], strlen(*word)};
  return word_data;
}