#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
   vector<vector<int>> res;

   void solve(vector<int> &nums, int index, int target, vector<int> &v)
   {
      if (target < 0)
         return;
      if (target == 0)
      {
         res.push_back(v);
         return;
      }
      if (index == nums.size())
         return;
      v.push_back(nums[index]);
      solve(nums, index, target - nums[index], v);
      v.pop_back();
      solve(nums, index + 1, target, v);
   }

   vector<vector<int>> combinationSum(vector<int> &candidates, int target)
   {
      vector<int> v;
      solve(candidates, 0, target, v);
      return res;
   }
};

void main()
{
   int n, target;
   cin >> n >> target;
   vector<int> res(n);
   for (int i = 0; i < n; i++)
      cin >> res[i];

   Solution solution = *new Solution();
   solution.combinationSum(res, target);
}