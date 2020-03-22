#pragma once
class Block {
	private:
		Block* next=nullptr;
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
		void setNext(Block &other) {next=&other;}
		int getX() {return x;}
		int getY() {return y;}
};
