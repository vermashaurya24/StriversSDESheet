#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
   int maxProfit(vector<int> &prices)
   {
      int ans = 0, minbuy = prices[0];
      for (auto p : prices)
      {
         // checking if current price difference give us the maximum profit
         ans = max(ans, p - minbuy);

         // always prefer to buy at the lower price and sell later at higher price.
         minbuy = min(minbuy, p);
      }
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
   solution.maxProfit(res);
}