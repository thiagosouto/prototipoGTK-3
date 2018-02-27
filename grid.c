#include <gtk/gtk.h>

void imprimir1 (void)
{
  g_print ("primeiro botao\n");
}

void imprimir2 (void)
{
  g_print ("segundo botao\n");
}

void imprimir3 (void)
{
  g_print ("segundo botao\n");
}

void destroy (void)
{
  gtk_main_quit ();
}

int main (int argc, char *argv[])
{
  GtkWidget *janela;
  GtkWidget *botao;
  GtkWidget *grade;

  gtk_init (&argc, &argv);

  janela = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  g_signal_connect (janela, "destroy",G_CALLBACK (destroy), NULL);
  gtk_container_set_border_width (GTK_CONTAINER (janela), 30);

  grade = gtk_grid_new ();
  gtk_container_add (GTK_CONTAINER (janela), grade);

  botao = gtk_button_new_with_label ("Botao um");

  g_signal_connect (botao, "clicked",G_CALLBACK (imprimir1), NULL);
  g_signal_connect_object (botao, "clicked",G_CALLBACK (gtk_widget_destroy),NULL,G_CONNECT_AFTER);
  gtk_grid_attach (GTK_GRID(grade),botao, 1,1,1,1);

  botao = gtk_button_new_with_label ("Botao dois");

  g_signal_connect (botao, "clicked",G_CALLBACK (imprimir2), NULL);
  g_signal_connect_object (botao, "clicked",G_CALLBACK (gtk_widget_destroy),NULL,G_CONNECT_AFTER);
  gtk_grid_attach (GTK_GRID(grade),botao, 1,2,1,1);

  botao = gtk_button_new_with_label ("Botao 3");

  g_signal_connect (botao, "clicked",G_CALLBACK (imprimir2), NULL);
  g_signal_connect_object (botao, "clicked",G_CALLBACK (gtk_widget_destroy),NULL,G_CONNECT_AFTER);
  gtk_grid_attach (GTK_GRID(grade),botao, 2,1,1,2);



  gtk_widget_show_all (janela);

  gtk_main ();

  return 0;
}
