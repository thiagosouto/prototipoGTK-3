#include <gtk/gtk.h>
void destroy (void)
{
  gtk_main_quit ();
}


int main (int argc, char *argv[])
{
  GtkWidget *janela;
  GtkWidget *spin;
  GtkWidget *grade;
  GtkAdjustment *ajuste1;
  GtkAdjustment *ajuste2;
  GtkWidget *label;



  gtk_init (&argc, &argv);

  ajuste1 = gtk_adjustment_new (0.0, 0.0, 10.0, 1.0, 0.1, 0.0);
  ajuste2 = gtk_adjustment_new (0.0, 0.0, 1.0, 0.1, 1.0, 0.0);


  janela = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  g_signal_connect (janela, "destroy",G_CALLBACK (destroy), NULL);
  gtk_container_set_border_width (GTK_CONTAINER (janela), 30);

  grade = gtk_grid_new ();
  gtk_container_add (GTK_CONTAINER (janela), grade);


  label= gtk_label_new("Spin com inteiro");
  gtk_grid_attach (GTK_GRID(grade),label, 1,1,1,1);


  spin = gtk_spin_button_new (ajuste1, 1.0, 0);;
  gtk_grid_attach (GTK_GRID(grade),spin, 1,2,1,1);


  label= gtk_label_new("Spin com decimal");
  gtk_grid_attach (GTK_GRID(grade),label, 1,3,1,1);

  spin = gtk_spin_button_new (ajuste2, 2.0, 3);
  gtk_grid_attach (GTK_GRID(grade),spin, 1,4,1,1);



  gtk_widget_show_all (janela);

  gtk_main ();

  return 0;
}
