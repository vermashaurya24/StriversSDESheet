#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
   int trap(vector<int> &nums)
   {
      int left = 0, n = nums.size(), right = n - 1, leftmax = 0, rightmax = 0;
      int res = 0;
      while (left < right)
      {
         if (nums[left] <= nums[right])
         {
            if (nums[left] > leftmax)
               leftmax = nums[left];
            else
               res += min(leftmax, nums[right]) - nums[left];
            left++;
         }
         else
         {
            if (nums[right] > rightmax)
               rightmax = nums[right];
            else
               res += min(nums[left], rightmax) - nums[right];
            right--;
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
   solution.trap(res);
}