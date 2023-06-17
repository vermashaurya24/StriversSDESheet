#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
   vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
   {
      unordered_map<int, int> mp;
      stack<int> st;
      int n = nums1.size(), m = nums2.size();
      for (int i = m - 1; i >= 0; i--)
      {
         while (!st.empty() && nums2[i] > st.top())
            st.pop();
         if (st.empty())
            mp[nums2[i]] = -1;
         else
            mp[nums2[i]] = st.top();
         st.push(nums2[i]);
      }
      for (auto &num : nums1)
         num = mp[num];
      return nums1;
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
   solution.nextGreaterElement(nums1, nums2);
}