#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
   vector<vector<string>> res;

   bool isSafe(vector<string> &v, int row, int col)
   {
      int x = row, y = col, n = v.size();
      while (x >= 0)
      {
         if (v[x][col] == 'Q')
            return false;
         x--;
      }
      x = row;
      while (y >= 0)
      {
         if (v[row][y] == 'Q')
            return false;
         y--;
      }
      y = col;
      while (x >= 0 && y >= 0)
      {
         if (v[x][y] == 'Q')
            return false;
         x--;
         y--;
      }
      x = row;
      y = col;
      while (x >= 0 && y < n)
      {
         if (v[x][y] == 'Q')
            return false;
         x--;
         y++;
      }
      return true;
   }

   void solve(vector<string> &v, int row)
   {
      if (row == v.size())
      {
         res.push_back(v);
         return;
      }
      for (int i = 0; i < v.size(); i++)
      {
         if (isSafe(v, row, i))
         {
            v[row][i] = 'Q';
            solve(v, row + 1);
            v[row][i] = '.';
         }
      }
   }

   vector<vector<string>> solveNQueens(int n)
   {
      vector<string> v(n, string(n, '.'));
      solve(v, 0);
      return res;
   }
};

void main()
{
   int n;
   cin >> n;
   Solution solution = *new Solution();
   solution.solveNQueens(n);
}