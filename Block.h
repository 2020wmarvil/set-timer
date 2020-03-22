#pragma once

#include "Drawable.h"
#include "Canvas.h"

class Block : public Drawable {
private:
	Block* next=nullptr;

	int width = 48, height = 48;
	int x, y, x2, y2;
public:
	Block(int x, int y) : x(x-width/2), y(y-height/2) {}

	void draw(const Cairo::RefPtr<Cairo::Context>& cr) {
		int x_off = width / 6; int y_off = height / 6;

		cr->rectangle(x, y, width, height);
		cr->rectangle(x - x_off, y + height/2 - y_off/2, x_off, y_off);
		cr->rectangle(x + width, y + height/2 - y_off/2, x_off, y_off);

		cr->stroke();
	}

	void connect(Block &other) { next= &other; }
	void setNext(Block &other) { next= &other; }
	Block* getNext() { return next; }
};
