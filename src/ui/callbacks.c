#include "callbacks.h"
#include "typedefs.h"
#include <gtk/gtk.h>
#include <string.h>

void select_difficulty(GtkButton *button, gpointer user_data) {
  SelectDifficultyParams *params = (SelectDifficultyParams *)user_data;
  const gchar *label = gtk_button_get_label(button);
  if (strcmp(label, "Easy") == 0) {
    params->table->difficulty = EASY;
    printf("Easy Level Clicked");
  } else if (strcmp(label, "Medium") == 0) {
    params->table->difficulty = MEDIUM;
    printf("Medium Level Clicked");
  } else if (strcmp(label, "Hard") == 0) {
    params->table->difficulty = HARD;
    printf("hard Level Clicked");
  } else {
    params->table->difficulty = MEDIUM;
  }
  // TODO: Change Screen and Load Game
  gtk_stack_set_visible_child_name(GTK_STACK(params->stack), "game_page");
}