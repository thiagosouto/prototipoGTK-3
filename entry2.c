#include <gtk/gtk.h>

void destroy (void)
{
  gtk_main_quit ();
}


static void initialize_window(GtkWidget* window) {

  gtk_window_set_title(GTK_WINDOW(window),"My Window");
  gtk_window_set_default_size (GTK_WINDOW (window), 200, 100);
  g_signal_connect (window, "destroy", G_CALLBACK (destroy), NULL);

}

int main (int argc, char *argv[]){

  GtkWidget *janela;
  GtkWidget *grade;
  GtkWidget *label;
  GtkWidget *entry;
  GtkWidget *entry1;
  GtkWidget *label1;
  GtkWidget *label3;
  GtkWidget *label2;
  GtkWidget *entry2;


  gtk_init(&argc, &argv);



  janela = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  g_signal_connect (janela, "destroy",G_CALLBACK (destroy), NULL);
  gtk_container_set_border_width (GTK_CONTAINER (janela), 500);

  initialize_window(janela);

  grade = gtk_grid_new ();
  gtk_container_add (GTK_CONTAINER (janela), grade);



  label = gtk_label_new ("Circle with standard formula:(x-a)^2 + (y-b)^2 =r*r");
  gtk_grid_attach (GTK_GRID(grade),label, 1,1,1,1);

  entry = gtk_entry_new ();
  gtk_grid_attach (GTK_GRID (grade), entry, 1, 2, 1, 2);

  label1 = gtk_label_new ("Input value of a:");
  gtk_grid_attach (GTK_GRID (grade), entry, 0, 1, 1, 2);

  entry1 = gtk_entry_new();
  gtk_grid_attach (GTK_GRID (grade), entry1, 1, 2, 2, 3);

  label2=gtk_label_new("Input the value of b:");
  gtk_grid_attach (GTK_GRID (grade), label2, 0, 1, 2, 3);

  label3=gtk_label_new("Input the value of r:");
  gtk_grid_attach (GTK_GRID (grade), label3, 0, 1, 3, 4);

  entry2 = gtk_entry_new();
  gtk_grid_attach (GTK_GRID (grade), entry2, 1, 2, 3, 4);


  gtk_widget_show_all(janela);

  gtk_main ();
  return 0;
}
