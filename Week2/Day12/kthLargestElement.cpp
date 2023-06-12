#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
   int findKthLargest(vector<int> &nums, int k)
   {
      priority_queue<int, vector<int>, greater<int>> pq;
      for (auto &num : nums)
      {
         pq.push(num);
         if (pq.size() > k)
            pq.pop();
      }
      return pq.top();
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
   solution.findKthLargest(res, k);
}