#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector<int> g[N];
bool visited[N];
void dfs(int i, int j, int initialColor, int newColor, vector<vector<int>> &image)
{
if(i<0 || j<0 || i>=image.size() || j>=image[0].size() || image[i][j]!=initialColor)
        return;
image[i][j] = newColor;

    dfs(i + 1, j, initialColor, newColor, image);
    dfs(i - 1, j, initialColor, newColor, image);
    dfs(i, j + 1, initialColor, newColor, image);
    dfs(i, j - 1, initialColor, newColor, image);
}
vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color) 
{
    int initialColor=image[sr][sc];
if(initialColor!=newColor)
    dfs(sr,sc,initialColor,newColor,image);
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
