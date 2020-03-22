#pragma once

class Drawable {
public:
	virtual void draw(const Cairo::RefPtr<Cairo::Context>& cr) = 0;
	virtual void translate(double new_x, double new_y) = 0;
	virtual bool isClicked(double mouse_x, double mouse_y) = 0;
};
