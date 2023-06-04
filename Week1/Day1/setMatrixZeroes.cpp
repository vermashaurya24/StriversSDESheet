#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
   void setZeroes(vector<vector<int>> &matrix)
   {
      bool rowzero = false, colzero = false;
      int n = matrix.size(), m = matrix[0].size();

      // checking if we need to convert respective zero row/col to zero
      for (int i = 0; i < n; i++)
         if (!matrix[i][0])
            rowzero = true;
      for (int j = 0; j < m; j++)
         if (!matrix[0][j])
            colzero = true;

      // using the 0th row and 0th column to mark the indices that need to be converted
      for (int i = 1; i < n; i++)
      {
         for (int j = 1; j < m; j++)
         {
            if (!matrix[i][j])
               matrix[i][0] = 0, matrix[0][j] = 0;
         }
      }

      // performing the actual convertion for matrix from row[1..n] and col[1..m]
      for (int i = 1; i < n; i++)
      {
         for (int j = 1; j < m; j++)
         {
            if (!matrix[i][0] || !matrix[0][j])
               matrix[i][j] = 0;
         }
      }

      // if respective 0th row/col need to be converted, we do it now
      if (rowzero || colzero)
      {
         if (rowzero)
            for (int i = 0; i < n; i++)
               matrix[i][0] = 0;
         if (colzero)
            for (int j = 0; j < m; j++)
               matrix[0][j] = 0;
      }
   }
};

void main()
{
   int row, col;
   cin >> row >> col;
   vector<vector<int>> matrix(row, vector<int>(col));
   for (int i = 0; i < row; i++)
   {
      for (int j = 0; j < col; j++)
      {
         cin >> matrix[i][j];
      }
   }
   Solution solution = *new Solution();
   solution.setZeroes(matrix);
}