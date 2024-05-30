#include "../game/game_logic.h"
#include "shared/typedefs.h"
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

SelectedWord choose_random_word(char **word, int total_words) {

  int random_index = rand() % total_words;

  SelectedWord word_data = {.word = word[random_index], strlen(*word)};
  return word_data;
}

Direction choose_random_direction() {

  int random_index = rand() % 1;
  return random_index == 1 ? VERTICAL : HORIZONTAL;
}

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
bool validate_position(int *coords, int grid_length, SelectedWord word,
                       Direction direction, Table table) {

  if (direction == VERTICAL) {

    bool available_spaces =
        word.word_length <= grid_length - coords[0] ? true : false;

    if (available_spaces) {
      // Check there are no other letters already filled there
      int pos = 0;
      for (int i = coords[0]; i < word.word_length + coords[0]; i++) {
        if (table.table[i][coords[1]] != '\0') {
          return false;
        }
        pos++;
      }
      return true;
    } else {
      return false;
    }
  } else {
    bool available_spaces =
        word.word_length <= grid_length - coords[1] ? true : false;
    if (available_spaces) {
      int pos = 0;

      for (int i = coords[1]; i < word.word_length + coords[1]; i++) {
        if (table.table[coords[0]][i] != '\0') {
          return false;
        }
        pos++;
      }

      return true;
    } else {

      return false;
    }
  }
  return false;
}
bool is_cell_filled(Table table, int *coords) {
  if (table.table[coords[0]][coords[1]])
    return false;
  return true;
}

int choose_random_position(int grid_length) {
  int totalSquares = grid_length * grid_length;
  int position = rand() % totalSquares;
  return position;
}

void place_word_in_table(SelectedWord word, const Table table,
                         TableData table_data) {
  int *coords = table_data.position;
  for (int i = 0; i <= word.word_length; i++) {
    if (table_data.word[i] == '\0') {
      continue;
    }
    if (table_data.direction == HORIZONTAL) {
      table.table[coords[0]][coords[1] + i] = toupper(table_data.word[i]);
    } else {
      table.table[coords[0] + i][coords[1]] = toupper(table_data.word[i]);
    }
  }
}
char generate_random_character() {
  int random_index = rand() % 26;

  // Add 'A' (ASCII value of 65) to get the character
  char random_char = 'A' + random_index;
  return random_char;
}
void fill_grid_with_characters(Table table) {
  for (int i = 0; i < table.table_length; i++) {
    for (int j = 0; j < table.table_length; j++) {
      if (table.table[i][j] == '\0') {
        table.table[i][j] = generate_random_character();
      } else {
      }
    }
  }
}
int *change_position_to_coordinate(int number, int cols) {

  int *coords = malloc(sizeof(int) * 2);

  if (number == 0) {
    coords[0] = 0;
    coords[1] = 1;
    return coords;
  }
  if (number % cols == 0 && number != 0) {
    // The inputted number is on last column.
    coords[1] = cols - 1;
    coords[0] = number / cols - 1;
  } else {
    coords[0] = number / cols;
    coords[1] = number % cols - 1;
  }

  return coords;
}
int change_coordinate_to_position(int *coords, int cols) {
  return cols * coords[0] + coords[1] + 1;
}

void initialize_game(int grid_length, char **words, Table table,
                     TableData *game_data) {
  Direction direction = HORIZONTAL;
  for (int i = 0; i < table.total_words; i++) {
    char *word = words[0];
    bool is_position_valid = false;
    SelectedWord selected_word;
    selected_word.word = words[i];
    selected_word.word_length = strlen(words[i]);
    TableData table_data;
    int *coords;
    if (direction == VERTICAL) {
      direction = HORIZONTAL;
    } else {
      direction = VERTICAL;
    }
    while (!is_position_valid) {

      int position = choose_random_position(grid_length);

      coords = change_position_to_coordinate(position, table.table_length);

      is_position_valid = validate_position(coords, table.table_length,
                                            selected_word, direction, table);
      if (is_position_valid) {

        table_data.direction = direction;
        table_data.position = coords;
        table_data.word = selected_word.word;
        place_word_in_table(selected_word, table, table_data);
        game_data[i] = table_data;
      }
    }
  }
  // fill_grid_with_characters(table);
}