#pragma once

#include "Canvas.h"

class Line;

class Block {
private:
	int width = 48, height = 48;
	int x, y, x_off, y_off;
	bool highlightIncomingNode = false, highlightOutgoingNode = false;

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
		cr->stroke();

		cr->save();
    	cr->set_line_width(1);
		if (highlightIncomingNode) {
			cr->set_source_rgba(1, 1, 0, 0.5);
			cr->rectangle(x - x_off, y + height/2 - y_off/2, x_off, y_off);
			cr->fill();
			cr->set_source_rgb(1, 1, 0);
		} cr->rectangle(x - x_off, y + height/2 - y_off/2, x_off, y_off);
		cr->stroke();
		cr->restore();

		cr->save();
    	cr->set_line_width(1);
		if (highlightOutgoingNode) {
			cr->set_source_rgba(1, 1, 0, 0.5);
			cr->rectangle(x + width, y + height/2 - y_off/2, x_off, y_off);
			cr->fill();
			cr->set_source_rgb(1, 1, 0);
		} cr->rectangle(x + width, y + height/2 - y_off/2, x_off, y_off);
		cr->stroke();
		cr->restore();
	}

	void translate(double new_x, double new_y) { x = new_x - width/2; y = new_y - height/2; }

	bool isIncomingNodeHovered(double mouse_x, double mouse_y) {
		int x1 = x - x_off;
		int y1 = y + (height - y_off) / 2;

		int x2 = x;
		int y2 = y + (height + y_off) / 2;

		if (mouse_x < x2 && mouse_x > x1 && mouse_y < y2 && mouse_y > y1) {
			return true;
		} return false;
	}

	bool isOutgoingNodeHovered(double mouse_x, double mouse_y) {
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

	int getIncomingNodeCenterX() { return x - x_off / 2; }
	int getIncomingNodeCenterY() { return y + height / 2; }

	int getOutgoingNodeCenterX() { return x + width + x_off / 2; }
	int getOutgoingNodeCenterY() { return y + height / 2; }

	void setOutgoing(Line *line) { next = line; }
	void setIncoming(Line* line) { prev = line; }

	void setHighlightIncomingNode(bool highlightIncoming) { highlightIncomingNode = highlightIncoming; }
	void setHighlightOutgoingNode(bool highlightOutgoing) { highlightOutgoingNode = highlightOutgoing; }
};
