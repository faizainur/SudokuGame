#include <gtk/gtk.h>
#include "headers/sudoku.h"


GtkBuilder *builder, *builder_about;
GtkWidget *main_window, *menu_new, *menu_load, *menu_quit, *menu_about, *img_clear, *btn_clear;
GtkWidget *header, *btn_check, *textEntry[9][9], *btnBox, *dialog, *lblCounter[9];
GtkWidget *btnYes, *btnNo, *img_caution, *lbl_ans_status, *lbl_ask_new_game, *btn_menu;
GtkAboutDialog *about_window;
GError *error = NULL;
PangoAttrList *attrlist;
PangoAttribute *attr;
PangoFontDescription *df;
int blankCounter[9];


struct sudokuTable sudoTbl;
void init(int);
void new_game();
int getRand();
int initAbout();
void initComponent();
void checkAns();
void clearTable();

int main(int argc, char **argv)
{
    // inisialisasi
    gtk_init(&argc, &argv);
    attrlist = pango_attr_list_new();
    builder = gtk_builder_new();
    if(!gtk_builder_add_from_file(builder, "resources/glade-templates/gui_interface.glade", &error)){
        g_warning("%s", error->message);
        g_free(error);
        return 1;
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
            gtk_editable_set_editable(GTK_EDITABLE(textEntry[i][j]), FALSE);

        }
    }

    pango_attr_list_unref(attrlist);
    gtk_header_bar_set_title(GTK_HEADER_BAR (header), "Sudoku Game");
    g_signal_connect(btn_check, "clicked", G_CALLBACK(checkAns), NULL);
    g_signal_connect(btn_clear, "clicked", G_CALLBACK(clearTable), NULL);
    g_signal_connect(menu_new, "activate", G_CALLBACK(new_game), NULL);
    g_signal_connect(menu_quit, "activate", G_CALLBACK(gtk_main_quit), NULL);
    g_signal_connect(menu_about, "activate", G_CALLBACK(initAbout), NULL);

    gtk_builder_connect_signals(builder, NULL);

    g_object_unref(G_OBJECT(builder));

    gtk_widget_show(main_window);
    gtk_main();
    return 0;
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
    clearTable();
    gtk_widget_show(btn_check);
    gtk_widget_show(btn_clear);
    gtk_widget_show(btn_menu);
    for (i = 0; i < 9; ++i){
        blankCounter[i] = 0;
    }
    init(getRand());
    for (i = 0; i < 9; ++i){
        for (j = 0; j < 9; j++){
            char *a;
            a[0] = sudoTbl.arrPtr[i][j];
            char ans;
            ans = sudoTbl.ansArr[i][j];
            if ((int)a[0] != 32){
                gtk_editable_set_editable(GTK_EDITABLE(textEntry[i][j]), FALSE);
                gtk_entry_set_text(GTK_ENTRY(textEntry[i][j]), a);
            } else {
                gtk_editable_set_editable(GTK_EDITABLE(textEntry[i][j]), TRUE);
                int b = (int)ans;
                blankCounter[b - 49] += 1;
            }
        }
    }
    for (i = 0; i < 9; ++i){
        printf("%d ", blankCounter[i]);
        char counter[2];
        counter[0] = (char)blankCounter[i] + 48;
        gtk_label_set_text(GTK_LABEL(lblCounter[i]), counter);
    }
    // gtk_label_set_text(GTK_LABEL(lbl_ask_new_game), "Wanna play one more ?");


}

int getRand(){
    int i, num;
    bool status;
    num = rand() % ARRAY_CATALOG; // generate number between 0 and ARRAY_CATALOG    
    return num; 
}

void initComponent(){
    int i,j,k;
    
    main_window = GTK_WIDGET(gtk_builder_get_object(builder, "main_window"));
    header = GTK_WIDGET(gtk_builder_get_object(builder, "header"));
    btn_check = GTK_WIDGET(gtk_builder_get_object(builder, "btn_check"));
    menu_new = GTK_WIDGET(gtk_builder_get_object(builder, "menu_new"));
    menu_load = GTK_WIDGET(gtk_builder_get_object(builder, "menu_load"));
    menu_about = GTK_WIDGET(gtk_builder_get_object(builder, "menu_about"));
    menu_quit = GTK_WIDGET(gtk_builder_get_object(builder, "menu_quit"));
    img_clear = GTK_WIDGET(gtk_builder_get_object(builder, "img_clear"));
    btn_clear = GTK_WIDGET(gtk_builder_get_object(builder, "btn_clear"));
    dialog = GTK_WIDGET(gtk_builder_get_object(builder, "dialog_ans_status"));
    btnNo = GTK_WIDGET(gtk_builder_get_object(builder, "btn_no_new"));
    btnYes = GTK_WIDGET(gtk_builder_get_object(builder, "btn_yes_new"));
    lbl_ans_status = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_ans_status"));
    lbl_ask_new_game = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_ask_new_game"));
    img_caution = GTK_WIDGET(gtk_builder_get_object(builder, "img_caution"));
    btn_menu = GTK_WIDGET(gtk_builder_get_object(builder, "btn_menu"));
    
    for (i = 0; i < 9; ++i){
        for (j = 0; j < 9; ++j){
            k = j;
            char a[] = "txt_";
            a[4] = (char)i + 48;
            a[5] = (char)k + 48;
            textEntry[i][j] = GTK_WIDGET(gtk_builder_get_object(builder, a));
        }
    }

    for (i = 0; i < 9; ++i){
        char lbl1[] = "lbl_x_counter";
        lbl1[4] = (char)i + 49;
        lblCounter[i] = GTK_WIDGET(gtk_builder_get_object(builder, lbl1));
    }
    gtk_widget_hide(btn_check);
    gtk_widget_hide(btn_clear);
    gtk_widget_hide(btn_menu);
    
    
}

int initAbout(){
    builder_about = gtk_builder_new();
    if (!gtk_builder_add_from_file(builder_about, "resources/glade-templates/main_about.glade", &error)){
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

void clearTable(){
    int i, j;
    for (i = 0; i < 9; ++i){
        for (j = 0; j < 9; ++j){
            gtk_entry_set_text(GTK_ENTRY(textEntry[i][j]), "");
            gtk_editable_set_editable(GTK_EDITABLE(textEntry[i][j]), FALSE);

        }
    }
}

void checkAns(){
    int i, j;
    int counter;
    for (i = 0; i < 9; ++i){
        for (j = 0; j < 9; ++j){
            const char *ans;
            ans = gtk_entry_get_text(GTK_ENTRY(textEntry[i][j]));
            if (ans[0] != sudoTbl.ansArr[i][j]){
                counter += 1;
            }
        }
    }
    if (counter > 0){
        gtk_image_set_from_file(GTK_IMAGE(img_caution), "resources/icon/if_sad_emoticon.png");
        gtk_widget_hide(btnNo);
        gtk_widget_hide(lbl_ask_new_game);
        gtk_button_set_label(GTK_BUTTON(btnYes), "Back to the game");
        gtk_label_set_text(GTK_LABEL(lbl_ans_status), "Check again !!!");
        int result = gtk_dialog_run(GTK_DIALOG(dialog));
        switch (result){
            case GTK_RESPONSE_YES:
                gtk_widget_hide(dialog);
                break;
            default :
                printf("Error");
                break;
        }
    } else {
        gtk_widget_show(btnNo);
        gtk_widget_show(lbl_ask_new_game);
        gtk_image_set_from_file(GTK_IMAGE(img_caution), "resources/icon/if_correct_answer.png");
        gtk_button_set_label(GTK_BUTTON(btnYes), "Yes, play more !");
        gtk_label_set_text(GTK_LABEL(lbl_ans_status), "You are doing great !!!");
        gtk_label_set_text(GTK_LABEL(lbl_ask_new_game), "Wanna play one more ?");
        int result = gtk_dialog_run(GTK_DIALOG(dialog));
        switch (result){
            case GTK_RESPONSE_YES:
                gtk_widget_hide(dialog);
                gtk_widget_hide(btn_check);
                gtk_widget_hide(btn_clear);
                gtk_widget_hide(btn_menu);
                clearTable();
                break;
            case GTK_RESPONSE_NO:
                gtk_main_quit();
                break;
            default :
                printf("Error");
                break;
        }
    }
}