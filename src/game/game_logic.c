#include "game_logic.h"
#include "grid_utils.h"
#include "typedefs.h"
#include <string.h>
void initialize_game(GameConfig config) {
  Direction direction = HORIZONTAL;
  for (int i = 0; i < config.total_words; i++) {
    char *word = config.words[i];
    bool is_position_valid = false;
    SelectedWord selected_word;
    selected_word.word = config.words[i];
    selected_word.word_length = strlen(config.words[i]);
    GameState game_state;
    int *coords;
    if (direction == VERTICAL) {
      direction = HORIZONTAL;
    } else {
      direction = VERTICAL;
    }
    while (!is_position_valid) {

      int position = choose_random_position(config.table_length);

      coords = change_position_to_coordinate(position, config.table_length);

      is_position_valid = validate_position(coords, config.table_length,
                                            selected_word, direction, config);
      if (is_position_valid) {

        game_state.direction = direction;
        game_state.coords = coords;
        game_state.word = selected_word.word;
        place_word_in_table(selected_word, config, game_state);
        config.game_state[i] = game_state;
      }
    }
  }
  fill_grid_with_characters(config);
}