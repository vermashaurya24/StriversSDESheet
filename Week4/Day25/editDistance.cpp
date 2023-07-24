#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
   int t[501][501];
   int solve(string a, string b, int i, int j)
   {
      if (i < 0)
         return j + 1;
      if (j < 0)
         return i + 1;
      if (t[i][j] != -1)
         return t[i][j];
      if (a[i] == b[j])
         return t[i][j] = solve(a, b, i - 1, j - 1);
      int replace = 0, delt = 0, insert = 0;
      replace = solve(a, b, i - 1, j - 1);
      delt = solve(a, b, i - 1, j);
      insert = solve(a, b, i, j - 1);
      return t[i][j] = min({replace, delt, insert}) + 1;
   }

   int minDistance(string word1, string word2)
   {
      memset(t, -1, sizeof(t));
      return solve(word1, word2, word1.size() - 1, word2.size() - 1);
   }
};

void main()
{
   string s, t;
   cin >> s >> t;
   Solution solution = *new Solution();
   solution.minDistance(s, t);
}