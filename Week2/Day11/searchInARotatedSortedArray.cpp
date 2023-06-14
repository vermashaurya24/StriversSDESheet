#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
   int search(vector<int> &nums, int target)
   {
      int n = nums.size(), low = 0, high = n - 1;
      while (low <= high)
      {
         int mid = low + (high - low) / 2;
         if (nums[mid] == target)
            return mid;
         else if (nums[low] <= nums[mid])
         {
            if (target >= nums[low] && target <= nums[mid])
               high = mid - 1;
            else
               low = mid + 1;
         }
         else
         {
            if (target >= nums[mid] && target <= nums[high])
               low = mid + 1;
            else
               high = mid - 1;
         }
      }
      return -1;
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
   solution.search(res, target);
}