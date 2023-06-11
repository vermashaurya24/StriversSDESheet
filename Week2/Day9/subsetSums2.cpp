#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
   set<vector<int>> st;

   void dfs(vector<int> &nums, int idx, vector<int> &cur)
   {
      if (idx == nums.size())
      {
         st.insert(cur);
         return;
      }
      cur.push_back(nums[idx]);
      dfs(nums, idx + 1, cur);
      cur.pop_back();
      dfs(nums, idx + 1, cur);
   }

   vector<vector<int>> subsetsWithDup(vector<int> &nums)
   {
      vector<int> cur;
      sort(nums.begin(), nums.end());
      dfs(nums, 0, cur);
      vector<vector<int>> ans;
      for (auto it : st)
         ans.push_back(it);
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
   solution.subsetsWithDup(res);
}