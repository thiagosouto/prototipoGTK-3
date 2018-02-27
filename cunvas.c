#include <gtk/gtk.h>


void funcao_janela (void);
void destroy2 (gpointer data);
void destroy (void);
gboolean draw_callback (GtkWidget *widget, cairo_t *cr, gpointer data);



int main (int argc, char *argv[])
{
  GtkWidget *janela;
  GtkWidget *botao;

  gtk_init (&argc, &argv);

  janela = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  g_signal_connect (janela, "destroy",G_CALLBACK (destroy), NULL);
  //gtk_container_set_border_width (GTK_CONTAINER (janela), 30);

  botao = gtk_button_new();
  g_signal_connect (botao, "clicked",G_CALLBACK (funcao_janela), NULL);
  g_signal_connect_object (botao, "clicked",G_CALLBACK (gtk_widget_destroy),NULL,G_CONNECT_AFTER);


  GtkWidget *drawing_area = gtk_drawing_area_new ();
  gtk_widget_set_size_request (drawing_area, 100, 100);
  g_signal_connect (G_OBJECT (drawing_area), "draw", G_CALLBACK (draw_callback), NULL);


  gtk_container_add (GTK_CONTAINER (botao), drawing_area);
  gtk_container_add (GTK_CONTAINER (janela), botao);


  gtk_widget_show_all (janela);

  gtk_main ();

  return 0;
}

void funcao_janela (void)
{

  GtkWidget *janela;
  GtkWidget *label;

  janela = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  g_signal_connect (janela, "destroy",G_CALLBACK (destroy2), janela);
  gtk_container_set_border_width (GTK_CONTAINER (janela), 30);

  label= gtk_label_new("Ligou alguma coisa");
  gtk_container_add (GTK_CONTAINER (janela), label);

  gtk_widget_show_all (janela);


}

void destroy2 (gpointer data)
{

  gtk_window_get_destroy_with_parent (GTK_WINDOW(data));

}

void destroy (void)
{

  gtk_main_quit ();

}


gboolean draw_callback (GtkWidget *widget, cairo_t *cr, gpointer data)
{
  guint width, height;
  GdkRGBA color;
  GtkStyleContext *context;

  context = gtk_widget_get_style_context (widget);

  width = gtk_widget_get_allocated_width (widget);
  height = gtk_widget_get_allocated_height (widget);

  gtk_render_background (context, cr, 0, 0, width, height);

  cairo_arc (cr, width / 2.0, height / 2.0, MIN (width, height) / 4.0, 0 , 1 * G_PI);
  gdk_rgba_parse (&color ,"rgba(250,250,250,255)");
  gdk_cairo_set_source_rgba (cr, &color);

  cairo_arc (cr, width / 2.0, height / 2.0, MIN (width, height) / 4.0, 0 , 2 * G_PI);
  gdk_rgba_parse (&color ,"rgba(150,150,150,255)");
  gdk_cairo_set_source_rgba (cr, &color);

  gtk_style_context_get_color (context, gtk_style_context_get_state (context), &color);
  gdk_cairo_set_source_rgba (cr, &color);




  cairo_fill (cr);

 return FALSE;
}
