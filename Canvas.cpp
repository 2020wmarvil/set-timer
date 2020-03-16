#include "Canvas.h"

bool Canvas::on_draw(const Cairo::RefPtr<Cairo::Context>& cr) {
    Gtk::Allocation allocation = get_allocation();
    const int width = allocation.get_width();
    const int height = allocation.get_height();

    int x = width / 2, y = height / 2;

    cr->set_source_rgb(0.0, 0.0, 0.0);
    cr->paint();

    cr->save();
        cr->set_source_rgb(1.0, 0.0, 0.0);
        cr->set_line_width(10.0);
        cr->move_to(0, 0);
        cr->line_to(x, y);
        cr->line_to(width, 0);
        cr->stroke();
    cr->restore();
}
