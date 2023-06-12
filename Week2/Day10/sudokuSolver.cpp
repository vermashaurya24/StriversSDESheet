#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
   bool isSafe(vector<vector<char>> &board, int row, int col, char ch)
   {
      for (int i = 0; i < 9; i++)
      {
         if (board[row][i] == ch)
            return false;
         if (board[i][col] == ch)
            return false;
         if (board[3 * (row / 3) + (i / 3)][3 * (col / 3) + (i % 3)] == ch)
            return false;
      }
      return true;
   }

   bool solve(vector<vector<char>> &board, int row, int col)
   {
      if (col == 9)
      {
         if (row == 8)
            return true;
         return solve(board, row + 1, 0);
      }
      if (board[row][col] != '.')
      {
         return solve(board, row, col + 1);
      }
      for (char i = '1'; i <= '9'; i++)
      {
         if (isSafe(board, row, col, i))
         {
            board[row][col] = i;
            if (solve(board, row, col + 1))
               return true;
            ;
            board[row][col] = '.';
         }
      }
      return false;
   }

   void solveSudoku(vector<vector<char>> &board)
   {
      solve(board, 0, 0);
   }
};

void main()
{
   vector<vector<char>> matrix;
   for (int i = 0; i < 9; i++)
   {
      for (int j = 0; j < 9; j++)
      {
         cin >> matrix[i][j];
      }
   }
   Solution solution = *new Solution();
   solution.solveSudoku(matrix);
}