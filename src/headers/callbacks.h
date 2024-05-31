/**
 * A header file containing callbacks function for UI components
 */
#ifndef CALLBACKS_H
#define CALLBACKS_H
#include <gtk/gtk.h>
void select_difficulty(GtkButton *button, gpointer user_data);
void on_button_clicked(GtkWidget *widget, gpointer data);
#endif