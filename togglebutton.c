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
  GtkWidget *toggle;
  GtkWidget *grade;
  GtkWidget *caixa;
  GtkWidget *label;
  GtkWidget *botao;


  gtk_init (&argc, &argv);



  janela = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  g_signal_connect (janela, "destroy",G_CALLBACK (destroy), NULL);
  gtk_container_set_border_width (GTK_CONTAINER (janela), 150);

  grade = gtk_grid_new ();
  gtk_container_add (GTK_CONTAINER (janela), grade);

  label= gtk_label_new("Botao de check");
  gtk_grid_attach (GTK_GRID(grade),label, 1,1,1,1);

  botao = gtk_button_new_with_label ("Fechar");
  g_signal_connect (botao, "clicked",G_CALLBACK (destroy), NULL);
  gtk_grid_attach (GTK_GRID(grade),botao, 1,6,1,1);

  caixa = gtk_box_new (GTK_ORIENTATION_VERTICAL,2);
  gtk_grid_attach (GTK_GRID(grade),caixa, 1,2,3,3);

  toggle = gtk_toggle_button_new_with_label ("Mostrar o titulo");
  gtk_toggle_button_set_mode (GTK_TOGGLE_BUTTON (toggle),FALSE);
  g_signal_connect (toggle, "toggled",G_CALLBACK (selecao),botao);
  gtk_grid_attach (GTK_GRID(grade),toggle, 1,2,1,1);

  toggle = gtk_toggle_button_new_with_label ("Mostrar o botao 1");



  gtk_widget_show_all (janela);

  gtk_main ();

  return 0;
}
