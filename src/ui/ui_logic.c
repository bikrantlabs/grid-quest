#include "../ui/ui_logic.h"
#include "../shared/typedefs.h"

static GtkWidget ***buttons;
void on_start_game_button_clicked(GtkButton *button, gpointer user_data) {
  GtkStack *stack = GTK_STACK(user_data);
  gtk_stack_set_visible_child_name(stack, "game_page");
}
static void on_button_clicked(GtkWidget *widget, gpointer data) {
  gtk_button_set_label(GTK_BUTTON(widget), "0");
  printf("Clicked");
  gtk_widget_add_css_class(widget, "selected");
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
  GtkWidget *home_page = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
  gtk_widget_set_margin_top(home_page, 10);
  gtk_widget_set_margin_bottom(home_page, 10);
  gtk_widget_set_margin_start(home_page, 10);
  gtk_widget_set_margin_end(home_page, 10);

  // Start Game Button
  GtkWidget *start_game_button = gtk_button_new_with_label("Start Game");

  gtk_box_append(GTK_BOX(home_page), start_game_button);

  // Add home page to stack
  gtk_stack_add_titled(GTK_STACK(stack), home_page, "home_page", "Home Page");

  // Create the game page
  GtkWidget *game_page = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
  gtk_widget_set_margin_top(game_page, 10);
  gtk_widget_set_margin_bottom(game_page, 10);
  gtk_widget_set_margin_start(game_page, 10);
  gtk_widget_set_margin_end(game_page, 10);

  GtkWidget *label = gtk_label_new("Game Screen");
  // Add the game page to the stack
  gtk_stack_add_titled(GTK_STACK(stack), game_page, "game_page", "Game Page");

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
  // Allocate memory for buttons
  buttons = malloc(table->length * sizeof(GtkWidget **));
  for (int i = 0; i < table->length; ++i) {
    buttons[i] = malloc(table->length * sizeof(GtkWidget *));
  }

  // Create buttons and add to grid
  printf("%c", table->table[1][2]);
  for (int i = 0; i < table->length; ++i) {
    for (int j = 0; j < table->length; ++j) {
      char label[2];
      label[0] = table->table[i][j];
      label[1] = '\0';
      buttons[i][j] = gtk_button_new_with_label(label);
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
