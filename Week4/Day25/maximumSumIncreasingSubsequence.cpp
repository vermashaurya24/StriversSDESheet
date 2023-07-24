#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
   // Function to return max value that can be put in knapsack of capacity W.
   int t[1001][1001];
   int solve(vector<int> &arr, int n, int previdx, int curidx)
   {
      if (curidx == n)
      {
         return 0;
      }
      if (previdx != -1 && t[previdx][curidx] != -1)
         return t[previdx][curidx];
      int take = 0, nottake = 0;
      if (previdx != -1 && arr[previdx] < arr[curidx])
      {
         take = arr[curidx] + solve(arr, n, curidx, curidx + 1);
      }
      else if (previdx == -1)
      {
         take = arr[curidx] + solve(arr, n, curidx, curidx + 1);
      }
      nottake = solve(arr, n, previdx, curidx + 1);
      if (previdx != -1)
         t[previdx][curidx] = max(take, nottake);
      return max(take, nottake);
   }

   int maxSumIS(vector<int> &arr, int n)
   {
      // Your code goes here
      memset(t, -1, sizeof(t));
      return solve(arr, n, -1, 0);
   }
};

void main()
{
   int n;
   vector<int> arr(n);
   for (int i = 0; i < n; i++)
      cin >> arr[i];
   Solution solution = *new Solution();
   solution.maxSumIS(arr, n);
}
