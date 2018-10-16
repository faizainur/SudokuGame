#include <gtk/gtk.h>
    GtkWidget *header, *label, *button;
void on_action_clicked(){
    gtk_label_set_text(GTK_LABEL (label), "Hello World");
}

static void
print_hello (GtkWidget *widget,
             gpointer   data)
{
//   g_print ("My Name Misha\n");
    gtk_label_set_text(GTK_LABEL (label), "Hello World");

}
    
int main(int argc, char **argv)
{
    GtkBuilder *builder;
    GtkWidget *window;
    GError *error = NULL;
    

    gtk_init(&argc, &argv);
    builder = gtk_builder_new();

    if(!gtk_builder_add_from_file(builder, "main.glade", &error)){
        g_warning("%s", error->message);
        g_free(error);
        return (1);
    }

    window = GTK_WIDGET(gtk_builder_get_object(builder, "main_window"));
    header = GTK_WIDGET(gtk_builder_get_object(builder, "header"));
    label = GTK_WIDGET(gtk_builder_get_object(builder, "label"));
    button = GTK_WIDGET(gtk_builder_get_object(builder, "action"));
    g_signal_connect (button, "clicked", G_CALLBACK (print_hello), NULL);
      g_signal_connect_swapped (button, "clicked", G_CALLBACK (gtk_main_quit), window);

    // gtk_label_set_text(GTK_LABEL (label), "Hello World");

    gtk_header_bar_set_title(GTK_HEADER_BAR (header), "Welcome");
    // gtk_window_set_titlebar(GTK_WINDOW (window), header);
    // gtk_header_bar_set_show_close_button(GTK_HEADER_BAR (header), TRUE);
    gtk_builder_connect_signals(builder, NULL);
    

    g_object_unref(G_OBJECT(builder));
    // on_action_clicked();
    gtk_widget_show(window);
    gtk_main();
    return (0);
}



// #include <gtk/gtk.h>

// int
// main( int    argc,
//       char **argv )
// {
//     GtkBuilder *builder;
//     GtkWidget *window;
//     GtkWidget *header;
//     GtkWidget *box;
//     GError     *error = NULL;

//     /* Init GTK+ */
//     gtk_init( &argc, &argv );

//     /* Create new GtkBuilder object */
//     builder = gtk_builder_new();
//     /* Load UI from file. If error occurs, report it and quit application.
//      * Replace "tut.glade" with your saved project. */
//     if( ! gtk_builder_add_from_file( builder, "welcome.glade", &error ) )
//     {
//         g_warning( "%s", error->message );
//         g_free( error );
//         return( 1 );
//     }

//     /* Get main window pointer from UI */
//     window = GTK_WIDGET( gtk_builder_get_object( builder, "start_screen" ) );
//     // header = GTK_WIDGET( gtk_builder_get_object( builder, "header_main"));
//     // gtk_header_bar_set_show_close_button (GTK_HEADER_BAR (header), TRUE);
//     // header = gtk_header_bar_new ();
//     // gtk_header_bar_set_title(GTK_HEADER_BAR (header), "Welcome");
//     // gtk_header_bar_set_has_subtitle (GTK_HEADER_BAR (header), FALSE);
//     /* Connect signals */
//     gtk_builder_connect_signals( builder, NULL );
//     // gtk_header_bar_pack_start (GTK_HEADER_BAR (header), box);
//     // gtk_window_set_titlebar(GTK_WINDOW(window), header);
//     /* Destroy builder, since we don't need it anymore */
//     g_object_unref( G_OBJECT( builder ) );

//     /* Show window. All other widgets are automatically shown by GtkBuilder */
//     gtk_widget_show( window );

//     /* Start main loop */
//     gtk_main();

//     return( 0 );
// }

