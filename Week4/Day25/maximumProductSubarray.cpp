#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
   int maxProduct(vector<int> &nums)
   {
      if (nums.size() == 1)
         return nums[0];
      int res = 0, left = 1, right = 1, n = nums.size();
      for (int i = 0; i < n; i++)
      {
         if (left == 0)
            left = 1;
         left *= nums[i];
         res = max(res, left);
      }
      for (int i = n - 1; i >= 0; i--)
      {
         if (right == 0)
            right = 1;
         right *= nums[i];
         res = max(res, right);
      }
      return res;
   }
};

void main()
{
   int n;
   cin >> n;
   vector<int> v(n);
   for (int i = 0; i < n; i++)
      cin >> v[i];
   Solution solution = *new Solution();
   solution.maxProduct(v);
}