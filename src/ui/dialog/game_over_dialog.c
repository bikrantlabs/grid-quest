#include "typedefs.h"
#include "ui_logic.h"
#include <gtk/gtk.h>
static void button_clicked(GtkButton *button, gpointer user_data) {
  // Print the label of the clicked button
  g_print("%s clicked\n", gtk_button_get_label(button));
}

void open_dialog(gpointer user_data) {
  AppConfig *params = (AppConfig *)user_data;
  GtkWidget *dialog, *label, *content_area;
  GtkDialogFlags flags;

  // Create the widgets
  flags = GTK_DIALOG_DESTROY_WITH_PARENT;
  dialog = gtk_dialog_new_with_buttons("Message",
                                       GTK_WINDOW(params->uiconfig->window),
                                       flags, "OK", GTK_RESPONSE_NONE, NULL);
  content_area = gtk_dialog_get_content_area(GTK_DIALOG(dialog));
  label = gtk_label_new("HELLO");

  // Ensure that the dialog box is destroyed when the user responds

  g_signal_connect_swapped(dialog, "response", G_CALLBACK(gtk_window_destroy),
                           dialog);

  // Add the label, and show everything we’ve added

  gtk_box_append(GTK_BOX(content_area), label);
  gtk_widget_show(dialog);
  // GtkWidget *dialog;
  // GtkWidget *button1;
  // GtkWidget *button2;
  // GtkWidget *button3;
  // GtkDialogFlags flags = GTK_DIALOG_MODAL | GTK_DIALOG_DESTROY_WITH_PARENT;

  // dialog = gtk_dialog_new_with_buttons(
  //     "Game Over!", GTK_WINDOW(params->uiconfig->window), flags, "Cancel",
  //     GTK_RESPONSE_CANCEL, "OK", GTK_RESPONSE_OK, NULL);
  // g_signal_connect_swapped(dialog, "response",
  // G_CALLBACK(gtk_window_destroy),
  //                          dialog);
  // button1 = gtk_button_new_with_label("Button 1");
  // button2 = gtk_button_new_with_label("Button 2");
  // button3 = gtk_button_new_with_label("Button 3");

  // g_signal_connect(button1, "clicked", G_CALLBACK(button_clicked), NULL);
  // g_signal_connect(button2, "clicked", G_CALLBACK(button_clicked), NULL);
  // g_signal_connect(button3, "clicked", G_CALLBACK(button_clicked), NULL);
}
