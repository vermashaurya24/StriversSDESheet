#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
   bool isPossible(vector<vector<int>> &matrix, int target, int n, int m)
   {
      int count = 0, total = n * m;
      for (int i = 0; i < n; i++)
      {
         for (int j = 0; j < m; j++)
         {
            if (matrix[i][j] <= target)
               count++;
         }
      }
      return count >= (total + 1) / 2;
   }

   int median(vector<vector<int>> &matrix, int R, int C)
   {
      // code here
      int low = 1, high = 2000, res;
      while (low <= high)
      {
         int mid = low + (high - low) / 2;
         if (isPossible(matrix, mid, R, C))
         {
            res = mid;
            high = mid - 1;
         }
         else
         {
            low = mid + 1;
         }
      }
      return res;
   }
};

void main()
{
   int n, m;
   cin >> n >> m;
   vector<vector<int>> v;
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < m; j++)
      {
         cin >> v[i][j];
      }
   }
   Solution solution = *new Solution();
   solution.median(v, n, m);
}