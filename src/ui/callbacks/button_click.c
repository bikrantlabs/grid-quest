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

  printf("PRINTING COORDS:::::::\n");
  // printf("Word length: %d", button_data->config.game_state[0].word_length);
  // int *a = button_data->config.game_state[0].coords;
  // for (int i = 0; i < button_data->config.game_state[0].word_length; i++) {
  //   printf("COORDS: %d\n", a[i]);
  // }
  // for (int i = 0; i < button_data->config->total_words; i++) {
  //   if (is_subset(button_data->config->game_state[i].coords,
  //                 button_data->config->game_state[i].word_length,
  //                 button_data->clicked_positions->positions,
  //                 button_data->clicked_positions->clicked_count)) {
  //     printf("SUBSET TRUE:\n");
  //   } else {
  //     printf("Subset false:\n");
  //   }
  // }

  if (gtk_widget_has_css_class(widget, "selected")) {
    gtk_widget_remove_css_class(widget, "selected");
  } else {
    gtk_widget_add_css_class(widget, "selected");
  }
}