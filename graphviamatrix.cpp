#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; // number of nodes in the graph
    int m; // number of EDGES in the graph
    cin >> n >> m;
    int graph[n + 1][m + 1];
    for (int i = 0; i < m; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1][v2] = 1;
        graph[v2][v1] = 1;
    }
    // for weighted graphs
    for (int i = 0; i < m; i++)
    {
        int v1, v2, wt;
        cin >> v1 >> v2 >> wt;
        graph[v1][v2] = wt;
        graph[v2][v1] = wt;
    }
    // O(N^2)-space complexity
    // N=10^5
    return 0;
}
