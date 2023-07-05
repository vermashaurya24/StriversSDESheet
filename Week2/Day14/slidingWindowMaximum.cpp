#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
   vector<int> maxSlidingWindow(vector<int> &nums, int k)
   {
      vector<int> res;
      deque<int> window;
      int n = nums.size();
      for (int i = 0; i < k; i++)
      {
         while (!window.empty() && nums[window.back()] < nums[i])
            window.pop_back();
         window.push_back(i);
      }
      res.push_back(nums[window.front()]);
      for (int i = k; i < n; i++)
      {
         while (!window.empty() && window.front() <= i - k)
            window.pop_front();
         while (!window.empty() && nums[window.back()] < nums[i])
            window.pop_back();
         window.push_back(i);
         res.push_back(nums[window.front()]);
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
   solution.maxSlidingWindow(res, k);
}