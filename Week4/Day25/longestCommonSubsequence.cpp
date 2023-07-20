#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
   int longestCommonSubsequence(string s, string t)
   {
      int n = s.size(), m = t.size();
      vector<vector<int>> dp(n + 1, vector<int>(m + 1));
      for (int i = 0; i < n + 1; i++)
      {
         for (int j = 0; j < m + 1; j++)
         {
            if (i == 0 || j == 0)
               continue;
            else if (s[i - 1] == t[j - 1])
               dp[i][j] = dp[i - 1][j - 1] + 1;
            else
               dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
         }
      }
      return dp[n][m];
   }
};

void main()
{
   string s, t;
   cin >> s >> t;
   Solution solution = *new Solution();
   solution.longestCommonSubsequence(s, t);
}