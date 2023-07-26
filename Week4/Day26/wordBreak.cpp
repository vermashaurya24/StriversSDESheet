#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
   int t[301];
   bool solve(string s, int index, unordered_set<string> &st)
   {
      if (index >= s.size())
         return 1;
      if (t[index] != -1)
         return t[index];
      string cur = "";
      for (int i = index; i < s.size(); i++)
      {
         cur += s[i];
         if (st.count(cur) && solve(s, i + 1, st))
            return t[index] = true;
      }
      return t[index] = false;
   }

   bool wordBreak(string s, vector<string> &wordDict)
   {
      memset(t, -1, sizeof(t));
      unordered_set<string> st(wordDict.begin(), wordDict.end());
      return solve(s, 0, st);
   }
};

void main()
{
   string s;
   int n;
   vector<string> wordDict;
   cin >> s >> n;
   for (int i = 0; i < n; i++)
      cin >> wordDict[i];
   Solution solution = *new Solution();
   solution.wordBreak(s, wordDict);
}