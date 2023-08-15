#include <bits/stdc++.h>
using namespace std;

int subarraysWithSumK(vector<int> &nums, int k)
{
   // Write your code here
   int xor_ = 0, res = 0;
   unordered_map<int, int> mp;
   mp[0] = 1;
   for (auto &num : nums)
   {
      xor_ ^= num;
      int x = xor_ ^ k;
      res += mp[x];
      mp[xor_]++;
   }
   return res;
}

void main()
{
   int n, k;
   cin >> n >> k;
   vector<int> v;
   for (int i = 0; i < n; i++)
      cin >> v[i];
   subarraysWithSumK(v, k);
}