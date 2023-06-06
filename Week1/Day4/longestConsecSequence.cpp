#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
   int longestConsecutive(vector<int> &nums)
   {
      unordered_set<int> st;
      for (auto &num : nums)
         st.insert(num);
      int len = 0;
      for (auto &it : nums)
      {
         int curnum = it;
         int curlen = 1, lower = curnum - 1, upper = curnum + 1;
         while (st.count(lower))
         {
            st.erase(lower);
            curlen++;
            lower--;
         }
         while (st.count(upper))
         {
            st.erase(upper);
            curlen++;
            upper++;
         }
         st.erase(curnum);
         len = max(len, curlen);
      }
      return len;
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
   solution.longestConsecutive(res);
}