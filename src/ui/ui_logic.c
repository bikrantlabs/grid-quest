#include "headers/ui_logic.h"
#include "headers/typedefs.h"
#include "screens.h"

void setup_ui(GtkApplication *app, gpointer user_data) {
  UiConfig *uiconfig = malloc(sizeof(UiConfig));
  AppConfig *app_config = malloc(sizeof(AppConfig));
  app_config->uiconfig = uiconfig;

  GtkWidget *window = gtk_application_window_new(app);
  gtk_window_set_title(GTK_WINDOW(window), "Word Puzzle Game");
  gtk_window_set_default_size(GTK_WINDOW(window), 400, 400);

  // Create Stack
  initialize_ui(app_config, window);

  gtk_stack_set_visible_child_name(GTK_STACK(uiconfig->stack), "home_page");

  // Apply CSS
  apply_css("../src/styles.css");

  gtk_widget_show(window);
}
