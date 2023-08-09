#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
   int t[101][101];
   int solve(vector<int> &cuts, int left, int right, int left_cut, int right_cut)
   {
      if (left_cut > right_cut)
         return 0;
      if (t[left_cut][right_cut] != -1)
         return t[left_cut][right_cut];
      int res = INT_MAX;
      for (int i = left_cut; i <= right_cut; i++)
      {
         int cur_cost = right - left + solve(cuts, left, cuts[i], left_cut, i - 1) + solve(cuts, cuts[i], right, i + 1, right_cut);
         res = min(res, cur_cost);
      }
      return t[left_cut][right_cut] = res;
   }

   int minCost(int n, vector<int> &cuts)
   {
      memset(t, -1, sizeof(t));
      sort(cuts.begin(), cuts.end());
      return solve(cuts, 0, n, 0, cuts.size() - 1);
   }
};

void main()
{
   int n, m;
   cin >> n >> m;
   vector<int> v(m);
   for (int i = 0; i < m; i++)
      cin >> v[i];
   Solution solution = *new Solution();
   solution.minCost(n, v);
}