#include <gtk/gtk.h>
void destroy (void)
{
  gtk_main_quit ();
}


int main (int argc, char *argv[])
{
  GtkWidget *janela;
  GtkWidget *carregar;
  GtkWidget *grade;
  GtkAdjustment *ajuste1;
  GtkWidget *label;



  gtk_init (&argc, &argv);

  ajuste1 = gtk_adjustment_new (0.0, 0.0, 10.0, 1.0, 0.1, 0.0);


  janela = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  g_signal_connect (janela, "destroy",G_CALLBACK (destroy), NULL);
  gtk_container_set_border_width (GTK_CONTAINER (janela), 30);

  grade = gtk_grid_new ();
  gtk_container_add (GTK_CONTAINER (janela), grade);


  label= gtk_label_new("ScrollBar na vertical");
  gtk_grid_attach (GTK_GRID(grade),label, 1,1,1,1);


  carregar = gtk_scrollbar_new ( GTK_ORIENTATION_HORIZONTAL,ajuste1);
  gtk_grid_attach (GTK_GRID(grade),carregar, 1,2,1,1);



  gtk_widget_show_all (janela);

  gtk_main ();

  return 0;
}
