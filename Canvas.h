#pragma once

#include <gtkmm.h>

class Canvas : public Gtk::DrawingArea {
private:
    Glib::RefPtr<Gtk::Builder> m_refGlade;

    bool click1, click2;
    int x1, x2, y1, y2;
protected:
    bool on_button_press_event(GdkEventButton * event);
    bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr) override;
public:
    Canvas(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refGlade)
    : Gtk::DrawingArea(cobject), m_refGlade(refGlade) {
       add_events(Gdk::BUTTON_PRESS_MASK);
       click1 = false; click2 = false;
    }
    virtual ~Canvas() {}
};
