#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
   vector<int> minPartition(int N)
   {
      // code here
      int coins[] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
      int n = 10;
      vector<int> res;
      for (int i = n - 1; i >= 0; i--)
      {
         while (N >= coins[i])
         {
            res.push_back(coins[i]);
            N -= coins[i];
         }
      }
      return res;
   }
};

void main()
{
   int N;
   cin >> N;
   Solution solution = *new Solution();
   solution.minPartition(N);
}