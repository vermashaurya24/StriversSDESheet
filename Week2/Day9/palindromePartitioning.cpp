#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
   vector<vector<string>> res;

   bool isPal(string s)
   {
      int i = 0, n = s.size(), j = n - 1;
      while (i < j)
      {
         if (s[i] != s[j])
            return false;
         i++;
         j--;
      }
      return true;
   }

   void solve(string s, int index, vector<string> &v)
   {
      if (index >= s.size())
      {
         res.push_back(v);
         return;
      }
      string cur = "";
      for (int i = index; i < s.size(); i++)
      {
         cur += s[i];
         if (isPal(cur))
         {
            v.push_back(cur);
            solve(s, i + 1, v);
            v.pop_back();
         }
      }
   }

   vector<vector<string>> partition(string s)
   {
      vector<string> v;
      solve(s, 0, v);
      return res;
   }
};

void main()
{
   string s;
   cin >> s;
   Solution solution = *new Solution();
   solution.partition(s);
}