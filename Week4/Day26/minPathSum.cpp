#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
   int minPathSum(vector<vector<int>> &grid)
   {
      int n = grid.size(), m = grid[0].size();
      for (int i = n - 1; i >= 0; i--)
      {
         for (int j = m - 1; j >= 0; j--)
         {
            if (i == n - 1 && j == m - 1)
               continue;
            int down = (i == n - 1) ? 1e9 : grid[i + 1][j];
            int right = (j == m - 1) ? 1e9 : grid[i][j + 1];
            grid[i][j] += min(down, right);
         }
      }
      return grid[0][0];
   }
};

void main()
{
   int n, m;
   cin >> n >> m;
   vector<vector<int>> v(n, vector<int>(m));
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < m; j++)
         cin >> v[i][j];
   }
   Solution solution = *new Solution();
   solution.minPathSum(v);
}