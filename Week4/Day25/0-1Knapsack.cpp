#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
   // Function to return max value that can be put in knapsack of capacity W.
   int t[1001][1001];
   int solve(int weight, vector<int> &wt, vector<int> &val, int index)
   {
      if (index < 0)
         return 0;
      if (t[weight][index] != -1)
         return t[weight][index];
      int pick = 0, notpick = 0;
      if (wt[index] <= weight)
         pick = val[index] + solve(weight - wt[index], wt, val, index - 1);
      notpick = solve(weight, wt, val, index - 1);
      return t[weight][index] = max(pick, notpick);
   }

   int knapSack(int w, vector<int> &wt, vector<int> &val, int n)
   {
      // Your code here
      memset(t, -1, sizeof(t));
      return solve(w, wt, val, n - 1);
   }
};

void main()
{
   int n, w;
   vector<int> wt(n), val(n);
   for (int i = 0; i < n; i++)
   {
      cin >> wt[i] >> val[i];
   }
   Solution solution = *new Solution();
   solution.knapSack(w, wt, val, n);
}
