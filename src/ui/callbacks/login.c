#include "callbacks.h"
#include "file_utils.h"
#include "login_utils.h"
#include "time_converter.h"
#include "typedefs.h"
#include <gtk/gtk.h>
/**
 * If username/password matches in credentials.txt, user will be logged in,
 * otherwise a new user will be created.
 */
void login(GtkButton *button, gpointer user_data) {
  AppConfig *app_config = (AppConfig *)user_data;

  const char *username =
      gtk_entry_buffer_get_text((app_config->uiconfig->username_input));
  const char *password =
      gtk_entry_buffer_get_text((app_config->uiconfig->password_input));
  app_config->game_config->username = (char *)malloc(strlen(username) + 1);
  app_config->game_config->password = (char *)malloc(strlen(password) + 1);
  strcpy(app_config->game_config->username, username);
  strcpy(app_config->game_config->password, password);
  if (check_user_exists(app_config->game_config->username,
                        app_config->game_config->password)) {
    app_config->game_config->new_user = false;

  } else {
    save_login_data(app_config->game_config->username,
                    app_config->game_config->password);
    app_config->game_config->new_user = true;
  }
  // TODO: Navigate to home_screen stack
  gtk_stack_set_visible_child_name(GTK_STACK(app_config->uiconfig->stack),
                                   "home_page");
}