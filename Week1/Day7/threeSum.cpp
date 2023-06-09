#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
   vector<vector<int>> threeSum(vector<int> &nums)
   {
      sort(nums.begin(), nums.end());
      vector<vector<int>> res;
      int i = 0, n = nums.size();
      while (i < n)
      {
         int j = i + 1, k = n - 1, newTarget = 0 - (nums[i]);
         while (j < k)
         {
            if (nums[j] + nums[k] == newTarget)
            {
               res.push_back({nums[i], nums[j], nums[k]});
               k--;
               j++;
               while (j < k && nums[j] == nums[j - 1])
                  j++;
               while (j < k && nums[k] == nums[k + 1])
                  k--;
            }
            else if (nums[j] + nums[k] > newTarget)
               k--;
            else
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
   int n;
   cin >> n;
   vector<int> res(n);
   for (int i = 0; i < n; i++)
      cin >> res[i];

   Solution solution = *new Solution();
   solution.threeSum(res);
}