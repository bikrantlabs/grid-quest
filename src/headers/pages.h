/**
 * A header file handling functions for different screens/pages
 */
#ifndef PAGES_H
#define PAGES_H

#include "typedefs.h"
#include <gtk/gtk.h>

GtkWidget *create_page(GtkWidget *stack, CreatePageParams page_params);
GtkWidget *home_screen(AppConfig *app_config);
GtkWidget *game_over_screen(AppConfig *app_config);
void generate_button_grids(AppConfig *app_config, GtkWidget *grid);
void generate_words_hints_grid(AppConfig *app_config);
void initialize_ui(AppConfig *app_config, GtkWidget *window);
#endif