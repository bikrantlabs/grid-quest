/**
 * Choose Difficulty in Start Screen.
 */

#include "callbacks.h"
#include "pages.h"
#include "typedefs.h"
GtkWidget *game_over_screen(SelectDifficultyParams *select_difficulty_params) {
  GtkWidget *easy_button;
  GtkWidget *medium_button;
  GtkWidget *hard_button;
  GtkWidget *exit_game;
  GtkWidget *start_again;

  start_again = gtk_button_new_with_label("Easy");
  g_signal_connect(start_again, "clicked", G_CALLBACK(start_game_again),
                   select_difficulty_params);

  GtkWidget *grid = gtk_grid_new();
  GtkWidget *label = gtk_label_new("Game Over");
  gtk_widget_add_css_class(label, "select-difficulty-label");
  gtk_grid_set_row_homogeneous(GTK_GRID(grid), TRUE);
  gtk_grid_set_column_homogeneous(GTK_GRID(grid), TRUE);

  gtk_grid_attach(GTK_GRID(grid), label, 0, 0, 1, 1);
  gtk_grid_attach(GTK_GRID(grid), start_again, 0, 1, 1, 1);

  gtk_widget_set_halign(grid, GTK_ALIGN_CENTER);
  gtk_widget_set_valign(grid, GTK_ALIGN_CENTER);

  gtk_widget_add_css_class(grid, "select-level-grid");
  gtk_widget_add_css_class(start_again, "select-level-btn");
  return grid;
}