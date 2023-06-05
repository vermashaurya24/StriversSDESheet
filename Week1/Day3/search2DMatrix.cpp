#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
   bool searchMatrix(vector<vector<int>> &matrix, int target)
   {
      // if we mark individual cell and stretch a matrix into a straight line, we can apply basic binary search to find element. logically identifying the location of mid in matrix by mid/m,mid%m
      int n = matrix.size(), m = matrix[0].size(), low = 0, high = (n * m) - 1;
      while (low <= high)
      {
         int mid = low + (high - low) / 2;
         int x = mid / m, y = mid % m;
         if (matrix[x][y] == target)
            return true;
         else if (matrix[x][y] > target)
         {
            high = mid - 1;
         }
         else
         {
            low = mid + 1;
         }
      }
      return false;
   }
};

void main()
{
   int row, col, target;
   cin >> row >> col >> target;
   vector<vector<int>> matrix(row, vector<int>(col));
   for (int i = 0; i < row; i++)
   {
      for (int j = 0; j < col; j++)
      {
         cin >> matrix[i][j];
      }
   }
   Solution solution = *new Solution();
   solution.searchMatrix(matrix, target);
}