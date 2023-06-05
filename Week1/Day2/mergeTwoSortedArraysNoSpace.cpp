#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
   void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
   {
      int ptr = m + n - 1;
      m--;
      n--;
      while (m >= 0 && n >= 0 && ptr >= 0)
      {
         if (nums1[m] > nums2[n])
         {
            nums1[ptr] = nums1[m];
            m--;
         }
         else
         {
            nums1[ptr] = nums2[n];
            n--;
         }
         ptr--;
      }
      while (m >= 0)
      {
         nums1[ptr--] = nums1[m--];
      }
      while (n >= 0)
      {
         nums1[ptr--] = nums2[n--];
      }
   }
};

void main()
{
   int n, m;
   cin >> n >> m;
   vector<int> nums1(n), nums2(m);
   for (int i = 0; i < n; i++)
      cin >> nums1[i];
   for (int i = 0; i < m; i++)
      cin >> nums2[i];
   Solution solution = *new Solution();
   solution.merge(nums1, n, nums2, m);
}