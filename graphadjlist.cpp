#include <bits/stdc++.h>
using namespace std;
const int N= 1e5+10;
vector<pair<int,int>>graph[N];
int main()
{
    //space complexity O(V+E)
    int v,e;
    cin >> v >> e;
    //v=no of vertices or nodes
    //e=graph edges
    for(int i=0;i<e;i++)
    {
        int v1,v2,wt;
        cin>>v1>>v2>>wt;
        graph[v1].push_back({v2,wt});
        graph[v2].push_back({v1,wt});

    }
    int i;
    cin>>i;
    int j;
    cin>>j;
    for(pair <int,int> child : graph[i])
    {
if(child.first ==j)
{
    //connected
    cout<<child.second<<endl;
}
    }

return 0;
}
