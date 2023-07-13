//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    vector<int> toposort(int V, vector<int> adj[])
    {
        int indegree[V] = {0};
        queue<int> q;
        for (int i = 0; i < V; i++)
        {
            for (auto it : adj[i])
            {
                indegree[it]++;
            }
        }
        for (int i = 0; i < V; i++)
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
    string findOrder(string dict[], int N, int K)
    {
        // code here
        vector<int> adj[K];
        for (int i = 0; i < N - 1; i++)
        {
            string s1 = dict[i];
            string s2 = dict[i + 1];
            int len = min(s1.length(), s2.length());
            int t = 0;
            while (t < len)
            {
                if (s1[t] != s2[t])
                {
                    adj[s1[t] - 'a'].push_back(s2[t] - 'a');
                    break;
                }
                t++;
            }
        }
        vector<int> res = toposort(K, adj);
        string s = "";
        for (auto it : res)
        {
            char ch = (char)('a' + it);
            s = s + ch;
        }

        return s;
    }
};

//{ Driver Code Starts.
string order;
bool f(string a, string b)
{
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++)
    {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size())
        return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++)
            cin >> dict[i];

        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++)
            order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i])
                f = false;

        if (f)
            cout << 1;
        else
            cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends