#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
   vector<vector<int>> fourSum(vector<int> &nums, int target)
   {
      vector<vector<int>> res;
      sort(nums.begin(), nums.end());
      int n = nums.size();
      int j, i = 0;
      while (i < n)
      {
         j = i + 1;
         while (j < n)
         {
            long long curTarget = (long)target - ((long)nums[i] + (long)nums[j]);
            int k = j + 1, l = n - 1;
            while (k < l)
            {
               if (nums[k] + nums[l] == curTarget)
               {
                  res.push_back({nums[i], nums[j], nums[k], nums[l]});
                  k++;
                  l--;
                  while (k < l && nums[k] == nums[k - 1])
                     k++;
                  while (l > k && nums[l] == nums[l + 1])
                     l--;
               }
               else if (nums[k] + nums[l] > curTarget)
                  l--;
               else
                  k++;
            }
            j++;
            while (j < n && nums[j] == nums[j - 1])
               j++;
         }
         i++;
         while (i < n && nums[i] == nums[i - 1])
            i++;
      }
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
   solution.fourSum(res, target);
}