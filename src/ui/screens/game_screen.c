#include "callbacks.h"
#include "typedefs.h"
#include <gtk/gtk.h>
#include <stdlib.h>
#include <string.h>
void generate_button_grids(GameConfig *config, GtkWidget *grid) {
  static GtkWidget ***buttons;

  buttons = malloc(config->table_length * sizeof(GtkWidget **));
  for (int i = 0; i < config->table_length; ++i) {
    buttons[i] = malloc(config->table_length * sizeof(GtkWidget *));
  }

  // Create buttons and add to grid
  for (int i = 0; i < config->table_length; ++i) {
    for (int j = 0; j < config->table_length; ++j) {
      char label[2];
      label[0] = config->table[i][j];
      label[1] = '\0';
      buttons[i][j] = gtk_button_new_with_label(label);
      gtk_widget_add_css_class(buttons[i][j], "characters");
      g_signal_connect(buttons[i][j], "clicked", G_CALLBACK(on_button_clicked),
                       NULL);
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
    int length = strlen(config->words[i]);

    // char bullet[length + 2] = "• ";
    char *bullet = malloc((length + 2) * sizeof(char));
    bullet[0] = '-';
    bullet[1] = ' ';

    strcat(bullet, config->words[i]);
    labels[i] = gtk_label_new(bullet);
    gtk_widget_add_css_class(labels[i], "word_hint");
    gtk_grid_attach(GTK_GRID(grid), labels[i], 0, i + 1, 1, 1);
  }
}
