#include <gtk/gtk.h>

void imprimir1 (void)
{
  g_print ("primeiro botao\n");
}

void imprimir2 (void)
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
  GtkWidget *caixa;

  gtk_init (&argc, &argv);

  janela = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  g_signal_connect (janela, "destroy",G_CALLBACK (destroy), NULL);
  gtk_container_set_border_width (GTK_CONTAINER (janela), 30);

  caixa = gtk_box_new (GTK_ORIENTATION_VERTICAL,2);
  gtk_container_add (GTK_CONTAINER (janela), caixa);

  botao = gtk_button_new_with_label ("Botao um");

  g_signal_connect (botao, "clicked",G_CALLBACK (imprimir1), NULL);
  g_signal_connect_object (botao, "clicked",G_CALLBACK (gtk_widget_destroy),NULL,G_CONNECT_AFTER);
  gtk_container_add (GTK_CONTAINER (caixa), botao);


  botao = gtk_button_new_with_label ("Botao dois");

  g_signal_connect (botao, "clicked",G_CALLBACK (imprimir2), NULL);
  g_signal_connect_object (botao, "clicked",G_CALLBACK (gtk_widget_destroy),NULL,G_CONNECT_AFTER);
  gtk_container_add (GTK_CONTAINER (caixa), botao);


  gtk_widget_show_all (janela);

  gtk_main ();

  return 0;
}
