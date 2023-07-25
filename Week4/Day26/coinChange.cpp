#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
   int t[13][10001];
   int solve(vector<int> &coins, int amount, int index)
   {
      if (index == 0)
      {
         return (amount % coins[index] > 0) ? 1e9 : amount / coins[index];
      }
      if (amount == 0)
         return 0;
      if (t[index][amount] != -1)
         return t[index][amount];
      int take = 1e9, nottake;
      nottake = solve(coins, amount, index - 1);
      if (coins[index] <= amount)
         take = 1 + solve(coins, amount - coins[index], index);
      return t[index][amount] = min(take, nottake);
   }

   int coinChange(vector<int> &coins, int amount)
   {
      memset(t, -1, sizeof(t));
      sort(coins.begin(), coins.end());
      int res = solve(coins, amount, coins.size() - 1);
      return res >= 1e9 ? -1 : res;
   }
};

void main()
{
   int n, amount;
   cin >> n >> amount;
   vector<int> v(n);
   for (int i = 0; i < n; i++)
      cin >> v[i];
   Solution solution = *new Solution();
   solution.coinChange(v, amount);
}