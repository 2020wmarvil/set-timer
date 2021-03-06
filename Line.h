#pragma once

#include "Canvas.h"
#include "Block.h"

class Line {
private:
    double x1, x2, x3, x4;
    double y1, y2, y3, y4;
    int arrowHeadLength = 10;

    Block *source = nullptr, *dest = nullptr;

    void calculateArrowHead() {
        int angle = 45;
        double theta = angle * (M_PI / 180);

        double mx, my;
        int vx = x2 - x1;
        int vy = y2 - y1;
        double vmag = sqrt(vx*vx + vy*vy);
        double ux = vx / vmag;
        double uy = vy / vmag;
        mx = x2 - arrowHeadLength * ux;
        my = y2 - arrowHeadLength * uy;

        x3 = (mx-x2)*cos(theta) - (my-y2)*sin(theta) + mx;
        y3 = (mx-x2)*sin(theta) + (my-y2)*cos(theta) + my;

        theta = -theta;

        x4 = (mx-x2)*cos(theta) - (my-y2)*sin(theta) + mx;
        y4 = (mx-x2)*sin(theta) + (my-y2)*cos(theta) + my;
    }
public:
    Line(int x1, int y1, int x2, int y2)
    : x1(x1), y1(y1), x2(x2), y2(y2) {
        calculateArrowHead();
    }

    void draw(const Cairo::RefPtr<Cairo::Context>& cr) {
        if (x1 == x2 && y1 == y2) return;

        cr->move_to(x1, y1);
        cr->line_to(x2, y2);
        cr->move_to(x2, y2);
        cr->line_to(x3, y3);
        cr->move_to(x2, y2);
        cr->line_to(x4, y4);

        cr->stroke();
    }

    void setSourcePoint(int x, int y) {
        x1 = x; y1 = y;
        calculateArrowHead();
    }
    void setDestPoint(int x, int y) {
        x2 = x; y2 = y;
        calculateArrowHead();
    }

    void setSource(Block* block) { source = block; }
    void setDest(Block* block) { dest = block; }
};
