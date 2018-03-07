#include <gtk/gtk.h>

void destroy (void)
{
  gtk_main_quit ();
}


void selecao (GtkToggleButton *toggle_button, gpointer user_data)
{


  if (gtk_toggle_button_get_active (toggle_button))
      gtk_window_set_title (GTK_WINDOW(user_data), "CheckButton");
  else
      gtk_window_set_title (GTK_WINDOW(user_data), "");
}



void criar_botao (GtkToggleButton *toggle_button, gpointer user_data)
{

  if (gtk_toggle_button_get_active (toggle_button))
      gtk_window_set_title (GTK_WINDOW(user_data), "CheckButton2");
  else
      gtk_window_set_title (GTK_WINDOW(user_data), "");

}

int main (int argc, char *argv[])
{
  GtkWidget *janela;
  GtkWidget *switc;
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


  caixa = gtk_box_new (GTK_ORIENTATION_VERTICAL,2);
  gtk_grid_attach (GTK_GRID(grade),caixa, 1,2,3,3);

  switc = gtk_switch_new ();
  gtk_switch_set_active (GTK_SWITCH(switc),TRUE);
  g_signal_connect (GTK_TOGGLE_BUTTON (switc), "clicked", G_CALLBACK (selecao), janela);
  gtk_container_add (GTK_CONTAINER (caixa), switc);

  switc = gtk_switch_new ();
  gtk_switch_set_active (GTK_SWITCH(switc),FALSE);
  g_signal_connect (GTK_TOGGLE_BUTTON (switc), "clicked", G_CALLBACK (selecao), janela);
  gtk_container_add (GTK_CONTAINER (caixa), switc);




  gtk_widget_show_all (janela);

  gtk_main ();

  return 0;
}
