#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
   vector<int> countDistinct(vector<int> nums, int n, int k)
   {
      // code here.
      vector<int> res;
      unordered_map<int, int> mp;
      for (int i = 0; i < k; i++)
      {
         mp[nums[i]]++;
      }
      res.push_back(mp.size());
      for (int i = k; i < n; i++)
      {
         mp[nums[i]]++;
         mp[nums[i - k]]--;
         if (mp[nums[i - k]] == 0)
            mp.erase(nums[i - k]);
         res.push_back(mp.size());
      }
      return res;
   }
};

void main()
{
   int n, k;
   cin >> n >> k;
   vector<int> res(n);
   for (int i = 0; i < n; i++)
   {
      cin >> res[i];
   }
   Solution solution = *new Solution();
   solution.countDistinct(res, n, k);
}