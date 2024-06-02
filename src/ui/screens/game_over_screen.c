/**
 * Choose Difficulty in Start Screen.
 */

#include "callbacks.h"
#include "screens.h"
#include "typedefs.h"
GtkWidget *game_over_screen(AppConfig *app_config) {
  GtkWidget *exit_game;
  GtkWidget *start_again;

  start_again = gtk_button_new_with_label("Play again");
  g_signal_connect(start_again, "clicked", G_CALLBACK(start_game_again),
                   app_config);
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