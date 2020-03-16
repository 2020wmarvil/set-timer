#include <iostream>
#include <gtkmm.h>

void clicked() {
    std::cout << "clicked" << std::endl;
}

int main(int argc, char *argv[]) {
    auto app = Gtk::Application::create(argc, argv, "org.gtkmm.examples.base");

    auto builder = Gtk::Builder::create_from_file("../gui.glade");

    Gtk::Window* window = nullptr;
    builder->get_widget("window", window);
    window->maximize();

    Gtk::Button* button = nullptr;
    builder->get_widget("button", button);
    button->signal_clicked().connect(
        sigc::ptr_fun(&clicked)
    );


    return app->run(*window);
}
