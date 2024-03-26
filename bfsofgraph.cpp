#include <bits/stdc++.h>
#define int long long int
using namespace std;
vector<int> bfsOfGraph(int V, vector<int> adj[])
{
    int vis[V] = {0};
    vis[0] = 1;
    queue<int> q;
    // push the initial starting node
    q.push(0);
    vector<int> bfs;
    // iterate till the queue is empty
    while (!q.empty())
    {

        int node = q.front();
        q.pop();
        bfs.push_back(node);
        // traverse for all its neighbours
        for (auto it : adj[node])
        {
            // if the neighbour has previously not been visited,
            // store in Q and mark as visited
            if (!vis[it])
            {
                vis[it] = 1;
                q.push(it);
            }
        }
    }
    return bfs;
}
int32_t main()
{
    int V,E;
    cin >> V >> E;
    vector<int>adj[V+1];
    for(int i=0;i<E;i++)
    {
        int x,y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<int>bfs=bfsOfGraph(V,adj);
    for(auto it:bfs)
    {
        cout<<it<<" ";
    }
return 0;
}
