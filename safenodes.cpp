//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    vector<int> eventualSafeNodes(int V, vector<int> adjinv[])
    {
        // code here
        vector<int> adj[V];
        int indegree[V] = {0};
        for (int i = 0; i < V; i++)
        {
            for (auto it : adjinv[i])
            {
                adj[it].push_back(i);
                indegree[i]++;
            }
        }
        queue<int> q;
        for (int i = 0; i < V; i++)
        {
            if (indegree[i] == 0)
                q.push(i);
        }
        vector<int> safe;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            safe.push_back(node);
            for (auto it : adj[node])
            {
                indegree[it]--;
                if (indegree[it] == 0)
                    q.push(it);
            }
        }
        sort(safe.begin(), safe.end());
        return safe;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends