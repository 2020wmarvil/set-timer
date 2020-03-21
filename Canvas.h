#pragma once

#include <vector>

#include <gtkmm/drawingarea.h>
#include <gtkmm/builder.h>

enum ToolStatus { SELECT, LINE, BLOCK };

extern int toolStatus;

class Canvas : public Gtk::DrawingArea {
private:
    Glib::RefPtr<Gtk::Builder> m_refGlade;

    struct line { int x1,y1,x2,y2; };
    std::vector<line> lines;

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
