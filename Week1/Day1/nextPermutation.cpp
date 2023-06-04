#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
   void nextPermutation(vector<int> &nums)
   {
      int n = nums.size(), idx;
      for (idx = n - 2; idx >= 0; idx--)
      {
         if (nums[idx] < nums[idx + 1])
            break;
      }
      if (idx < 0)
      {
         reverse(nums.begin(), nums.end());
         return;
      }
      int idx_swap = idx + 1, swap = idx + 1;
      while (idx_swap < n)
      {
         if (nums[idx_swap] > nums[idx] && nums[idx_swap] < nums[swap])
         {
            swap = idx_swap;
         }
         idx_swap++;
      }
      int t = nums[idx];
      nums[idx] = nums[swap];
      nums[swap] = t;
      sort(nums.begin() + idx + 1, nums.end());
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
   solution.nextPermutation(res);
}