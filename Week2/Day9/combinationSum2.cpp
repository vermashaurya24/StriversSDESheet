#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
   vector<vector<int>> res;

   void solve(vector<int> &nums, int index, int target, vector<int> &v)
   {
      if (target == 0)
      {
         res.push_back(v);
         return;
      }
      for (int i = index; i < nums.size(); i++)
      {
         if (i > index && nums[i] == nums[i - 1])
            continue;
         if (nums[i] > target)
            break;
         v.push_back(nums[i]);
         solve(nums, i + 1, target - nums[i], v);
         v.pop_back();
      }
   }

   vector<vector<int>> combinationSum2(vector<int> &nums, int target)
   {
      sort(nums.begin(), nums.end());
      vector<int> v;
      solve(nums, 0, target, v);
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
   solution.combinationSum2(res, target);
}