#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
   int findMaxConsecutiveOnes(vector<int> &nums)
   {
      int n = nums.size(), res = nums[0];
      for (int i = 1; i < n; i++)
      {
         if (nums[i] == 0)
            continue;
         else
         {
            nums[i] += nums[i - 1];
            res = max(res, nums[i]);
         }
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
   solution.findMaxConsecutiveOnes(res);
}