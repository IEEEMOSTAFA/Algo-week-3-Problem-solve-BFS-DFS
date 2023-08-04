/*
There are n
 pupils in Uolevi's class, and m
 friendships between them. Your task is to divide the pupils into two teams in such a way that no two pupils in a team are friends. You can freely choose the sizes of the teams.

Input

The first input line has two integers n
 and m
: the number of pupils and friendships. The pupils are numbered 1,2,…,n
.

Then, there are m
 lines describing the friendships. Each line has two integers a
 and b
: pupils a
 and b
 are friends.

Every friendship is between two different pupils. You can assume that there is at most one friendship between any two pupils.

Output

Print an example of how to build the teams. For each pupil, print "1" or "2" depending on to which team the pupil will be assigned. You can print any valid team.

If there are no solutions, print "IMPOSSIBLE".

Constraints
1≤n≤105

1≤m≤2⋅105

1≤a,b≤n

Example

Input:
5 3
1 2
1 3
4 5

Output:
1 2 2 1 2

(1)  (2)
1---2
|
3
(2)


(1)  (2)
4---5
for understand:
thats not bicoloarable--

5 4
1 2
1 3
2 3
4 5


*/
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
int visited[N];
int color[N];

vector<int>adj_list[N];
bool dfs(int node)
{
    // cout<<node<<endl;
    visited[node] = 1;

    for(int adj_node:adj_list[node])
    {
        if(visited[adj_node]== 0)
        {
            //assign different color to adj_node
            if(color[node] == 1) color[adj_node] = 2;
            else color[adj_node] = 1;
            
           bool is_bicolorable =  dfs(adj_node);
           if(! is_bicolorable)
           {
            return false;
           }
        }
        else
        {
           //check if color is same or different
         if(color[node] == color[adj_node])
         {
            return false;
         }

        }
    }
    return true;
}
/*
 0------1----2----3
        |    |
        |    |
        5----4
 number of node->6
 number of edges->6
 list of adj nodes ->

6 6

 0 1  
 2 3
 1 5
 2 4
 5 4
 1 2

output->0 1 5 4 2 3      
*/
int main()
{
int nodes ,edges;
cin>>nodes>>edges;

for(int i = 0;i<edges;i++)
{
    int u,v;
    cin>>u>>v;
    adj_list[u].push_back(v);
    adj_list[v].push_back(u);

}

 bool is_bicolorable = true;  
for(int i=1;i<= nodes;i++)
{
    if(visited[i] == 0)
    {
        color[i] = 1;// atar mane je node ta protom a pabo sei node er colour 1 dore nici______
  
       bool ok = dfs(i);
       if(!ok)
       {
        is_bicolorable = false;
        break;
       }
    }
}
if(!is_bicolorable)
{
    cout<<"IMPOSSIBLE"<<endl;
}
else
{
    for(int i=1;i<= nodes;i++)
    {
        cout<<color[i]<<" ";
    }
    cout<<endl;
}
return 0;
}