#include "headers/ui_logic.h"
#include "headers/typedefs.h"
#include "pages.h"

void on_start_game_button_clicked(GtkButton *button, gpointer user_data) {
  GtkStack *stack = GTK_STACK(user_data);
  gtk_stack_set_visible_child_name(stack, "game_page");
}
static void on_button_clicked(GtkWidget *widget, gpointer data) {
  if (gtk_widget_has_css_class(widget, "selected")) {
    gtk_widget_remove_css_class(widget, "selected");
  } else {
    gtk_widget_add_css_class(widget, "selected");
  }
}

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
  // Allocate memory for buttons

  gtk_widget_show(window);
}
