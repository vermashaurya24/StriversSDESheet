#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
   vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
   {
      if (image[sr][sc] == color)
         return image;
      int old = image[sr][sc], n = image.size(), m = image[0].size();
      queue<pair<int, int>> q;
      q.push({sr, sc});
      int dx[] = {0, -1, 0, +1};
      int dy[] = {-1, 0, +1, 0};
      image[sr][sc] = color;
      while (!q.empty())
      {
         auto f = q.front();
         q.pop();
         int x = f.first, y = f.second;
         for (int i = 0; i < 4; i++)
         {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && image[nx][ny] == old)
            {
               image[nx][ny] = color;
               q.push({nx, ny});
            }
         }
      }
      return image;
   }
};

void main()
{
   int n, m, sr, sc, color;
   cin >> n >> m >> sr >> sc >> color;
   vector<vector<int>> res(n, vector<int>(m));
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < m; j++)
      {
         cin >> res[i][j];
      }
   }
   Solution solution = *new Solution();
   solution.floodFill(res, sr, sc, color);
}