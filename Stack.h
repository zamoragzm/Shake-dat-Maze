

#ifndef _STACK_H_
#define _STACK_H_

#include "MazeLocation.h"


class Stack {

  public:
	
	Stack(int size);
	
	bool isEmpty() const;

	bool isFull() const;
   
	~Stack();
	
	void push(MazeLocation m);
	
	void pop();

	void printTop();

  MazeLocation getTop();

private:
   
    MazeLocation* data;
    int MAX_SIZE;
    int top;
};

#endif
