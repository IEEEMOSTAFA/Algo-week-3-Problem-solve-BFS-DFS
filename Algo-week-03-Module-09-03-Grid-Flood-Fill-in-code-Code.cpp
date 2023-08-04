/*
//CSES problem: Counting Room:1192/Graph Algorithm Topics:
You are given a map of a building, and your task is to count the number of its rooms. The size of the map is n×m
 squares, and each square is either floor or wall. You can walk left, right, up, and down through the floor squares.

Input

The first input line has two integers n
 and m
: the height and width of the map.

Then there are n
 lines of m
 characters describing the map. Each character is either . (floor) or # (wall).

Output

Print one integer: the number of rooms.

Constraints
1≤n,m≤1000

Example

Input:
5 8
########
#..#...#
####.#.#
#..#...#
########

Output:
3
//for understanding:
########
#$$#***#
####*#*#
#%%#***#
########

$ * % = 3 ta sign = 3 ta room= so output ->3 ta:
 while there exists  an empty cell
 
-> find an empty unvisited cell
-> run bfs() from that cell
->
*/