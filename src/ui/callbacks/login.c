#include "callbacks.h"
#include "login_utils.h"
#include "typedefs.h"
#include <gtk/gtk.h>
void login(GtkButton *button, gpointer user_data) {
  AppConfig *app_config = (AppConfig *)user_data;
  app_config->game_config = malloc(sizeof(GameConfig));
  const char *username =
      gtk_entry_buffer_get_text((app_config->uiconfig->username_input));
  const char *password =
      gtk_entry_buffer_get_text((app_config->uiconfig->password_input));
  app_config->game_config->username = (char *)malloc(strlen(username) + 1);
  app_config->game_config->password = (char *)malloc(strlen(password) + 1);
  strcpy(app_config->game_config->username, username);
  strcpy(app_config->game_config->password, password);
  g_print("%s\n", username); // I wanna print out what it's been typed in here
  g_print("%s\n", password); // I wanna print out what it's been typed in here
  save_login_data(app_config->game_config->username,
                  app_config->game_config->password);
}