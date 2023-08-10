#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
   // Function to find if there is a celebrity in the party or not.
   int celebrity(vector<vector<int>> &grid, int n)
   {
      // code here
      int celeb = 0;
      for (int j = 1; j < n; j++)
      {
         if (grid[celeb][j])
            celeb = j;
      }
      for (int i = 0; i < n; i++)
      {
         if (i != celeb && (grid[celeb][i] || !grid[i][celeb]))
            return -1;
      }
      return celeb;
   }
};

void main()
{
   int n;
   cin >> n;
   vector<vector<int>> grid(n, vector<int>(n));
   for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
         cin >> grid[i][j];

   Solution solution = *new Solution();
   solution.celebrity(grid, n);
}