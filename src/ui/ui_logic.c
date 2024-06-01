#include "headers/ui_logic.h"
#include "headers/typedefs.h"
#include "home_screen.h"
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
  AppConfig *app_config = (AppConfig *)user_data;
  GtkWidget *window = gtk_application_window_new(app);
  gtk_window_set_title(GTK_WINDOW(window), "Word Puzzle Game");
  gtk_window_set_default_size(GTK_WINDOW(window), 400, 400);
  SelectDifficultyParams *start_screen_params =
      malloc(sizeof(SelectDifficultyParams));
  // Create Stack
  start_screen_params->stack = gtk_stack_new();
  start_screen_params->config = app_config->game_config;
  start_screen_params->uiconfig = app_config->uiconfig;
  app_config->uiconfig->stack = start_screen_params->stack;
  gtk_stack_set_transition_type(GTK_STACK(start_screen_params->stack),
                                GTK_STACK_TRANSITION_TYPE_SLIDE_LEFT_RIGHT);
  gtk_window_set_child(GTK_WINDOW(window), start_screen_params->stack);

  // Home Page
  CreatePageParams home_page_params = {"home_page", "Home Page"};
  CreatePageParams game_over_page_params = {"game_over_page", "Game Over Page"};
  GtkWidget *home_page =
      create_page(start_screen_params->stack, home_page_params);
  GtkWidget *game_over_page =
      create_page(start_screen_params->stack, game_over_page_params);
  // Create the game page
  CreatePageParams game_page_garams = {"game_page", "Game Page"};
  GtkWidget *game_page =
      create_page(start_screen_params->stack, game_page_garams);
  gtk_widget_set_halign(game_page, GTK_ALIGN_CENTER);
  gtk_widget_set_valign(game_page, GTK_ALIGN_CENTER);

  // Wrapper Grid
  GtkWidget *wrapper_grid = gtk_grid_new();
  gtk_grid_set_row_homogeneous(GTK_GRID(wrapper_grid), TRUE);
  gtk_grid_set_column_homogeneous(GTK_GRID(wrapper_grid), TRUE);
  gtk_box_append(GTK_BOX(game_page), wrapper_grid);
  //
  GtkWidget *button_grid = gtk_grid_new();
  gtk_grid_set_row_homogeneous(GTK_GRID(button_grid), TRUE);
  gtk_grid_set_column_homogeneous(GTK_GRID(button_grid), TRUE);
  gtk_widget_set_halign(game_page, GTK_ALIGN_CENTER);
  gtk_widget_set_valign(game_page, GTK_ALIGN_CENTER);
  start_screen_params->button_grid = button_grid;

  gtk_grid_attach(GTK_GRID(wrapper_grid), button_grid, 0, 0, 8, 1);
  //
  GtkWidget *word_hints_grid = gtk_grid_new();
  gtk_widget_add_css_class(word_hints_grid, "word_hints_grid");
  // gtk_grid_set_row_homogeneous(GTK_GRID(word_hints_grid), TRUE);
  // gtk_grid_set_column_homogeneous(GTK_GRID(word_hints_grid), TRUE);

  start_screen_params->word_hints_grid = word_hints_grid;
  gtk_grid_attach(GTK_GRID(wrapper_grid), word_hints_grid, 9, 0, 2, 1);

  // Start Game Button
  GtkWidget *start_game_button = gtk_button_new_with_label("Start Game");
  GtkWidget *start_screen_grid = home_screen(start_screen_params);
  GtkWidget *game_over_grid = game_over_screen(start_screen_params);
  gtk_box_append(GTK_BOX(home_page), start_screen_grid);
  gtk_box_append(GTK_BOX(game_over_page), game_over_grid);

  // Add home page to start_screen_params->stack

  GtkWidget *label = gtk_label_new("Game Screen");
  // Add the game page to the stack

  // Connect the "Start Game" button to the callback function
  g_signal_connect(start_game_button, "clicked",
                   G_CALLBACK(on_start_game_button_clicked),
                   start_screen_params->stack);
  gtk_stack_set_visible_child_name(GTK_STACK(start_screen_params->stack),
                                   "home_page");

  // Apply CSS
  apply_css("../src/styles.css");
  // Allocate memory for buttons

  gtk_widget_show(window);
}
