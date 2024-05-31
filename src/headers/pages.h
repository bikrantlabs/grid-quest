/**
 * A header file handling functions for different screens/pages
 */
#ifndef PAGES_H
#define PAGES_H

#include "typedefs.h"
#include <gtk/gtk.h>

GtkWidget *create_page(GtkWidget *stack, CreatePageParams page_params);
GtkWidget *home_screen(SelectDifficultyParams *select_difficulty_params);
void generate_button_grids(GameConfig *config, GtkWidget *grid);
void generate_words_hints_grid(GameConfig *config, GtkWidget *grid);
#endif