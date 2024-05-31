/**
 * Source file for grid related utilities functions
 */
#include "grid_utils.h"
#include "headers/word_utils.h"
#include "stdlib.h"
#include <ctype.h>
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

Direction choose_random_direction() {

  int random_index = rand() % 1;
  return random_index == 1 ? VERTICAL : HORIZONTAL;
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
