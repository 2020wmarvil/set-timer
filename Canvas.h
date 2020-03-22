#pragma once

#include <vector>
#include <cmath>
#include <iostream>

#include <gtkmm/drawingarea.h>
#include <gtkmm/builder.h>

#include "Drawable.h"
#include "Line.h"
#include "Block.h"

enum ToolStatus { SELECT, LINE, BLOCK };

extern int toolStatus;

class Canvas : public Gtk::DrawingArea {
private:
    Glib::RefPtr<Gtk::Builder> m_refGlade;

    std::vector<Drawable*> drawables;
    Drawable* selected_drawable = nullptr;

    bool click1=false, click2=false, isDragging=false;

    int clicked_x, clicked_y;
    int mouse_x, mouse_y;

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
