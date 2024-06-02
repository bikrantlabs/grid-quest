/**
 * Choose Difficulty in Start Screen.
 */
#include "callbacks.h"
#include "screens.h"
#include "typedefs.h"
GtkWidget *home_screen(AppConfig *app_config) {
  GtkWidget *easy_button;
  GtkWidget *medium_button;
  GtkWidget *hard_button;

  easy_button = gtk_button_new_with_label("Easy");
  g_signal_connect(easy_button, "clicked", G_CALLBACK(select_difficulty),
                   app_config);
  medium_button = gtk_button_new_with_label("Medium");
  g_signal_connect(medium_button, "clicked", G_CALLBACK(select_difficulty),
                   app_config);
  hard_button = gtk_button_new_with_label("Hard");
  g_signal_connect(hard_button, "clicked", G_CALLBACK(select_difficulty),
                   app_config);

  GtkWidget *grid = gtk_grid_new();
  GtkWidget *label = gtk_label_new("Select difficulty");
  gtk_widget_add_css_class(label, "select-difficulty-label");
  gtk_grid_set_row_homogeneous(GTK_GRID(grid), TRUE);
  gtk_grid_set_column_homogeneous(GTK_GRID(grid), TRUE);

  gtk_grid_attach(GTK_GRID(grid), label, 0, 0, 1, 1);
  gtk_grid_attach(GTK_GRID(grid), easy_button, 0, 1, 1, 1);
  gtk_grid_attach(GTK_GRID(grid), medium_button, 0, 2, 1, 1);
  gtk_grid_attach(GTK_GRID(grid), hard_button, 0, 3, 1, 1);

  gtk_widget_set_halign(grid, GTK_ALIGN_CENTER);
  gtk_widget_set_valign(grid, GTK_ALIGN_CENTER);

  gtk_widget_add_css_class(grid, "select-level-grid");
  gtk_widget_add_css_class(easy_button, "select-level-btn");
  gtk_widget_add_css_class(medium_button, "select-level-btn");
  gtk_widget_add_css_class(hard_button, "select-level-btn");
  return grid;
}