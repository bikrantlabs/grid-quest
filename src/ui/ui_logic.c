#include "headers/ui_logic.h"
#include "headers/typedefs.h"
#include "pages.h"
#include "start_screen.h"

static GtkWidget ***buttons;
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
  Table *table = (Table *)user_data;
  GtkWidget *window = gtk_application_window_new(app);
  gtk_window_set_title(GTK_WINDOW(window), "Word Puzzle Game");
  gtk_window_set_default_size(GTK_WINDOW(window), 400, 400);

  // Create Stack
  GtkWidget *stack = gtk_stack_new();
  gtk_stack_set_transition_type(GTK_STACK(stack),
                                GTK_STACK_TRANSITION_TYPE_SLIDE_LEFT_RIGHT);
  gtk_window_set_child(GTK_WINDOW(window), stack);

  // Home Page
  CreatePageParams home_page_params = {"home_page", "Home Page"};
  GtkWidget *home_page = create_page(stack, home_page_params);

  // Start Game Button
  GtkWidget *start_game_button = gtk_button_new_with_label("Start Game");
  GtkWidget *start_screen_grid = start_screen(table);
  gtk_box_append(GTK_BOX(home_page), start_screen_grid);

  // Add home page to stack

  // Create the game page
  CreatePageParams game_page_garams = {"game_page", "Game Page"};
  GtkWidget *game_page = create_page(stack, game_page_garams);

  GtkWidget *label = gtk_label_new("Game Screen");
  // Add the game page to the stack

  // Connect the "Start Game" button to the callback function
  g_signal_connect(start_game_button, "clicked",
                   G_CALLBACK(on_start_game_button_clicked), stack);
  gtk_stack_set_visible_child_name(GTK_STACK(stack), "home_page");

  GtkWidget *grid = gtk_grid_new();
  gtk_grid_set_row_homogeneous(GTK_GRID(grid), TRUE);
  gtk_grid_set_column_homogeneous(GTK_GRID(grid), TRUE);
  gtk_box_append(GTK_BOX(game_page), grid);
  gtk_widget_set_halign(game_page, GTK_ALIGN_CENTER);
  gtk_widget_set_valign(game_page, GTK_ALIGN_CENTER);

  // Apply CSS
  apply_css("../src/styles.css");
  // Allocate memory for buttons
  buttons = malloc(table->table_length * sizeof(GtkWidget **));
  for (int i = 0; i < table->table_length; ++i) {
    buttons[i] = malloc(table->table_length * sizeof(GtkWidget *));
  }

  // Create buttons and add to grid
  for (int i = 0; i < table->table_length; ++i) {
    for (int j = 0; j < table->table_length; ++j) {
      char label[2];
      label[0] = table->table[i][j];
      label[1] = '\0';
      buttons[i][j] = gtk_button_new_with_label(label);
      gtk_widget_add_css_class(buttons[i][j], "characters");
      g_signal_connect(buttons[i][j], "clicked", G_CALLBACK(on_button_clicked),
                       NULL);
      gtk_grid_attach(GTK_GRID(grid), buttons[i][j], j, i, 1, 1);
    }
  }
  gtk_widget_show(window);
}

void update_button_label(GtkWidget *button, const char *label) {
  gtk_button_set_label(GTK_BUTTON(button), label);
}
