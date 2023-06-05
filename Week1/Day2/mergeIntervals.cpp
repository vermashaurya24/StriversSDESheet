#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
   vector<vector<int>> merge(vector<vector<int>> &intervals)
   {
      sort(intervals.begin(), intervals.end());
      vector<int> curInt = intervals[0];
      vector<vector<int>> res;
      for (auto &interval : intervals)
      {
         if (interval[0] > curInt[1])
         {
            res.push_back(curInt);
            curInt = interval;
         }
         else
         {
            curInt[1] = max(curInt[1], interval[1]);
         }
      }
      res.push_back(curInt);
      return res;
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
   solution.merge(matrix);
}