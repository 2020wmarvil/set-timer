#pragma once

#include "Drawable.h"
#include "Canvas.h"

class Block : public Drawable {
private:
	Block* next=nullptr;

	int width = 48, height = 48;
	int x, y;
public:
	Block(int x, int y) : x(x-width/2), y(y-height/2) {}

	void draw(const Cairo::RefPtr<Cairo::Context>& cr) {
		int x_off = width / 6; int y_off = height / 6;

		cr->save();
		cr->set_source_rgba(0.36, 0, .25, 0.5);
		cr->rectangle(x, y, width, height);
		cr->fill();
		cr->restore();

		cr->rectangle(x, y, width, height);
		cr->rectangle(x - x_off, y + height/2 - y_off/2, x_off, y_off);
		cr->rectangle(x + width, y + height/2 - y_off/2, x_off, y_off);

		cr->stroke();
	}

	void translate(double new_x, double new_y) {
		x = new_x - width/2; y = new_y - height/2;
	}

	bool isClicked(double mouse_x, double mouse_y) {
		return mouse_x < x+width && mouse_x > x && mouse_y < y+height && mouse_y > y;
	}

	void connect(Block &other) { next = &other; }
	void setNext(Block &other) { next = &other; }
	Block* getNext() { return next; }
};
