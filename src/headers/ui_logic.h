#ifndef UI_LOGIC_H
#define UI_LOGIC_H

#include <gtk/gtk.h>

void setup_ui(GtkApplication *app, gpointer user_data);
void update_button_label(GtkWidget *button, const char *label);
void apply_css(const char *css_path);
#endif // UI_LOGIC_H
