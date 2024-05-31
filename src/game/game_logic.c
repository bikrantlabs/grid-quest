#include "shared/typedefs.h"
#include "utils/grid_utils.h"
#include <string.h>

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
  fill_grid_with_characters(table);
}