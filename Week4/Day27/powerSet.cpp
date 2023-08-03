#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
public:
   vector<string> res;

   void solve(string s, int index, string &cur)
   {
      if (index >= s.size())
      {
         if (!cur.empty())
            res.push_back(cur);
         return;
      }
      cur += s[index];
      solve(s, index + 1, cur);
      cur.pop_back();
      solve(s, index + 1, cur);
   }

   vector<string> AllPossibleStrings(string s)
   {
      // Code here
      string cur = "";
      solve(s, 0, cur);
      sort(res.begin(), res.end());
      return res;
   }
};

void main()
{
   string s;
   cin >> s;
   Solution solution = *new Solution();
   solution.AllPossibleStrings(s);
}