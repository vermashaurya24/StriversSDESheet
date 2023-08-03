#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
   int t[101][101];
   int solve(int arr[], int left, int right)
   {
      if (left >= right)
         return 0;
      if (t[left][right] != -1)
         return t[left][right];
      int res = INT_MAX;
      for (int i = left; i < right; i++)
      {
         int leftCost = solve(arr, left, i);
         int rightCost = solve(arr, i + 1, right);
         int curCost = arr[left - 1] * arr[i] * arr[right];
         res = min(res, leftCost + rightCost + curCost);
      }
      return t[left][right] = res;
   }

   int matrixMultiplication(int N, int arr[])
   {
      // code here
      memset(t, -1, sizeof(t));
      return solve(arr, 1, N - 1);
   }
};
