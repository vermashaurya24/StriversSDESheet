#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
   int uniquePaths(int m, int n)
   {
      vector<vector<int>> grid(n, vector<int>(m, 0));
      for (int i = n - 1; i >= 0; i--)
      {
         for (int j = m - 1; j >= 0; j--)
         {
            if (i == n - 1 || j == m - 1)
               grid[i][j] = 1;
            else
               grid[i][j] = grid[i + 1][j] + grid[i][j + 1];
         }
      }
      return grid[0][0];
   }
};

void main()
{
   int m, n;
   cin >> m >> n;
   Solution solution = *new Solution();
   solution.uniquePaths(m, n);
}