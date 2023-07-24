#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
   int t[201][10001];
   bool solve(vector<int> &nums, int index, int target)
   {
      if (target == 0)
         return true;
      if (index >= nums.size())
         return false;
      if (t[index][target] != -1)
         return t[index][target];
      bool take = false, nottake = false;
      if (nums[index] <= target)
         take = solve(nums, index + 1, target - nums[index]);
      nottake = solve(nums, index + 1, target);
      return t[index][target] = take || nottake;
   }

   bool canPartition(vector<int> &nums)
   {
      int sum = accumulate(nums.begin(), nums.end(), 0);
      if (sum % 2)
         return false;
      memset(t, -1, sizeof(t));
      return solve(nums, 0, sum / 2);
   }
};

void main()
{
   int n;
   cin >> n;
   vector<int> v(n);
   for (int i = 0; i < n; i++)
      cin >> v[i];
   Solution solution = *new Solution();
   solution.canPartition(v);
}