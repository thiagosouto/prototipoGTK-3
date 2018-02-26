#include <gtk/gtk.h>

void hello (void)
{
  g_print ("Hello World\n");
}

void destroy (void)
{
  gtk_main_quit ();
}

int main (int argc, char *argv[])
{
  GtkWidget *janela;
  GtkWidget *botao;

  gtk_init (&argc, &argv);

  janela = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  g_signal_connect (janela, "destroy",G_CALLBACK (destroy), NULL);
  gtk_container_set_border_width (GTK_CONTAINER (janela), 30);

  botao = gtk_button_new_with_label ("Hello World");

  g_signal_connect (botao, "clicked",G_CALLBACK (hello), NULL);
  g_signal_connect_object (botao, "clicked",G_CALLBACK (gtk_widget_destroy),NULL,G_CONNECT_AFTER);
  gtk_container_add (GTK_CONTAINER (janela), botao);


  gtk_widget_show_all (janela);

  gtk_main ();

  return 0;
}
