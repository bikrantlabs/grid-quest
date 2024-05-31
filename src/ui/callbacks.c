#include "callbacks.h"
#include "typedefs.h"
#include <gtk/gtk.h>
#include <string.h>

void select_level(GtkButton *button, gpointer user_data) {
  Table *table = (Table *)user_data;
  const gchar *label = gtk_button_get_label(button);
  if (strcmp(label, "Easy") == 0)
    table->difficulty = EASY;

  else if (strcmp(label, "Medium") == 0)
    table->difficulty = MEDIUM;
  else if (strcmp(label, "Hard") == 0)
    table->difficulty = HARD;
  else {
    table->difficulty = MEDIUM;
  }
}