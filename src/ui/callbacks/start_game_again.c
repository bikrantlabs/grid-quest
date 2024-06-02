#include "callbacks.h"
#include "typedefs.h"
void start_game_again(GtkWidget *widget, gpointer data) {
  AppConfig *params = (AppConfig *)data;

  // free_game_config(params);
  // free_button_grids(params);
  // free_label_grids(params);

  // TODO: Navigate to home page
  gtk_stack_set_visible_child_name(GTK_STACK(params->uiconfig->stack),
                                   "home_page");
}