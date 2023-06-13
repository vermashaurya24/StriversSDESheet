#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
   typedef pair<int, pair<int, int>> ppi;

   vector<int> mergeKArrays(vector<vector<int>> arr, int k)
   {
      // code here
      priority_queue<ppi, vector<ppi>, greater<ppi>> pq;
      for (int i = 0; i < k; i++)
      {
         pq.push({arr[i][0], {i, 0}});
      }
      vector<int> ans;
      while (!pq.empty())
      {
         ppi curr = pq.top();
         pq.pop();
         ans.push_back(curr.first);
         int list = curr.second.first;
         int pos = curr.second.second;
         if (pos + 1 < k)
         {
            pq.push({arr[list][pos + 1], {list, pos + 1}});
         }
      }
      return ans;
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
   solution.mergeKArrays(matrix, row);
}