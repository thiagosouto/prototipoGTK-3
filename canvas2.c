#include <gtk/gtk.h>

int isdragging = 0;

void destruir (void)
{
  gtk_main_quit ();
}


gboolean circulo_preto_branco (GtkWidget *widget, cairo_t *cr, gpointer data)
{
  guint width, height;
  GdkRGBA color;
  GtkStyleContext *context;

  context = gtk_widget_get_style_context (widget);

  width = gtk_widget_get_allocated_width (widget);
  height = gtk_widget_get_allocated_height (widget);

  gtk_render_background (context, cr, 0, 0, width, height);
  gtk_style_context_get_color (context, gtk_style_context_get_state (context), &color);

  gtk_style_context_get_color (context, gtk_style_context_get_state (context), &color);
  gdk_rgba_parse (&color ,"rgba(0,0,0,0)");
  cairo_arc (cr, width / 2.0, height / 2.0, MIN (width, height) / 3.0, 0, 2 * G_PI);


  gtk_style_context_get_color (context, gtk_style_context_get_state (context), &color);
  gdk_rgba_parse (&color ,"rgba(250,250,250,250)");
  cairo_arc (cr, width / 2.0, height / 2.0, MIN (width, height) / 3.0, 0, 2 * G_PI);

  cairo_fill (cr);


  // cairo_arc (cr, width / 2.0, height / 2.0, MIN (width, height) / 2.0, 0, 2 * G_PI);
  // gtk_style_context_get_color (context, gtk_style_context_get_state (context), &color);
  // gdk_rgba_parse (&color ,"rgba(250,250,250,255)");
  // gdk_cairo_set_source_rgba (cr, &color);
  //
  //
  // cairo_fill (cr);

 return FALSE;
}

int main( int argc, char *argv[])
{
  GtkWidget *janela;
  GtkWidget *caixa;
  GtkWidget *grade;


  gtk_init (&argc, &argv);
  janela = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  g_signal_connect (janela, "destroy", G_CALLBACK(destruir), NULL);
  gtk_container_set_border_width (GTK_CONTAINER (janela), 50);

  grade = gtk_grid_new ();
  gtk_container_add (GTK_CONTAINER (janela), grade);

  //gtk_widget_add_events (canvas, GDK_BUTTON_PRESS_MASK);
  GtkWidget *area_desenho = gtk_drawing_area_new ();
  gtk_widget_set_size_request (area_desenho, 100, 100);
  g_signal_connect (G_OBJECT (area_desenho), "draw", G_CALLBACK (circulo_preto_branco), NULL);
  gtk_grid_attach (GTK_GRID(grade),area_desenho, 1,1,1,1);


  //ends gtkdrawable + cairo example
  gtk_widget_show_all (janela);
  gtk_main ();
  return (0);
}


/* EOF */
