#include <gtk/gtk.h>

void destroy2 (gpointer data)
{
  gtk_window_get_destroy_with_parent (GTK_WINDOW(data));
}

void destroy (void)
{
  gtk_main_quit ();
}

static void printar( GtkWidget *widget, GtkWidget *entry )
{
  entry_text = gtk_entry_get_text (GTK_ENTRY (entry));
  printf ("Esta escrito: %s\n", entry_text);
}

void printar_janela (GtkWidget *widget, GtkWidget *entry )
{

  GtkWidget *janela;
  GtkWidget *label;
  const gchar *texto = gtk_entry_get_text (GTK_ENTRY (entry));

  janela = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  g_signal_connect (janela, "destroy",G_CALLBACK (destroy2), janela);
  gtk_container_set_border_width (GTK_CONTAINER (janela), 50);

  label= gtk_label_new(texto);
  gtk_container_add (GTK_CONTAINER (janela), label);

  gtk_widget_show_all (janela);


}

int main (int argc, char *argv[])
{
  GtkWidget *janela;
  GtkWidget *escrita;
  GtkWidget *grade;
  GtkWidget *label;
  GtkWidget *botao;
  gint tamanho;


  gtk_init (&argc, &argv);



  janela = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  g_signal_connect (janela, "destroy",G_CALLBACK (destroy), NULL);
  gtk_container_set_border_width (GTK_CONTAINER (janela), 50);

  grade = gtk_grid_new ();
  gtk_container_add (GTK_CONTAINER (janela), grade);


  label = gtk_label_new("Digite a sua pesquisa");
  gtk_grid_attach (GTK_GRID(grade),label, 1,1,1,1);


  escrita = gtk_entry_new ();
  gtk_entry_set_max_length (GTK_ENTRY (escrita), 50);
  g_signal_connect (escrita, "activate",G_CALLBACK (printar),escrita);
  gtk_entry_set_text (GTK_ENTRY (escrita), "Digite aqui");
  tamanho = gtk_entry_get_text_length (GTK_ENTRY (escrita));
  gtk_editable_insert_text (GTK_EDITABLE (escrita), " a palavra", -1, &tamanho);
  gtk_editable_select_region (GTK_EDITABLE (escrita),5, gtk_entry_get_text_length (GTK_ENTRY (escrita)));
  gtk_grid_attach (GTK_GRID(grade),escrita, 1,2,1,1);


  botao = gtk_button_new_with_label ("Botao para abrir uma janela com escrita");
  g_signal_connect (botao, "clicked",G_CALLBACK (printar_janela),escrita);



  gtk_grid_attach (GTK_GRID(grade),botao, 1,3,1,1);




  gtk_widget_show_all (janela);

  gtk_main ();

  return 0;
}
