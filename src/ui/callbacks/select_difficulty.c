#include "callbacks.h"
#include "game_logic.h"
#include "get_words.h"
#include "grid_utils.h"
#include "pages.h"
#include "typedefs.h"
#include "word_utils.h"
#include <gtk/gtk.h>
#include <string.h>
void select_difficulty(GtkButton *button, gpointer user_data) {
  SelectDifficultyParams *params = (SelectDifficultyParams *)user_data;
  const gchar *label = gtk_button_get_label(button);
  // Allocate all memory only after selecting difficulty

  GameConfig *config = params->config;
  config->words = malloc(5 * sizeof(char *));
  config->attempts = 0;
  if (strcmp(label, "Easy") == 0) {
    config->attempts += 6;
    config->difficulty = EASY;
  } else if (strcmp(label, "Medium") == 0) {
    config->attempts += 4;
    config->difficulty = MEDIUM;
  } else if (strcmp(label, "Hard") == 0) {
    config->attempts += 2;
    config->difficulty = HARD;
  } else {
    config->attempts += 4;
    config->difficulty = MEDIUM;
  }
  RandomSelectedWords *random_word = get_words(config->difficulty);
  config->words = random_word->words;
  config->total_words = random_word->total_words;

  int longest_word = longest_word_in_array(config->words, config->total_words);

  config->table_length = longest_word + 2;

  // Generate a table
  initialize_grid(config);
  // Allocate memory for gamestate
  config->game_state = malloc(config->total_words * sizeof(GameState));
  initialize_game(config);
  generate_button_grids(config, params->uiconfig, params->button_grid);
  generate_words_hints_grid(config, params->uiconfig, params->word_hints_grid);
  // Initialize Game Here

  // TODO: Fire function to read words from respective files.
  gtk_stack_set_visible_child_name(GTK_STACK(params->stack), "game_page");
}