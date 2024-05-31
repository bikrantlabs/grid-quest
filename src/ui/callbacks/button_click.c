#include "callbacks.h"
#include <gtk/gtk.h>
void on_button_clicked(GtkWidget *widget, gpointer data) {
  if (gtk_widget_has_css_class(widget, "selected")) {
    gtk_widget_remove_css_class(widget, "selected");
  } else {
    gtk_widget_add_css_class(widget, "selected");
  }
}