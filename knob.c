#include <gtk/gtk.h>
#include <stdlib.h>

typedef struct t_knob t_knob;

typedef void (*t_knob_callback)(t_knob *knob);

struct t_knob
{

   float value;
   int x;
   int y;
   GtkWidget *drawing_area;
   t_knob_callback callback;

};

void destroy2 (gpointer janela)
{

  gtk_window_get_destroy_with_parent (GTK_WINDOW(janela));
  return;

}

void destroy (void)
{

  gtk_main_quit ();
  return;

}


static gboolean motion_notify_event_cb (GtkWidget *widget, GdkEventMotion *event, gpointer user_data)
{

  if (!(event->state & GDK_BUTTON1_MASK))
  {
      return TRUE;
  }

  int width;
  int height;

  t_knob *knob = (t_knob *) user_data;

  if (event->x > knob->x){
      knob->value ++;
      knob->x = event->x;
  }else{
          knob->value --;
          knob->x = event->x;
  }

  if (event->y < knob->y){
      knob->value ++;
      knob->y = event->y;
  }else{
          knob->value --;
          knob->y = event->y;
  }


  width = gtk_widget_get_allocated_width(knob->drawing_area);
  height = gtk_widget_get_allocated_height(knob->drawing_area);

  gtk_widget_queue_draw_area(knob->drawing_area, 0, 0, width, height);

  if (knob->callback != NULL)
  {
      knob->callback(knob);

  }

  return TRUE;
}


gboolean draw(GtkWidget *widget, GdkEventConfigure *event, gpointer user_data)
{

  cairo_t *cr;

  t_knob *knob = (t_knob *) user_data;

  cr = gdk_cairo_create(gtk_widget_get_window(knob->drawing_area));
  int width;
  int height;

  width = gtk_widget_get_allocated_width(widget);
  height = gtk_widget_get_allocated_height(widget);

  // Background circle
  cairo_set_source_rgb(cr, 0, 1, 0);
  cairo_set_line_width(cr, 1);
  cairo_arc(cr, width / 2, height / 2.0, MIN(width, height)/2.0, 0., 2.0 * G_PI);
  cairo_fill_preserve(cr);
  cairo_set_source_rgb(cr, 0, 0, 0);
  cairo_stroke(cr);

  float angle1 = G_PI; // Start point
  float angle2 = angle1 + knob->value * (2.0 * G_PI / 128.0); // Start point

  cairo_new_sub_path(cr);
  cairo_set_source_rgb(cr, 1, 0, 0);
  cairo_arc(cr, width / 2, height / 2.0, MIN(width, height)/3.0, angle1, angle2);
  cairo_line_to (cr, width / 2, height / 2);
  cairo_line_to (cr, MIN(width, height)/2.0 - MIN(width, height)/3.0 , height / 2);

  cairo_fill_preserve(cr);
  cairo_set_source_rgb(cr, 0, 0, 0);
  cairo_stroke(cr);
  cairo_destroy(cr);
  return FALSE;

}

GtkWidget * create_knob(int value, int size, t_knob_callback callback)
{
    t_knob * knob = (t_knob *) malloc(sizeof(t_knob));
    knob->callback = callback;
    knob->x = 0;
    knob->y = 0;
    knob->value = value;
    knob->drawing_area = gtk_drawing_area_new();

    gtk_widget_set_events(knob->drawing_area, GDK_POINTER_MOTION_MASK | GDK_BUTTON_PRESS_MASK | GDK_BUTTON_RELEASE_MASK);

   gtk_widget_set_size_request(knob->drawing_area, size, size);
   g_signal_connect(knob->drawing_area, "draw", G_CALLBACK(draw), knob);
   g_signal_connect (knob->drawing_area, "motion-notify-event",G_CALLBACK (motion_notify_event_cb), knob);
   return knob->drawing_area;
}


void callback(t_knob * knob){

    printf("%f\n", knob->value);

}

int main (int argc, char *argv[]){
   GtkWidget *janela;
   GtkWidget *knob1;
   GtkWidget *knob2;
   GtkWidget *caixa;

   gtk_init (&argc, &argv);

   janela = gtk_window_new (GTK_WINDOW_TOPLEVEL);
   g_signal_connect (janela, "destroy",G_CALLBACK (destroy), NULL);
   gtk_container_set_border_width (GTK_CONTAINER (janela), 30);

  caixa = gtk_box_new (GTK_ORIENTATION_VERTICAL,2);
  gtk_container_add (GTK_CONTAINER (janela), caixa);


   knob1 = create_knob(10, 100, callback);
   gtk_container_add (GTK_CONTAINER (caixa), knob1);

   knob2 = create_knob(10, 100, NULL);
   gtk_container_add (GTK_CONTAINER (caixa), knob2);

   gtk_widget_show_all (janela);

   gtk_main ();

   return 0;
}
