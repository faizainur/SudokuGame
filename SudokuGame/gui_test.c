#include <gtk/gtk.h>
#include <stdlib.h>
#include "sudoku.h"
GtkBuilder *builder;
GtkWidget *window, *menu_new, *menu_load, *menu_quit, *menu_about;
GtkWidget *header, *button, *textEntry[9][9];
GError *error = NULL;
PangoAttrList *attrlist;
PangoAttribute *attr;
PangoFontDescription *df;
struct sudokuTable sudoTbl;

void fexit(GtkWidget *widget, gpointer data){
    g_print("Test exit");
}

void init(int);
void new_game();
void initComponent(){
    int i,j,k;
    
    window = GTK_WIDGET(gtk_builder_get_object(builder, "main_window"));
    header = GTK_WIDGET(gtk_builder_get_object(builder, "header"));
    button = GTK_WIDGET(gtk_builder_get_object(builder, "btn_check"));
    menu_new = GTK_WIDGET(gtk_builder_get_object(builder, "menu_new"));
    menu_load = GTK_WIDGET(gtk_builder_get_object(builder, "menu_load"));
    menu_about = GTK_WIDGET(gtk_builder_get_object(builder, "menu_about"));
    menu_quit = GTK_WIDGET(gtk_builder_get_object(builder, "menu_quit"));
    for (i = 0; i < 9; ++i){
        for (j = 0; j < 9; ++j){
            k = j;
            char a[5] = "txt_";
            a[4] = (char)i + 48;
            a[5] = (char)k + 48;
            // printf("%c %s\n", (char)j+48, a);
            textEntry[i][j] = GTK_WIDGET(gtk_builder_get_object(builder, a));
        }
    }
    
}   
int main(int argc, char **argv)
{
    gtk_init(&argc, &argv);
    attrlist = pango_attr_list_new();
    builder = gtk_builder_new();
    if(!gtk_builder_add_from_file(builder, "gui_interface.glade", &error)){
        g_warning("%s", error->message);
        g_free(error);
        return (1);
    }
    initComponent();
    df = pango_font_description_new();
    pango_font_description_set_size(df, 20*PANGO_SCALE);
    
    attr = pango_attr_font_desc_new(df);
    pango_font_description_free(df);
    attr->start_index = 0;
    attr->end_index = 2;
    pango_attr_list_insert(attrlist, attr);

    int i,j;    
    for (i = 0; i < 9; ++i){
        for (j = 0; j < 9; ++j){
            gtk_entry_set_attributes(GTK_ENTRY(textEntry[i][j]), attrlist);
            gtk_entry_set_alignment(GTK_ENTRY(textEntry[i][j]), 0.5);
        }
    }
    gtk_editable_set_editable(GTK_EDITABLE(textEntry[0][0]), FALSE);
    // gtk_editable_set_editable(GTK_EDITABLE(entry), TRUE);

    pango_attr_list_unref(attrlist);
    gtk_header_bar_set_title(GTK_HEADER_BAR (header), "Sudoku Game");
    // gtk_window_set_titlebar(GTK_WINDOW(window), header);
    g_signal_connect(button, "clicked", G_CALLBACK(gtk_main_quit), NULL);
    g_signal_connect(menu_new, "activate", G_CALLBACK(new_game), NULL);
    g_signal_connect(menu_quit, "activate", G_CALLBACK(gtk_main_quit), NULL);
    g_signal_connect_swapped (button, "clicked", G_CALLBACK (gtk_widget_destroy), window);

    gtk_builder_connect_signals(builder, NULL);

    g_object_unref(G_OBJECT(builder));

    gtk_widget_show(window);
    gtk_main();
    return (0);
    system("pause");
}
void init(int randNum){
    int i, j;
    initTables();
    sudoTbl.arrPtr = arrayList[randNum];
    // sudoTbl.blankCounter = 0;
}
void new_game(){
    int i,j;
    init(0);
    for (i = 0; i < 9; ++i){
        for (j = 0; j < 9; j++){
            char *a;
            a[0] = sudoTbl.arrPtr[i][j];
            gtk_entry_set_text(GTK_ENTRY(textEntry[i][j]), a);
        }
    }
}