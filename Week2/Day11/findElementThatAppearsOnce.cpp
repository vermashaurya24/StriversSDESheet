#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
   int singleNonDuplicate(vector<int> &nums)
   {
      int low = 0, n = nums.size(), high = n - 1;
      while (low <= high)
      {
         int mid = low + (high - low) / 2;
         if (mid + 1 < n && nums[mid] == nums[mid + 1])
         {
            if (mid % 2)
               high = mid - 1;
            else
               low = mid + 1;
         }
         else if (mid - 1 >= 0 && nums[mid] == nums[mid - 1])
         {
            if ((mid % 2) == 0)
               high = mid - 1;
            else
               low = mid + 1;
         }
         else
         {
            return nums[mid];
         }
      }
      return -1;
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
   solution.singleNonDuplicate(res);
}