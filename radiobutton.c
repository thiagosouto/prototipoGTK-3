#include <gtk/gtk.h>

void destroy (void)
{
  gtk_main_quit ();
}

void selecao (GtkToggleButton *source, gpointer user_data) {
  printf ("esta ativado?: %d\n", gtk_toggle_button_get_active (source));
}


int main (int argc, char *argv[])
{
  GtkWidget *janela;
  GtkWidget *radio;
  GtkWidget *radio2;
  GtkWidget *radio3;
  GtkWidget *grade;
  GtkWidget *caixa;
  GtkWidget *label;
  GtkWidget *botao;
  GtkWidget *escrita;

  gtk_init (&argc, &argv);



  janela = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  g_signal_connect (janela, "destroy",G_CALLBACK (destroy), NULL);
  gtk_container_set_border_width (GTK_CONTAINER (janela), 150);

  grade = gtk_grid_new ();
  gtk_container_add (GTK_CONTAINER (janela), grade);

  label= gtk_label_new("Botao de radio");
  gtk_grid_attach (GTK_GRID(grade),label, 1,1,1,1);

  botao = gtk_button_new_with_label ("Fechar");
  g_signal_connect (botao, "clicked",G_CALLBACK (destroy), NULL);
  gtk_grid_attach (GTK_GRID(grade),botao, 1,6,1,1);

  caixa = gtk_box_new (GTK_ORIENTATION_VERTICAL,2);
  gtk_grid_attach (GTK_GRID(grade),caixa, 1,2,3,3);


  radio = gtk_radio_button_new_with_label(NULL,"primeiro");

  radio2 = gtk_radio_button_new_with_label(NULL,"segundo");

  gtk_radio_button_join_group (GTK_RADIO_BUTTON(radio),GTK_RADIO_BUTTON(radio2));

  escrita = gtk_entry_new ();
  gtk_entry_set_max_length (GTK_ENTRY (escrita), 50);
  gtk_entry_set_text (GTK_ENTRY (escrita), "Digite aqui");


  radio3 = gtk_radio_button_new (gtk_radio_button_get_group (GTK_RADIO_BUTTON(radio)));
  gtk_container_add (GTK_CONTAINER (radio3), escrita);


  gtk_container_add (GTK_CONTAINER (caixa), radio);
  gtk_container_add (GTK_CONTAINER (caixa), radio2);
  gtk_container_add (GTK_CONTAINER (caixa), radio3);



  gtk_widget_show_all (janela);

  gtk_main ();

  return 0;
}
