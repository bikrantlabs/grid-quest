/**
 * A header file handling functions for different screens/pages
 */
#ifndef PAGES_H
#define PAGES_H

#include "typedefs.h"
#include <gtk/gtk.h>

GtkWidget *create_page(GtkWidget *stack, CreatePageParams page_params);
#endif