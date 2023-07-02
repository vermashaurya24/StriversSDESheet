#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
   int largestRectangleArea(vector<int> &heights)
   {
      stack<int> st;
      heights.push_back(-1);
      int res = 0, n = heights.size();
      for (int i = 0; i < n; i++)
      {
         while (!st.empty() && heights[st.top()] > heights[i])
         {
            int top = heights[st.top()];
            st.pop();
            int width = i - (st.empty() ? 0 : st.top() + 1);
            res = max(res, width * top);
         }
         st.push(i);
      }
      return res;
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
   solution.largestRectangleArea(res);
}