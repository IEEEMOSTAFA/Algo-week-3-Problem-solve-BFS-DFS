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
#include<bits/stdc++.h>
using namespace std;
const int N = 2002;

int maze[N][N], visited[N][N];

int n, m;

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};


bool is_inside(pair<int, int>coord) {
    int x = coord.first;
    int y = coord.second;

    if(x >= 0 && x < n && y >= 0 &&  y < m) {
        return true;
    }
    return false;
}

bool is_safe(pair<int, int>coord)//ata dara check korbo cholar pote # ace kina
 {
    int x = coord.first;
    int y = coord.second;
    if(maze[x][y] == -1) {
        return false;
    }
    return true;
}

void bfs(pair<int, int>src) {

    queue< pair<int, int> >q;
    visited[src.first][src.second] = 1;
    

    q.push(src);

    while(!q.empty()) {
        pair<int,int>head = q.front();
        q.pop();
        int x = head.first;
        int y = head.second;
        //x and y ke coordinate bibacona korbo
        for(int i = 0 ; i < 4 ; i++) {
            int new_x = x + dx[i];
            int new_y = y + dy[i];

            pair<int,int>adj_node = {new_x, new_y};
                                                                                              
            if(is_inside(adj_node) && is_safe(adj_node) && visited[new_x][new_y] == 0) {
                visited[new_x][new_y] = 1;
                
                q.push(adj_node);
            }
        }
    }
}
pair<int,int>find_unvisited()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0 ;j<m;j++)
        {
            if(visited[i][j] == 0 && maze[i][j] == 0)
            {
             return {i,j};
            }
        }
    }
    //  jodi kico na pai sei ketre invalid cordinate print korbo {-1,-1}
    return {-1,-1};
}

int main() {

    cin >> n >> m;

    
    

    for(int i = 0 ; i < n  ; i++) {
        string input;
        cin>>input;
        for(int j = 0 ; j < m ; j++) {
            if(input[j] == '#') {
                maze[i][j] = -1;
            }
            
        }
    }

    // for(int i = 0 ; i < n ; i++) {
    //     for(int j = 0; j < m ; j++) {
    //         cout<<maze[i][j]<<"\t";
    //     }
    //     cout<<endl;
    // }
    // cout<<endl;

   // while(1) or while (true) dara bojai loop ta infinite time ber cholbe
   int room_cnt = 0;

   while (true)
   {
    pair<int,int >unvisited_pos =  find_unvisited();
    if(unvisited_pos == pair<int,int>(-1, -1)){

        break;
    }
    bfs(unvisited_pos);
    room_cnt++;

   }
   cout<<"Output -> "<<room_cnt<<endl;
   
   

    


    return 0;
}
//code ta online juje submit kore dekbo submit kore kina::