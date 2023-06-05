#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
   int findDuplicate(vector<int> &nums)
   {
      int n = nums.size(), i = 0;
      while (i < n)
      {
         int correct = nums[i] - 1;
         if (nums[i] == nums[correct])
            i++;
         else
         {
            swap(nums[correct], nums[i]);
         }
      }
      for (int i = 0; i < n; i++)
      {
         if (nums[i] != i + 1)
            return nums[i];
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
   solution.findDuplicate(res);
}