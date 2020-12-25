// Andrew Barlow
// Description
//
// v 0.0.0


// LIBRARIES//////////////////////////////////////////////

// printf, scanf, file ops
#include <stdio.h>
// malloc, calloc
#include <stdlib.h>
// math
#include <math.h>
// gtk
#include <gtk/gtk.h>

// GLOBAL VARS ///////////////////////////////////////////
int count = 0;

// CLASSES////////////////////////////////////////////////

// HELPER FUNCTIONS///////////////////////////////////////
void end_program (GtkWidget *wid, gpointer ptr) {
        gtk_main_quit();
}

void count_button (GtkWidget *wid, gpointer ptr) {
        char buffer[33];
        count++;
        sprintf(buffer, "Button pressed %d times", count);
        gtk_label_set_text (GTK_LABEL (ptr) , buffer);
}

// MAIN //////////////////////////////////////////////////
int main(int argc, char *argv[]) {
        gtk_init (&argc, &argv);

        // create window & button
        GtkWidget *win = gtk_window_new (GTK_WINDOW_TOPLEVEL);
        GtkWidget *btn = gtk_button_new_with_label("Close Window");

        // on button click or window exit, call the end_program function
        g_signal_connect(btn, "clicked", G_CALLBACK(end_program), NULL);
        g_signal_connect(win, "delete_event", G_CALLBACK(end_program), NULL);


        // create a label and add it to the window
        GtkWidget *lbl = gtk_label_new("My Label");

        // create a button that counts the presses
        GtkWidget *btn2 = gtk_button_new_with_label("Count button");
        g_signal_connect (btn2, "clicked", G_CALLBACK (count_button), lbl);

        GtkWidget *box = gtk_vbox_new(FALSE, 5);

        gtk_box_pack_start (GTK_BOX (box) , btn2 , TRUE , TRUE , 0);
        gtk_box_pack_start (GTK_BOX (box) , lbl , TRUE , TRUE , 0);
        gtk_box_pack_start (GTK_BOX (box) , btn , TRUE , TRUE , 0);
        gtk_container_add (GTK_CONTAINER (win) , box);

        // show everything in the window container
        gtk_widget_show_all(win);

        // run it
        gtk_main();
        return 0;
}
