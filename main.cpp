#include <iostream>
#include <gtkmm.h>

// g++ main.cpp `pkg-config --cflags --libs gtkmm-3.0`

int main(int argc, char *argv[]) {
    Gtk::Main kit(argc, argv);
    Gtk::Window window;

		Gtk::Button test;
		window.add(test);
    kit.run(window);
    return 0;
}
