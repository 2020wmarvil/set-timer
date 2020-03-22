#pragma once
class Block {
	private:
		Block* next;
		int x,y;
	public:
		Block(int x,int y) {
			this->x=x;
			this->y=y;
		}
		void connect(Block &other) {
			next=&other;
		}
		Block* getNext() {
			return next;
		}
		int getX() {return x;}
		int getY() {return y;}
};
