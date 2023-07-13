#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector<int> g[N];
bool visited[N];
void dfs(int vertex)
{

    if (visited[vertex])
        return;
    // cout << vertex << endl;
    // Takes action on vertex after entering the vertex
    visited[vertex] = 1;
    for (int child : g[vertex])
    {
        cout<<vertex<<" "<<child<<endl;
        // Takes  action on child before entering the child node
        dfs(child);
        // Takes  action on child after entering the child node
    }
    // Takes action on vertex before exiting the vertex
}
int main()
{
    int n, m;
    n = 5;
    m = 7;
    // cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
dfs(0);

    // visited array size is no of nodes
    // visited array represents the number of nodes visited
    return 0;
}
