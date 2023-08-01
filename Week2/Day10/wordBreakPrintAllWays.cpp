#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
   vector<string> res;

   void solve(string s, int idx, string str, unordered_set<string> &st)
   {
      if (idx >= s.size())
      {
         res.push_back(str.substr(1));
         return;
      }
      string temp = "";
      for (int i = idx; i < s.size(); i++)
      {
         temp += s[i];
         if (st.count(temp))
         {
            solve(s, i + 1, str + ' ' + temp, st);
         }
      }
   }

   vector<string> wordBreak(int n, vector<string> &dict, string s)
   {
      // code here
      unordered_set<string> st(dict.begin(), dict.end());
      string str = "";
      solve(s, 0, str, st);
      return res;
   }
};

void main()
{
   int n;
   cin >> n;
   string s;
   cin >> s;
   vector<string> res(n);
   for (int i = 0; i < n; i++)
      cin >> res[i];

   Solution solution = *new Solution();
   solution.wordBreak(n, res, s);
}