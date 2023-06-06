#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
   int maxLen(vector<int> &nums, int n)
   {
      // Your code here
      unordered_map<int, int> mp;
      int len = 0, sum = 0;
      mp[0] = -1;
      for (int i = 0; i < n; i++)
      {
         sum += nums[i];
         if (mp.count(sum))
         {
            len = max(len, i - mp[sum]);
         }
         else
         {
            mp[sum] = i;
         }
      }
      if (sum == 0)
         len = max(len, n);
      return len;
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
   solution.maxLen(res, n);
}