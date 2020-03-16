#include <iostream>
#include <gtkmm.h>

class MyArea : public Gtk::DrawingArea {
public:
    MyArea(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refGlade)
    : Gtk::DrawingArea(cobject), m_refGlade(refGlade) {}
    virtual ~MyArea() {}
protected:
    Glib::RefPtr<Gtk::Builder> m_refGlade;
    bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr) override {
        Gtk::Allocation allocation = get_allocation();
        const int width = allocation.get_width();
        const int height = allocation.get_height();

        int x = width / 2, y = height / 2;

        cr->set_source_rgb(1.0, 0.0, 0.0);
        cr->set_line_width(10.0);

        cr->move_to(0, 0);
        cr->line_to(x, y);
        cr->stroke();
    }
};

void clicked() { std::cout << "clicked\n"; }

int main(int argc, char *argv[]) {
    auto app = Gtk::Application::create(argc, argv, "org.gtkmm.examples.base");
    auto builder = Gtk::Builder::create_from_file("../gui.glade");

    Gtk::Window* window = nullptr;
    builder->get_widget("window", window);
    window->maximize();

    Gtk::Button* button = nullptr;
    builder->get_widget("button", button);
    button->signal_clicked().connect(sigc::ptr_fun(&clicked));

    MyArea* area = nullptr;
    builder->get_widget_derived("drawingArea", area);

    app->run(*window);

    auto context = area->get_window()->create_cairo_context();

    return 0;
}
