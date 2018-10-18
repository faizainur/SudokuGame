// #include "../headers/headerlist.h"
#include <gtk/gtk.h>
#include "headers/sudoku.h"


GtkBuilder *builder, *builder_about;
GtkWidget *main_window, *menu_new, *menu_load, *menu_quit, *menu_about;
GtkWidget *header, *button, *textEntry[9][9], *btnBox;
GtkAboutDialog *about_window;
GError *error = NULL;
PangoAttrList *attrlist;
PangoAttribute *attr;
PangoFontDescription *df;
struct sudokuTable sudoTbl;

// void on_about_window_close(GtkWidget *widget, gpointer data){
//     g_print("Test exit");
// }

void init(int);
void new_game();
int getRand();
int initAbout();
void initComponent();

int main(int argc, char **argv)
{
    // inisialisasi
    gtk_init(&argc, &argv);
    attrlist = pango_attr_list_new();
    builder = gtk_builder_new();
    if(!gtk_builder_add_from_file(builder, "glade-templates/gui_interface.glade", &error)){
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
            gtk_entry_set_max_length(GTK_ENTRY(textEntry[i][j]), 1);
        }
    }

    pango_attr_list_unref(attrlist);
    gtk_header_bar_set_title(GTK_HEADER_BAR (header), "Sudoku Game");
    g_signal_connect(button, "clicked", G_CALLBACK(gtk_main_quit), NULL);
    g_signal_connect(menu_new, "activate", G_CALLBACK(new_game), NULL);
    g_signal_connect(menu_quit, "activate", G_CALLBACK(gtk_main_quit), NULL);
    g_signal_connect(menu_about, "activate", G_CALLBACK(initAbout), NULL);
    g_signal_connect_swapped (button, "clicked", G_CALLBACK (gtk_widget_destroy), main_window);

    gtk_builder_connect_signals(builder, NULL);

    g_object_unref(G_OBJECT(builder));

    gtk_widget_show(main_window);
    gtk_main();
    return (0);
    system("pause");
}
void init(int randNum){
    int i, j;
    initTables();
    sudoTbl.arrPtr = arrayQList[randNum];
    sudoTbl.ansArr = arrayAList[randNum];
}
void new_game(){
    int i,j;
    init(getRand());
    for (i = 0; i < 9; ++i){
        for (j = 0; j < 9; j++){
            char *a;
            a[0] = sudoTbl.arrPtr[i][j];
            if ((int)a[0] != 32){
                gtk_editable_set_editable(GTK_EDITABLE(textEntry[i][j]), FALSE);
                gtk_entry_set_text(GTK_ENTRY(textEntry[i][j]), a);
            } else {
                gtk_editable_set_editable(GTK_EDITABLE(textEntry[i][j]), TRUE);
            }
        }
    }
}

int getRand(){
    int i, num;
    bool status;
    num = rand() % ARRAY_CATALOG; // generate number between 0 and ARRAY_CATALOG    
    return num; 
}

int checkAns(){

}

void initComponent(){
    int i,j,k;
    
    main_window = GTK_WIDGET(gtk_builder_get_object(builder, "main_window"));
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
            textEntry[i][j] = GTK_WIDGET(gtk_builder_get_object(builder, a));
        }
    }
    
}

int initAbout(){
    builder_about = gtk_builder_new();
    if (!gtk_builder_add_from_file(builder_about, "main_about.glade", &error)){
        g_warning("%s", error->message);
        g_free(error);
        return (1);
    }
    about_window = GTK_ABOUT_DIALOG(gtk_builder_get_object(builder_about, "about_window"));

    gtk_builder_connect_signals(builder_about, NULL);

    g_object_unref(G_OBJECT(builder_about));

    gtk_show_about_dialog(GTK_WINDOW(main_window), "program-name",
    gtk_about_dialog_get_program_name(about_window), "authors",
    gtk_about_dialog_get_authors(about_window), "license",
    gtk_about_dialog_get_license(about_window), "logo",
    gtk_about_dialog_get_logo(about_window), "version",
    gtk_about_dialog_get_version(about_window), "comments",
    gtk_about_dialog_get_comments(about_window), "copyright",
    gtk_about_dialog_get_copyright(about_window), "website",
    gtk_about_dialog_get_website(about_window), "website-label",
    gtk_about_dialog_get_website_label(about_window), "logo-icon-name",
    gtk_about_dialog_get_logo_icon_name(about_window), NULL);
    return (0);
}