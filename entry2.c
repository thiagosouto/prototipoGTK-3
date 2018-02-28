#include <gtk/gtk.h>

static void output_state (GtkToggleButton *source, gpointer user_data) {
  printf ("Active: %d\n", gtk_toggle_button_get_active (source));
}
void destroy (void)
{
  gtk_main_quit ();
}


int main (int argc, char **argv)
{
  GtkWidget *window, *radio1, *radio2, *box, *entry;

  gtk_init (&argc, &argv);


  window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  g_signal_connect (window, "destroy",G_CALLBACK (destroy), NULL);
  gtk_container_set_border_width (GTK_CONTAINER (window), 150);
  box = gtk_box_new (GTK_ORIENTATION_VERTICAL,3);
  // Create a radio button with a GtkEntry widget
  radio1 = gtk_radio_button_new (NULL);
  entry = gtk_entry_new ();
  gtk_container_add (GTK_CONTAINER (radio1), entry);


  // Create a radio button with a label
  radio2 = gtk_radio_button_new_with_label_from_widget (GTK_RADIO_BUTTON (radio1),
                                                        "I’m the second radio button.");

  // Pack them into a box, then show all the widgets
  gtk_container_add (GTK_CONTAINER (box), radio1);
  gtk_container_add  ( GTK_CONTAINER(box), radio2);
  gtk_container_add (GTK_CONTAINER (window), box);
  gtk_widget_show_all (window);


  gtk_main ();

  return 0;
}
