#pragma once

#include <gtkmm/drawingarea.h>
#include <gtkmm/builder.h>

class Canvas : public Gtk::DrawingArea {
private:
    Glib::RefPtr<Gtk::Builder> m_refGlade;

    bool click1=false, click2=false, isDragging=false;
    int x1, x2, y1, y2;

    void draw_text(const Cairo::RefPtr<Cairo::Context>& cr, const Glib::ustring& str, int width, int height);
protected:
    bool on_button_press_event(GdkEventButton * event);
    bool on_motion_notify_event(GdkEventMotion* event);
    bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr) override;
public:
    Canvas(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refGlade)
    : Gtk::DrawingArea(cobject), m_refGlade(refGlade) {
       add_events(Gdk::POINTER_MOTION_MASK | Gdk::BUTTON_PRESS_MASK);
       click1 = false; click2 = false;
    }
    virtual ~Canvas() {}
};
