#include <gtkmm/window.h>
#include <gtkmm/builder.h>

#include "Canvas.h"

int main(int argc, char *argv[]) {
    auto app = Gtk::Application::create(argc, argv, "org.gtkmm.examples.base");
    auto builder = Gtk::Builder::create_from_file("../gui.glade");

    Gtk::Window* window = nullptr;
    builder->get_widget("window", window);
    window->maximize();

    Canvas* area = nullptr;
    builder->get_widget_derived("drawingArea", area);

    app->run(*window);

    return 0;
}
