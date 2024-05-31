#include "game_logic.h"
#include "typedefs.h"
#include "ui_logic.h"
#include "word_utils.h"
#include <gtk/gtk.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  printf("Some debug output\n");

  char *words[] = {"Apple", "Banana", "Orange", "Mango", "Grape"};

  // The length of array is equal to the number of words in array.
  TableData game_data[5];

  int total_words = sizeof(words) / sizeof(words[0]);

  int longest_word_length = longest_word_in_array(words, total_words);

  // tableLength == no.of columns
  int table_length = longest_word_length + 2;
  // Initialize the game grid dynamically
  char **grid = malloc(table_length * sizeof(char *));
  for (int i = 0; i < table_length; ++i) {
    grid[i] = malloc(table_length * sizeof(char));
  }

  Table table = {table_length, total_words, table_length, words, grid};
  srand(time(NULL));
  initialize_game(table_length, words, table, game_data);
  // printf("GAME DATA:\n");
  // for (int i = 0; i < 5; i++) {
  //   printf("Word = %s\t, Position = {%d, %d}\n", game_data[i].word,
  //          game_data[i].position[0], game_data[i].position[1]);
  // }

  GtkApplication *app =
      gtk_application_new("org.gtk.example", G_APPLICATION_FLAGS_NONE);
  g_signal_connect(app, "activate", G_CALLBACK(setup_ui), &table);
  int status = g_application_run(G_APPLICATION(app), argc, argv);
  g_object_unref(app);

  // Free the dynamically allocated memory
  for (int i = 0; i < table_length; ++i) {
    free(grid[i]);
  }
  free(grid);

  // return status;
  return 1;
}
