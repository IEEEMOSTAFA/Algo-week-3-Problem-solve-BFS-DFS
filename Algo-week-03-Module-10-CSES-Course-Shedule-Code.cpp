/*
//https://cses.fi/problemset/task/1679

You have to complete n
 courses. There are m
 requirements of the form "course a
 has to be completed before course b
". Your task is to find an order in which you can complete the courses.

Input

The first input line has two integers n
 and m
: the number of courses and requirements. The courses are numbered 1,2,…,n
.

After this, there are m
 lines describing the requirements. Each line has two integers a
 and b
: course a
 has to be completed before course b
.

Output

Print an order in which you can complete the courses. You can print any valid order that includes all the courses.

If there are no solutions, print "IMPOSSIBLE".

Constraints
1≤n≤105

1≤m≤2⋅105

1≤a,b≤n

Example

Input:
5 3
1 2
3 1
4 5

Output:
3 4 1 5 2

*/
#include<bits/stdc++.h>
using namespace std;
const int N = 2e5;
vector<int>adj_list[N];
int visited[N];
stack<int>node_stack;


    void dfs(int node)
    {
        visited[node] = 1;
        for(int adj_node :adj_list[node])

        {
            if(visited[adj_node] == 0)
            {
                dfs(adj_node);
            }
        }
        node_stack.push(node);
    }

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i = 0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj_list[u].push_back(v);

    }
    for(int i=1;i<=n;i++)
    {
        if(visited[i] == 0)
        {
            dfs(i);
        }
    }
    while (! node_stack.empty())
    {
        cout<<node_stack.top()<<" ";
        node_stack.pop();
    }
    cout<<endl;
    return 0;
    
}