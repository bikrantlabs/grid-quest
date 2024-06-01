#include "callbacks.h"
#include "typedefs.h"
#include <gtk/gtk.h>
#include <stdlib.h>
void remove_clicked_position(int index, ClickedPositions *positions) {
  for (int i = index; i < positions->clicked_count - 1; ++i) {
    positions->positions[i] = positions->positions[i + 1];
  }
  positions->clicked_count--;
}
void add_or_remove_clicked_position(ClickedPositions *position,
                                    GameConfig *config, int new_position) {
  for (int i = 0; i < position->clicked_count; ++i) {
    if (position->positions[i] == new_position) {
      remove_clicked_position(i, position);
      return;
    }
  }
  position->positions[position->clicked_count++] = new_position;
  config->attempts--;
}
void on_button_clicked(GtkWidget *widget, gpointer data) {
  ButtonClickData *button_data =
      (ButtonClickData *)(data); // Retrieve the integer data

  add_or_remove_clicked_position(button_data->clicked_positions,
                                 button_data->config,
                                 button_data->new_position);
  update_attempts(
      button_data->config->attempts,
      button_data->uiconfig->attempts_label); // TODO: Check subset for arrays
                                              // and detect valid selection
  // If attempts is 0, show Game Over screen.
  if (button_data->config->attempts <= 0) {
    // Navigate to Game over screen and reset all data
    gtk_stack_set_visible_child_name(GTK_STACK(button_data->uiconfig->stack),
                                     "game_over_page");
    free(button_data->config);
  }
  if (gtk_widget_has_css_class(widget, "selected")) {
    gtk_widget_remove_css_class(widget, "selected");
  } else {
    gtk_widget_add_css_class(widget, "selected");
  }
}