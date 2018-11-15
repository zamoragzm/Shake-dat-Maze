# Shake-dat-Maze


Shake dat MAZE is a C++ program that solves any rectangular 2D maze in a .txt file by marking that same .txt file with the path that solves the maze. It also gives the rows and columns coordinates one should take, step by step, to solve the maze. 

The way this program finds the solution is by using a stack as data structure. The algorith is fairly simple, it pushes the location of the current standing, and it goes right, left, up or down and if it reach a dead end it pops all the locations until the last standing where it could have gone in another direction. While the program has a runtime of O(n^2) in the worst case it also has an average case of O(nlogn), so it is fairly similar regarding the runtime as the algorithm to solve mazes using Dijkstra's algorithm. Because the only way this algorithm would have a runtime of O(n^2) is if it chooses the wrong direction all the time, while this will be more common in smaller mazes this problems tends to decimate as the values get larger and it is when it really matters. The algorith was fully tested GDB to ensure the functionality. 

This program can be compiled with the current Makefile and executed with the Unix command line. The program needs to receive a maze in a text file, it can be one of the sample mazes in this repository or any other one that you may have, however it must follow the outline of the sample mazes. 



If you desire to know more about this project please let me know.
