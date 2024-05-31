/**
 * Source file for word related utilities functions
 */

#include "word_utils.h"
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

char generate_random_character() {
  int random_index = rand() % 26;

  // Add 'A' (ASCII value of 65) to get the character
  char random_char = 'A' + random_index;
  return random_char;
}

SelectedWord choose_random_word(char **word, int total_words) {
  int random_index = rand() % total_words;
  SelectedWord word_data = {.word = word[random_index], strlen(*word)};
  return word_data;
}