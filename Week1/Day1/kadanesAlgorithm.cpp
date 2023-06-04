#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
   int maxSubArray(vector<int> &nums)
   {
      // Kadanes Algorithm
      int sum = 0, res = INT_MIN;
      for (auto &num : nums)
      {
         // if sum of current subarray is < 0, then it can never contribute to the actual answer. hence we ignore it
         if (sum < 0)
            sum = 0;
         sum += num;
         res = max(res, sum);
      }
      return res;
   }
};

void main()
{
   int n;
   cin >> n;
   vector<int> res(n);
   for (int i = 0; i < n; i++)
      cin >> res[i];
   Solution solution = *new Solution();
   solution.maxSubArray(res);
}