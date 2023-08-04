/*
Byteland has n
 cities and m
 flight connections. Your task is to design a round trip that begins in a city, goes through one or more other cities, and finally returns to the starting city. Every intermediate city on the route has to be distinct.

Input

The first input line has two integers n
 and m
: the number of cities and flights. The cities are numbered 1,2,…,n
.

Then, there are m
 lines describing the flights. Each line has two integers a
 and b
: there is a flight connection from city a
 to city b
. All connections are one-way flights from a city to another city.

Output

First print an integer k
: the number of cities on the route. Then print k
 cities in the order they will be visited. You can print any valid solution.

If there are no solutions, print "IMPOSSIBLE".

Constraints
1≤n≤105

1≤m≤2⋅105

1≤a,b≤n

Example

Input:
4 5
1 3
2 1
2 4
3 2
3 4

Output:
4
2 1 3 2
//https://cses.fi/problemset/task/1678
 -> for understad
 intput:
 4 4
 1 3
 2 1
 2 4
 3 4
 
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 2e5;
vector<int>adj_list[N];
int visited[N];

bool detect_cycle(int node)                    //bfs==detect_cycle
{
    visited[node] = 1;
    for(int adj_node: adj_list[node])
    {
        /*
         -visited[adj_node] == 0  -> unexplored node  |apply dfs
         -visited[adj_node] == 1  -> paused node      | cycle detected
         -visited[adj_node] == 2  -> done node        | continue
         
        */
       if(visited[adj_node] == 0 ) 
       {
         bool got_cycle = detect_cycle(adj_node);
         if(got_cycle)
         {
            return true;
         }
       }
       else if(visited[adj_node] == 1)
       {
        return true;
       }
    }
    visited[node] = 2;
    //jodi sob golu loop gore jai tobe bojbo graph a ar kono node nei | so return false print korbo
    return false;
}

int main()
{
    int n,m;
    cin>>n>>m;

for(int i = 0;i<m;i++)
{
    int u,v;
    cin>>u>>v;
    // u->v   er modde directed edge ace----
    adj_list[u].push_back(v);

}
bool cycle_exists = false;
for(int i=0;i<=n;i++)
{
    if(visited[i] == 0)
    {
     bool got_cycle = detect_cycle(i);
      if(got_cycle)
      {
       cycle_exists = true;
       break;
      }
    }
}

if(cycle_exists )
{
    cout<<"Cycle Exists "<<endl;

}
else
{
    cout<<" No Cycle "<<endl;
}
}