/**
 * A header file containing callbacks function for UI components
 */
#ifndef CALLBACKS_H
#define CALLBACKS_H
#include "typedefs.h"
#include <gtk/gtk.h>
void select_difficulty(GtkButton *button, gpointer user_data);
void on_button_clicked(GtkWidget *widget, gpointer data);
void start_game_again(GtkWidget *widget, gpointer data);
void update_attempts(int attempts, GtkWidget *label);
void free_button_grids(AppConfig *app_config);
void free_label_grids(AppConfig *app_config);
void free_game_config(AppConfig *app_config);
#endif