#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
   int lengthOfLIS(vector<int> &nums)
   {
      int n = nums.size(), res = 0;
      vector<int> lis(n);
      for (int i = n - 1; i >= 0; i--)
      {
         int lis_cur = 0;
         for (int j = i + 1; j < n; j++)
         {
            if (nums[j] > nums[i])
               lis_cur = max(lis_cur, lis[j]);
         }
         lis[i] = lis_cur + 1;
         res = max(res, lis[i]);
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
   solution.lengthOfLIS(v);
}