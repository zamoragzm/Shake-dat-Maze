#include <iostream>
#include <fstream>
#include "Stack.h"
#include "Maze.h"

bool findPath(Stack& s, MazeLocation cur, Maze& m) {
  //Uncomment the cout if you desire every step of the map
bool done = false;
while(!done){
        if (m.isFinished(cur)) {
	    s.push(cur);
	    m.setChar(cur,'*');
            done = true;
            break;
        }

        if (m.isOpen(cur.rightOne())) {    // checks right
            s.push(cur);
            m.setChar(cur,'*');
            cur = cur.rightOne();
            //cout << m << endl;
            continue;
        }

        if (m.isOpen(cur.downOne())) {   // checks down
            s.push(cur);
            m.setChar(cur,'*');
            cur = cur.downOne();
            //cout << m << endl;
            continue;
        }

        if (m.isOpen(cur.leftOne())) {   // checks left
            s.push(cur);
            m.setChar(cur,'*');
            cur = cur.leftOne();
            //cout << m << endl;
            continue;
        }

        if (m.isOpen(cur.upOne())) {   // checks up
            s.push(cur);
            m.setChar(cur,'*');
            cur = cur.upOne();
            //cout << m << endl;
            continue;
        }

        // If we get, here, it means the path was a dead end
        if (!s.isEmpty()) {
            m.setChar(cur,':');
            cur = s.getTop();
            s.pop();
            //cout << m << endl;
            continue;
        }else{ //No solution
          m.setChar(cur,':');
          cout << m << endl;
          return false;
        }
}
cout << m << endl;
return true;
	}






int main(int argc, char* argv[]) {

	// Main maze program

	// Consumes the maze data file as a command line argument.
	if (argc < 2) {
		cerr << "ERROR" << endl << "usage: ./pa2 maze.txt" << endl;
		return 1;
	}

	ifstream inputFile(argv[1]);

	// Calls maze constructor linked to input file.
	Maze m(inputFile);
	// Creates a stack with enough space to hold every location in m
	Stack s(m.getSize());

	if (findPath(s, m.getStart(), m)) {
		cout << "Maze solved" << endl;
	} else {
		cout << "Ahhh, couldn't get out!" << endl;
	}

	// Stack should contain only locations on path to finish (not dead-ends)
	// or be empty if no solution was found (as everything was popped off).
	while(!s.isEmpty()) {
		s.printTop();
		s.pop();
	}

}
