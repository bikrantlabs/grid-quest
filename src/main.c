#include "typedefs.h"
#include "ui_logic.h"
#include <gtk/gtk.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  srand(time(NULL));
  GameConfig *config = malloc(sizeof(GameConfig));
  Difficulty difficulty = MEDIUM;
  config->difficulty = difficulty;

  GtkApplication *app =
      gtk_application_new("org.gtk.example", G_APPLICATION_FLAGS_NONE);
  g_signal_connect(app, "activate", G_CALLBACK(setup_ui), config);
  int status = g_application_run(G_APPLICATION(app), argc, argv);
  g_object_unref(app);

  // // Free the dynamically allocated memory
  // for (int i = 0; i < table_length; ++i) {
  //   free(grid[i]);
  // }
  // free(grid);

  // return status;
  return 1;
}
