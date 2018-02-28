#include <gtk/gtk.h>

void destroy2 (gpointer data)
{
  gtk_window_get_destroy_with_parent (GTK_WINDOW(data));
}

void destroy (void)
{
  gtk_main_quit ();
}

void janela (GtkEntryBuffer *buffer)
{

  GtkWidget *janela;
  GtkWidget *label;

  janela = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  g_signal_connect (janela, "destroy",G_CALLBACK (destroy2), janela);
  gtk_container_set_border_width (GTK_CONTAINER (janela), 30);

  label= gtk_label_new(gtk_entry_buffer_get_text (buffer));
  gtk_container_add (GTK_CONTAINER (janela), label);

    gtk_widget_show_all (janela);


}

int main (int argc, char *argv[])
{
  GtkWidget *janela;
  GtkWidget *escrita;
  GtkWidget *grade;
  GtkWidget *label;
  GtkEntryBuffer *buffer;
  GtkWidget *botao;



  gtk_init (&argc, &argv);



  janela = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  g_signal_connect (janela, "destroy",G_CALLBACK (destroy), NULL);
  gtk_container_set_border_width (GTK_CONTAINER (janela), 500);

  grade = gtk_grid_new ();
  gtk_container_add (GTK_CONTAINER (janela), grade);


  label = gtk_label_new("Digite a sua pesquisa");
  gtk_grid_attach (GTK_GRID(grade),label, 1,1,1,1);

  buffer = gtk_entry_buffer_new ("pesquisa",500);

  escrita = gtk_entry_new_with_buffer (buffer);
  gtk_grid_attach (GTK_GRID(grade),escrita, 1,2,1,1);

  botao = gtk_button_new_with_label ("Botao");
  g_signal_connect (botao, "clicked",G_CALLBACK (janela), buffer);
  gtk_grid_attach (GTK_GRID(grade),botao, 1,3,1,1);




  gtk_widget_show_all (janela);

  gtk_main ();

  return 0;
}
