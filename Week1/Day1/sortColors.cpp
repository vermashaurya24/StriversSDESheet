#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
   void sortColors(vector<int> &nums)
   {
      // created separations, everything to the left of "left" will contain 0's, everything to the right of "right" will contain all 2's, leaving all the 1's in the middle.
      int n = nums.size(), left = 0, mid = 0, right = n - 1;
      while (mid <= right)
      {
         // if we encounter a 1, we need to send it to the left of "left".
         if (nums[mid] == 0)
         {
            swap(nums[left], nums[mid]);
            left++;
            mid++;
         }
         // if we encounter a 2, we need to send it to the right of "right".
         else if (nums[mid] == 2)
         {
            swap(nums[right], nums[mid]);
            right--;
         }
         // if we encounter a 1, we leave it as it is.
         else
         {
            mid++;
         }
      }
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
   solution.sortColors(res);
}