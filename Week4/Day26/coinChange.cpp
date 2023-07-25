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
   // 2 array memoized
   // int coinChange(vector<int>& coins, int amount) {
   //      int n = coins.size();
   //      vector<int> prev(amount+1), cur(amount+1);
   //      for(int j=0; j<amount+1; j++)   prev[j] = 1e9;
   //      for(int i=1; i<n+1; i++) {
   //          for(int j=1; j<amount+1; j++) {
   //              if(coins[i-1] <= j) {
   //                  int pick = cur[j-coins[i-1]]+1, notpick = prev[j];
   //                  cur[j] = min(pick,notpick);
   //              }
   //              else {
   //                  cur[j] = prev[j];
   //              }
   //          }
   //          prev = cur;
   //      }
   //      return prev[amount] >= 1e9 ? -1 : prev[amount];
   //  }
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