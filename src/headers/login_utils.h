#ifndef LOGIN_UTILS_H
#define LOGIN_UTILS_H

#include <gtk/gtk.h>
#include <stdbool.h>

void save_login_data(char *username, char *password);
bool check_user_exists(char *username, char *password);

#endif // GAME_LOGIC_H
