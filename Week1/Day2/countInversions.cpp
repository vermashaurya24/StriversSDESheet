#include <bits/stdc++.h>
using namespace std;

// question solved on Coding Ninjas platform.
void merge(vector<long long> &nums, int left, int mid, int right, long long &ans)
{
   vector<int> temp;
   int i = left, j = mid + 1;
   while (i <= mid)
   {
      while (j <= right && nums[i] > (nums[j]))
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

void solve(vector<long long> &nums, int left, int right, long long &ans)
{
   if (left >= right)
      return;
   int mid = (right + left) / 2;
   solve(nums, left, mid, ans);
   solve(nums, mid + 1, right, ans);
   // using the concept of merge sort, while backtracking and merging the array back, we check the condition.
   merge(nums, left, mid, right, ans);
}

long long getInversions(long long *arr, int n)
{
   long long ans = 0;
   vector<long long> nums;
   for (int i = 0; i < n; i++)
      nums.push_back(arr[i]);
   solve(nums, 0, n - 1, ans);
   return ans;
}
