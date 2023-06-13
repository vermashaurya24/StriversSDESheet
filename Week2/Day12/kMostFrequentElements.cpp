#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
   vector<int> topKFrequent(vector<int> &nums, int k)
   {
      unordered_map<int, int> mp;
      for (auto &num : nums)
      {
         mp[num]++;
      }
      priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
      for (auto &it : mp)
      {
         pq.push({it.second, it.first});
         if (pq.size() > k)
            pq.pop();
      }
      vector<int> res;
      while (!pq.empty())
      {
         res.push_back(pq.top()[1]);
         pq.pop();
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
      cin >> res[i];
   Solution solution = *new Solution();
   solution.topKFrequent(res, k);
}