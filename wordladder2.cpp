//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string> &wordlist)
    {
        // code here
        queue<vector<string>> q;
        q.push({beginWord});
        unordered_set<string> st(wordlist.begin(), wordlist.end());
        vector<string> usedOnLevel;
        usedOnLevel.push_back(beginWord);
        int level = 0;
        vector<vector<string>> res;
        while (!q.empty())
        {
            vector<string> v = q.front();
            // erase all words that have been used
            // at previous level to transform
            if (v.size() > level)
            {
                level++;
                for (auto it : usedOnLevel)
                {
                    st.erase(it);
                }
            }
            string word = v.back();
            q.pop();
            if (word == endWord)
            {
                if (res.size() == 0)
                {
                    res.push_back(v);
                }
                else if (v.size() == res[0].size())
                {
                    res.push_back(v);
                }
            }

            for (int i = 0; i < word.size(); i++)
            {
                char original = word[i];
                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    word[i] = ch;
                    if (st.find(word) != st.end())
                    {

                        v.push_back(word);
                        usedOnLevel.push_back(word);
                        q.push(v);
                        v.pop_back();
                    }
                }
                word[i] = original;
            }
        }
        return res;
    }
};

//{ Driver Code Starts.

bool comp(vector<string> a, vector<string> b)
{
    string x = "", y = "";
    for (string i : a)
        x += i;
    for (string i : b)
        y += i;

    return x < y;
}

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        vector<string> wordList(n);
        for (int i = 0; i < n; i++)
            cin >> wordList[i];
        string startWord, targetWord;
        cin >> startWord >> targetWord;
        Solution obj;
        vector<vector<string>> ans = obj.findSequences(startWord, targetWord, wordList);
        if (ans.size() == 0)
            cout << -1 << endl;
        else
        {
            sort(ans.begin(), ans.end(), comp);
            for (int i = 0; i < ans.size(); i++)
            {
                for (int j = 0; j < ans[i].size(); j++)
                {
                    cout << ans[i][j] << " ";
                }
                cout << endl;
            }
        }
    }
    return 0;
}
// } Driver Code Ends