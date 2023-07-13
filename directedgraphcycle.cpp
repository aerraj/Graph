//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  bool dfs(int node, vector<int> adj[],int vis[],int pathVis[])
  {
      vis[node]=1;
      pathVis[node]=1;
      for(auto it:adj[node])
      {
          if(!vis[it])
          {
              if(dfs(it,adj,vis,pathVis)==true)
              return true;
              
          }
          else if(pathVis[it]==1)
          {
              return true;
          }
      }
      pathVis[node]=0;
      return false;
  }
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        int vis[V]={0};
        int pathVis[V]={0};
        
        for(int i=0;i<V;i++)
        {
            if(vis[i]==0)
            {
                if(dfs(i,adj,vis,pathVis)==true)
                return true;
            }
        }
        return false;
    }
};
class Solution2
{
public:
    bool dfs(int node, vector<int> adj[], int vis[])
    {
        vis[node] = 2;
        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                if (dfs(it, adj, vis) == true)
                return true;
            }
            else if (vis[it] == 2)
            {
                return true;
            }
        }
        vis[node] = 1;
        return false;
    }
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[])
    {
        // code here
        int vis[V] = {0};

        for (int i = 0; i < V; i++)
        {
            if (vis[i] == 0)
            {
                if (dfs(i, adj, vis) == true)
                return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends

