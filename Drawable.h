#pragma once

class Drawable {
public:
	virtual void draw(const Cairo::RefPtr<Cairo::Context>& cr) = 0;
};
