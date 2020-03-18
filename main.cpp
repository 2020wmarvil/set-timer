#include <iostream>

#include <gtkmm/window.h>
#include <gtkmm/builder.h>
#include <gtkmm/toolbutton.h>

#include "Canvas.h"

// todo
// prebuilt blocks in the canvas
// application menu/main menu
// toolbar with tooltips and keyboard shortcuts
// popup menu on blocks
// pixel buffer
// drag and drop blocks
// entries and spin buttons in the blocks
// scrollbars/variable size canvas
// Gio::Resource and glib-compile-resources to directly link resources to the executable
// FileChooserDialog to open files, possibly ColorChooserDialog to make custom blocks
// Non-modal AboutDialog to list the creators and link our repo
// use pix_buf for a background logo when the application is empty
// saving a built timer to an executable file that is a time

void selectButton_clicked() { std::cout << "select\n"; }
void lineButton_clicked() { std::cout << "line\n"; }
void blockButton_clicked() { std::cout << "block\n"; }

int main(int argc, char *argv[]) {
    auto app = Gtk::Application::create(argc, argv, "org.gtkmm.examples.base");
    auto builder = Gtk::Builder::create_from_file("../gui.glade");
    gtk_builder_add_callback_symbol(builder->gobj(),"lineButton_clicked",&lineButton_clicked);
    gtk_builder_add_callback_symbol(builder->gobj(),"selectButton_clicked",&selectButton_clicked);
    gtk_builder_add_callback_symbol(builder->gobj(),"blockButton_clicked",&blockButton_clicked);
    gtk_builder_connect_signals(builder->gobj(),NULL);

    Gtk::Window* window = nullptr;
    builder->get_widget("window", window);
    window->maximize();

    Canvas* area = nullptr;
    builder->get_widget_derived("drawingArea", area);
    area->show();

    app->run(*window);

    return 0;
}
