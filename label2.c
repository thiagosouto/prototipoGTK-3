#include <gtk/gtk.h>

int count;

gboolean button_press_event(GtkWidget *widget,
               GdkEvent  *event,
               gpointer   user_data){
    GtkWidget * led;
    led = GTK_WIDGET(user_data);
    int width;
    int height;

    width = gtk_widget_get_allocated_width(led);
    height = gtk_widget_get_allocated_height(led);

    count++;
    gtk_widget_queue_draw_area(led, 0, 0, width, height);
    return FALSE;
}


gboolean drag_motion(GtkWidget      *widget,
               GdkDragContext *context,
               gint            x,
               gint            y,
               guint           time,
               gpointer        user_data){

    printf("x: %d y: %d\n", (int) x, (int) y);

}


gboolean medusa_gui_led_draw(
      GtkWidget *widget,
      GdkEventConfigure *event,
      GtkWidget * led){

   cairo_t *cr;

   cr = gdk_cairo_create(gtk_widget_get_window(led));
   int width;
   int height;

   width = gtk_widget_get_allocated_width(widget);
   height = gtk_widget_get_allocated_height(widget);

    if (count % 2 == 0)
       cairo_set_source_rgb(cr, 0, 1, 0);
    else
       cairo_set_source_rgb(cr, 1, 0, 0);

   /* Circle */
   cairo_set_line_width(cr, 1);
   cairo_arc(cr, width / 2, height / 2.0, MIN(width, height) / 3.0, 0., 2 * 3.14159);
   cairo_fill_preserve(cr);
   cairo_set_source_rgb(cr, 0, 0, 0);

   /* Finish */
   cairo_stroke(cr);
   cairo_destroy(cr);
   return FALSE;
}

void destroy2 (gpointer data){
  gtk_window_get_destroy_with_parent (GTK_WINDOW(data));
}

void destroy (void){
  gtk_main_quit ();
}


int main (int argc, char *argv[]){
   GtkWidget *janela;
   GtkWidget *led;

    count = 0;
   gtk_init (&argc, &argv);

   janela = gtk_window_new (GTK_WINDOW_TOPLEVEL);
   g_signal_connect (janela, "destroy",G_CALLBACK (destroy), NULL);
   gtk_container_set_border_width (GTK_CONTAINER (janela), 30);

    led = gtk_drawing_area_new();
    gtk_widget_set_events(led, 
                    GDK_POINTER_MOTION_MASK
                    | GDK_BUTTON_PRESS_MASK
                    | GDK_BUTTON_RELEASE_MASK);

   gtk_widget_set_size_request(led, 30, 30);
   g_signal_connect(led, "draw", G_CALLBACK(medusa_gui_led_draw), led);
   g_signal_connect(led, "button-press-event", G_CALLBACK(button_press_event), led);
   g_signal_connect(led, "drag-motion", G_CALLBACK(drag_motion), led);

   gtk_container_add (GTK_CONTAINER (janela), led);

   gtk_widget_show_all (janela);


   gtk_main ();

   return 0;
}
