#include "callbacks.h"
#include "grid_utils.h"
#include "typedefs.h"
#include "word_utils.h"
#include <gtk/gtk.h>
#include <stdlib.h>
#include <string.h>
void generate_button_grids(GameConfig *config, GtkWidget *grid) {
  static GtkWidget ***buttons;

  buttons = malloc(config->table_length * sizeof(GtkWidget **));
  for (int i = 0; i < config->table_length; ++i) {
    buttons[i] = malloc(config->table_length * sizeof(GtkWidget *));
  }
  int total_cells = config->table_length * config->table_length;
  ClickedPositions *clicked_positions = malloc(sizeof(ClickedPositions));
  clicked_positions->positions = malloc(total_cells * sizeof(int));
  clicked_positions->clicked_count = 0;
  clicked_positions->max_size = total_cells;
  // Create buttons and add to grid
  for (int i = 0; i < config->table_length; ++i) {
    for (int j = 0; j < config->table_length; ++j) {
      char label[2];
      label[0] = config->table[i][j];
      label[1] = '\0';
      buttons[i][j] = gtk_button_new_with_label(label);
      int coords[2];
      coords[0] = i;
      coords[1] = j;
      int position =
          change_coordinate_to_position(coords, config->table_length);
      ButtonClickData *button_data = malloc(sizeof(ButtonClickData));
      button_data->new_position = position;
      button_data->button = buttons[i][j];
      button_data->config = config;
      button_data->clicked_positions = clicked_positions;
      gtk_widget_add_css_class(buttons[i][j], "characters");
      g_signal_connect(buttons[i][j], "clicked", G_CALLBACK(on_button_clicked),
                       button_data);
      gtk_grid_attach(GTK_GRID(grid), buttons[i][j], j, i, 1, 1);
    }
  }
}
void generate_words_hints_grid(GameConfig *config, GtkWidget *grid) {
  GtkWidget **labels = malloc(config->total_words * sizeof(GtkWidget *));
  if (labels == NULL) {
    // Handle memory allocation failure
    perror("Failed to allocate memory for labels");
    exit(EXIT_FAILURE);
  }
  GtkWidget *label = gtk_label_new("WORDS:");
  gtk_widget_add_css_class(label, "word_hint_label");

  gtk_grid_attach(GTK_GRID(grid), label, 0, 0, 1, 1);
  // Create labels and add to grid
  for (int i = 0; i < config->total_words; ++i) {

    labels[i] = gtk_label_new(uppercase(config->words[i]));
    gtk_widget_add_css_class(labels[i], "word_hint");
    gtk_grid_attach(GTK_GRID(grid), labels[i], 0, i + 1, 1, 1);
  }
}
