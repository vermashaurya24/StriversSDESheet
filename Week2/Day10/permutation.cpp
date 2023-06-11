#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
   vector<vector<int>> res;

   void solve(vector<int> &nums, int index)
   {
      if (index >= nums.size())
      {
         res.push_back(nums);
         return;
      }
      for (int i = index; i < nums.size(); i++)
      {
         swap(nums[i], nums[index]);
         solve(nums, index + 1);
         swap(nums[i], nums[index]);
      }
   }

   vector<vector<int>> permute(vector<int> &nums)
   {
      solve(nums, 0);
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
   solution.permute(res);
}