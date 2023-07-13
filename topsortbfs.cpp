#include <bits/stdc++.h>
using namespace std;
vector<int>topo(int V,vector<int>adj[])
{
    int indegree[V] = {0};
    queue<int> q;
    for (int i = 0; i <V; i++)
    {
        for (auto it : adj[i])
        {
            indegree[it]++;
        }
    }
    for (int i = 0; i <V; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }
    vector<int> res;
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        res.push_back(x);
        for (auto it : adj[x])
        {
            indegree[it]--;
            if (indegree[it] == 0)
                q.push(it);
        }
    }
    return res;
}
int main() {
	
	int n,m;
    cin>>n>>m;
    vector<int>adj[n];
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
    }
    vector<int>res=topo(n,adj);

   for(auto it:res)
   cout<<it<<" ";

    

}