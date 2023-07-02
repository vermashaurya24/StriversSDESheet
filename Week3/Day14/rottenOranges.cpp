#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
   int orangesRotting(vector<vector<int>> &grid)
   {
      int n = grid.size(), m = grid[0].size();
      queue<pair<int, int>> q;
      int fresh = 0;
      for (int i = 0; i < n; i++)
      {
         for (int j = 0; j < m; j++)
         {
            if (grid[i][j] == 2)
               q.push({i, j});
            fresh += (grid[i][j] == 1);
         }
      }
      if (fresh == 0)
         return 0;
      int time = 0;
      int dx[] = {0, 1, 0, -1};
      int dy[] = {1, 0, -1, 0};
      while (!q.empty())
      {
         int sz = q.size();
         while (sz--)
         {
            auto front = q.front();
            q.pop();
            int x = front.first, y = front.second;
            for (int i = 0; i < 4; i++)
            {
               int nx = x + dx[i], ny = y + dy[i];
               if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == 1)
               {
                  grid[nx][ny] = 2;
                  q.push({nx, ny});
                  fresh--;
               }
            }
         }
         time++;
      }
      return (!fresh) ? time - 1 : -1;
   }
};

void main()
{
   int row, col;
   cin >> row >> col;
   vector<vector<int>> matrix(row, vector<int>(row));
   for (int i = 0; i < row; i++)
   {
      for (int j = 0; j < col; j++)
      {
         cin >> matrix[i][j];
      }
   }
   Solution solution = *new Solution();
   solution.orangesRotting(matrix);
}