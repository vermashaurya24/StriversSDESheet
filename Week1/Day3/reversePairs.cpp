#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
   int ans = 0;

   void merge(vector<int> &nums, int left, int mid, int right)
   {
      vector<int> temp;
      int i = left, j = mid + 1;
      while (i <= mid)
      {
         while (j <= right && nums[i] > (2 * (long)nums[j]))
            j++;
         ans += (j - (mid + 1));
         i++;
      }
      i = left, j = mid + 1;
      while (i <= mid && j <= right)
      {
         if (nums[i] <= nums[j])
         {
            temp.push_back(nums[i]);
            i++;
         }
         else
         {
            temp.push_back(nums[j]);
            j++;
         }
      }
      while (i <= mid)
         temp.push_back(nums[i++]);
      while (j <= right)
         temp.push_back(nums[j++]);
      i = left;
      for (auto &t : temp)
         nums[i++] = t;
   }

   void solve(vector<int> &nums, int left, int right)
   {
      if (left >= right)
         return;
      int mid = (right + left) / 2;
      solve(nums, left, mid);
      solve(nums, mid + 1, right);
      merge(nums, left, mid, right);
   }

   int reversePairs(vector<int> &nums)
   {
      // using the concept of merge sort, while backtracking and merging the array back, we check the condition.
      solve(nums, 0, nums.size() - 1);
      return ans;
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
   solution.reversePairs(res);
}