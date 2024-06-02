#include "callbacks.h"
#include "game_logic.h"
#include "get_words.h"
#include "grid_utils.h"
#include "screens.h"
#include "typedefs.h"
#include "word_utils.h"
#include <gtk/gtk.h>
#include <stdlib.h>
#include <string.h>
void select_difficulty(GtkButton *button, gpointer user_data) {
  AppConfig *params = (AppConfig *)user_data;
  const gchar *label = gtk_button_get_label(button);
  // Allocate all memory only after selecting difficulty
  params->game_config = malloc(sizeof(GameConfig));

  params->game_config->words = malloc(5 * sizeof(char *));
  params->game_config->attempts = 0;
  if (strcmp(label, "Easy") == 0) {
    params->game_config->attempts += 4;
    params->game_config->difficulty = EASY;
  } else if (strcmp(label, "Medium") == 0) {
    params->game_config->attempts += 3;
    params->game_config->difficulty = MEDIUM;
  } else if (strcmp(label, "Hard") == 0) {
    params->game_config->attempts += 2;
    params->game_config->difficulty = HARD;
  } else {
    params->game_config->attempts += 4;
    params->game_config->difficulty = MEDIUM;
  }
  RandomSelectedWords *random_word = get_words(params->game_config->difficulty);
  params->game_config->words = random_word->words;
  params->game_config->total_words = random_word->total_words;

  int longest_word = longest_word_in_array(params->game_config->words,
                                           params->game_config->total_words);

  params->game_config->table_length = longest_word + 2;

  params->game_config->game_state =
      malloc(params->game_config->total_words * sizeof(GameState));
  initialize_grid(params);
  initialize_game(params->game_config);
  generate_button_grids(params, params->uiconfig->button_grid);
  generate_words_hints_grid(params);

  gtk_stack_set_visible_child_name(GTK_STACK(params->uiconfig->stack),
                                   "game_page");
}