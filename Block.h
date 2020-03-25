#pragma once

#include "Canvas.h"

class Line;

class Block {
private:
	int width = 48, height = 48;
	int x, y, x_off, y_off;

public:
	Line *next = nullptr, *prev = nullptr;

	Block(int x, int y) : x(x-width/2), y(y-height/2), x_off(width / 6), y_off(height / 6) {}

	void draw(const Cairo::RefPtr<Cairo::Context>& cr) {
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

	void translate(double new_x, double new_y) { x = new_x - width/2; y = new_y - height/2; }

	bool isIncomingConnectionHovered(double mouse_x, double mouse_y) {
		int x1 = x - x_off;
		int y1 = y + (height - y_off) / 2;

		int x2 = x;
		int y2 = y + (height + y_off) / 2;

		if (mouse_x < x2 && mouse_x > x1 && mouse_y < y2 && mouse_y > y1) {
			return true;
		} return false;
	}

	bool isOutgoingConnectionHovered(double mouse_x, double mouse_y) {
		int x1 = x + width;
		int y1 = y + (height - y_off) / 2;

		int x2 = x + width + x_off;
		int y2 = y + (height + y_off) / 2;

		if (mouse_x < x2 && mouse_x > x1 && mouse_y < y2 && mouse_y > y1) {
			return true;
		} return false;
	}

	bool isClicked(double mouse_x, double mouse_y) {
		return mouse_x < x+width && mouse_x > x && mouse_y < y+height && mouse_y > y;
	}

	void setOutgoing(Line *line) { next = line; }
	void setIncoming(Line* line) { prev = line; }
};
