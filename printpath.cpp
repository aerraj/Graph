//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> shortestPath(int n, int m, vector<vector<int>> &edges)
    {
        // Code here
        vector<int> ans;

        vector<vector<int>> adj[n + 1];
        for (int i = 0; i <m; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        
        priority_queue<pair<vector<int>, int>, vector<pair<vector<int>, int>>, greater<pair<vector<int>, int>>> pq;
        vector<int> dis(n + 1, INT_MAX);
        dis[1] = 0;
        vector<int> curr;
        curr.push_back(1);
        pq.push({curr, 0});
        int d = 0;
        while (!pq.empty())
        {
            auto it = pq.top();
            curr = it.first;
            int h = curr.size();
            int dist = it.second;
            pq.pop();
            for (auto it1 : adj[curr[h - 1]])
            {
                int ew = it1[1];
                int v = it1[0];

                if (ew + dist < dis[v])
                {
                    dis[v] = ew + dist;
                    curr.push_back(v);
                    if (v == n)
                    {
                        ans = curr;
                    }
                    else
                    {
                        pq.push({curr, dis[v]});
                    }
                    curr.pop_back();
                }
            }
        }
        
        if (dis[n] != INT_MAX)
            return ans;
        else
        {
            vector<int> res;
            res.push_back(-1);
            return res;
        }
    }
};

//{ Driver Code Starts.
int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i)
        {
            vector<int> temp;
            for (int j = 0; j < 3; ++j)
            {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res)
        {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends