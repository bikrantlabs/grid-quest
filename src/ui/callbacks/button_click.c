#include "callbacks.h"
#include "typedefs.h"
#include "word_utils.h"
#include <gtk/gtk.h>
void remove_clicked_position(int index, ClickedPositions *positions) {
  for (int i = index; i < positions->clicked_count - 1; ++i) {
    positions->positions[i] = positions->positions[i + 1];
  }
  positions->clicked_count--;
}
void add_or_remove_clicked_position(ClickedPositions *position,
                                    int new_position) {
  for (int i = 0; i < position->clicked_count; ++i) {
    if (position->positions[i] == new_position) {
      remove_clicked_position(i, position);
      return;
    }
  }
  position->positions[position->clicked_count++] = new_position;
}
void on_button_clicked(GtkWidget *widget, gpointer data) {
  ButtonClickData *button_data =
      (ButtonClickData *)(data); // Retrieve the integer data
  add_or_remove_clicked_position(button_data->clicked_positions,
                                 button_data->new_position);

  if (gtk_widget_has_css_class(widget, "selected")) {
    gtk_widget_remove_css_class(widget, "selected");
  } else {
    gtk_widget_add_css_class(widget, "selected");
  }
}