#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
   vector<string> res;

   void solve(vector<vector<int>> &mat, int row, int col, int n, string &path)
   {
      if (row < 0 || col < 0 || row >= n || col >= n)
         return;
      if (!mat[row][col])
         return;
      if (row == n - 1 && col == n - 1)
      {
         if (mat[row][col])
         {
            res.push_back(path);
         }
         return;
      }
      mat[row][col] = 0;
      path += 'L';
      solve(mat, row, col - 1, n, path);
      path.pop_back();
      path += 'R';
      solve(mat, row, col + 1, n, path);
      path.pop_back();
      path += 'U';
      solve(mat, row - 1, col, n, path);
      path.pop_back();
      path += 'D';
      solve(mat, row + 1, col, n, path);
      path.pop_back();
      mat[row][col] = 1;
   }

   vector<string> findPath(vector<vector<int>> &mat, int n)
   {
      // Your code goes here
      string path = "";
      solve(mat, 0, 0, n, path);
      return res;
   }
};

void main()
{
   int row;
   cin >> row;
   vector<vector<int>> matrix(row, vector<int>(row));
   for (int i = 0; i < row; i++)
   {
      for (int j = 0; j < row; j++)
      {
         cin >> matrix[i][j];
      }
   }
   Solution solution = *new Solution();
   solution.findPath(matrix, row);
}