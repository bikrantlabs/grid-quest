/**
 * Choose Difficulty in Start Screen.
 */

#include "callbacks.h"
#include "glibconfig.h"
#include "screens.h"
#include "typedefs.h"
GtkWidget *game_complete_screen(AppConfig *app_config) {
  GtkWidget *exit_game;
  GtkWidget *start_again;

  start_again = gtk_button_new_with_label("Play again");

  GtkWidget *grid = gtk_grid_new();
  GtkWidget *you_win = gtk_label_new("You Won!");
  // GtkWidget *your_score = gtk_label_new("Information: ");
  // printf("\nTOTAL WORDS\n: %d", app_config->game_config->total_words);
  // GtkWidget *total_words =
  //     gtk_label_new(GINT_TO_POINTER(app_config->game_config->total_words));
  // GtkWidget *attempts_left =
  //     gtk_label_new(GINT_TO_POINTER(app_config->game_config->attempts));

  gtk_widget_add_css_class(you_win, "select-difficulty-label");
  gtk_grid_set_row_homogeneous(GTK_GRID(grid), TRUE);
  gtk_grid_set_column_homogeneous(GTK_GRID(grid), TRUE);

  gtk_grid_attach(GTK_GRID(grid), you_win, 0, 0, 1, 1);
  // gtk_grid_attach(GTK_GRID(grid), your_score, 0, 1, 1, 1);
  // gtk_grid_attach(GTK_GRID(grid), total_words, 0, 2, 1, 1);
  // gtk_grid_attach(GTK_GRID(grid), attempts_left, 0, 3, 1, 1);
  gtk_grid_attach(GTK_GRID(grid), start_again, 0, 1, 1, 1);

  gtk_widget_set_halign(grid, GTK_ALIGN_CENTER);
  gtk_widget_set_valign(grid, GTK_ALIGN_CENTER);

  gtk_widget_add_css_class(grid, "select-level-grid");
  gtk_widget_add_css_class(start_again, "select-level-btn");

  g_signal_connect(start_again, "clicked", G_CALLBACK(start_game_again),
                   app_config);

  return grid;
}