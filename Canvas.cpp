#include "Canvas.h"

bool Canvas::on_button_press_event(GdkEventButton* event) {
    if(event->type == GDK_BUTTON_PRESS && event->button == 1) {
        switch (toolStatus) {
            case SELECT:
                click1 = false; click2 = false;
                isDragging = false;
                // this gonna be a whole dang jaunt
                break;
            case LINE:
                if(!click1 && !click2) {
                    clicked_x = event->x; clicked_y = event->y;
                    click1 = true;
                    isDragging = true;
                }

                if(click1 && !click2 && (int)event->x != clicked_x && (int)event->y != clicked_y) {
                    mouse_x = event->x; mouse_y = event->y;
                    click2 = true;
                    isDragging = false;

                    drawables.push_back(new Line(clicked_x, clicked_y, mouse_x, mouse_y));

                    queue_draw();
                } break;
            case BLOCK:
                click1 = false; click2 = false;
                isDragging = false;

                drawables.push_back(new Block(mouse_x, mouse_y));

                queue_draw();

                break;
        } return true;
    } return false;
}

bool Canvas::on_motion_notify_event(GdkEventMotion* event) {
    mouse_x = event->x; mouse_y = event->y;

    queue_draw();

    return true;
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

    for(Drawable* drawable : drawables) { drawable->draw(cr); }

    switch (toolStatus) {
        case SELECT: {
            break;
        } case LINE: {
            if (isDragging && toolStatus == LINE) {
                Line line(clicked_x, clicked_y, mouse_x, mouse_y);
                line.draw(cr);
            } break;
        } case BLOCK: {
            Block block(mouse_x, mouse_y);
            block.draw(cr);
            break;
        }
    } if(click2) { click1 = false; click2 = false; }

    cr->restore();

    cr->save();
    cr->set_source_rgb(0.5, 0, 0.5);
    draw_text(cr, "yeet", width, height/2);
    cr->restore();

    return true;
}

void Canvas::draw_text(const Cairo::RefPtr<Cairo::Context>& cr, const Glib::ustring& str, int width, int height) {
    Pango::FontDescription font;
    font.set_family("Monospace");
    font.set_weight(Pango::WEIGHT_BOLD);

    int text_width, text_height;
    auto layout = create_pango_layout(str);
    layout->set_font_description(font);
    layout->get_pixel_size(text_width, text_height);

    cr->move_to((800-text_width)/2, (400-text_height)/2);
    layout->show_in_cairo_context(cr);
}
