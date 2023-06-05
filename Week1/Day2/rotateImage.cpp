#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
   void rotate(vector<vector<int>> &matrix)
   {
      int n = matrix.size();
      for (int i = 0; i < n / 2; i++)
      {
         swap(matrix[i], matrix[n - 1 - i]);
      }
      for (int i = 0; i < n; i++)
      {
         for (int j = 0; j < i; j++)
         {
            swap(matrix[i][j], matrix[j][i]);
         }
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
   solution.rotate(matrix);
}