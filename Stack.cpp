
#include "Stack.h"
#include <iostream>
using namespace std;


Stack::Stack(int size) {
	top = -1;
	MAX_SIZE = size;
	if(size == 0){
		data = 0;
	}
    else{
			data = new MazeLocation[MAX_SIZE];
		}
}

bool Stack::isEmpty() const {
		if(top + 1 == 0){
			return true;
		}else{
			return false;
		}
}

bool Stack::isFull() const {
	if(top == MAX_SIZE - 1){
		return true;
	}else{
		return false;
	}
}

Stack::~Stack() {
	if(data != 0){
		delete [] data;
	}
}

void Stack::push(MazeLocation m) {
	 if(isFull())
	 {
			 return;
	 }
	 else
	 {
			 top++;
			 data[top]= m;
	 }
}

void Stack::pop() {
	if(isEmpty()){
		return;
	}else{
		top--;
	}
}

void Stack::printTop() {
	cout << data[top];
}

MazeLocation Stack::getTop() {
	return data[top];
}
