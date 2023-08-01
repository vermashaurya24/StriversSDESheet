#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
   typedef pair<int, pair<int, int>> pip;
   vector<int> maxCombinations(int n, int k, vector<int> &a, vector<int> &b)
   {
      // code here
      vector<int> res;
      set<pair<int, int>> st;
      priority_queue<pip> pq;
      sort(a.begin(), a.end());
      sort(b.begin(), b.end());
      reverse(a.begin(), a.end());
      reverse(b.begin(), b.end());
      pq.push({a[0] + b[0], {0, 0}});
      st.insert({0, 0});
      while (!pq.empty() && k--)
      {
         auto top = pq.top();
         pq.pop();
         int i = top.second.first, j = top.second.second;
         res.push_back(top.first);
         if (i + 1 < n && !st.count({i + 1, j}))
         {
            st.insert({i + 1, j});
            pq.push({a[i + 1] + b[j], {i + 1, j}});
         }
         if (j + 1 < n && !st.count({i, j + 1}))
         {
            st.insert({i, j + 1});
            pq.push({a[i] + b[j + 1], {i, j + 1}});
         }
      }
      return res;
   }
};

void main()
{
   int n, k;
   cin >> n >> k;
   vector<int> a(n), b(n);
   for (int i = 0; i < n; i++)
      cin >> a[i];
   for (int i = 0; i < n; i++)
      cin >> b[i];

   Solution solution = *new Solution();
   solution.maxCombinations(n, k, a, b);
}