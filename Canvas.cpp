#include "Canvas.h"

bool Canvas::on_button_press_event(GdkEventButton* event) {
    if( (event->type == GDK_BUTTON_PRESS) && (event->button == 1)) {
        if(!click1 && !click2) {
            x1=event->x; y1=event->y;
            click1=true;
        }

        if(click1 && !click2 && (int)event->x != x1 && (int)event->y != y1) {
            x2=event->x; y2=event->y;
            click2=true;

            queue_draw();
        }

        return true;
    } return false;
}

bool Canvas::on_draw(const Cairo::RefPtr<Cairo::Context>& cr) {
    Gtk::Allocation allocation = get_allocation();
    const int width = allocation.get_width();
    const int height = allocation.get_height();

    int x = width / 2, y = height / 2;

    cr->set_source_rgb(0.0, 0.0, 0.0);
    cr->paint();

    cr->save();
    cr->set_line_width(2);
    cr->set_source_rgb(1, 1, 1);
    if(click1 && click2) {
        cr->move_to(x1, y1);
        cr->line_to(x2, y2);
        cr->stroke();
        click1 = false; click2 = false;
    } cr->restore();

    cr->save();
    cr->set_source_rgb(0.5, 0, 0.5);
    draw_text(cr, "yeet", width, height/2);
    cr->restore();

    return true;
}

void Canvas::draw_text(const Cairo::RefPtr<Cairo::Context>& cr, const std::string& str, int width, int height) {
    Pango::FontDescription font;
    font.set_family("Monospace");
    font.set_weight(Pango::WEIGHT_BOLD);

    int text_width, text_height;
    auto layout = create_pango_layout(str);
    layout->set_font_description(font);
    layout->get_pixel_size(text_width, text_height);

    cr->move_to((width-text_width)/2, (height-text_height)/2);
    layout->show_in_cairo_context(cr);
}
