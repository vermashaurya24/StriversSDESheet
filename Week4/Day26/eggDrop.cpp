#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
   // Function to find minimum number of attempts needed in
   // order to find the critical floor.
   int t[201][201];
   int solve(int eggs, int floors)
   {
      if (eggs == 1)
         return floors;
      if (floors < 2)
         return floors;
      if (t[eggs][floors] != -1)
         return t[eggs][floors];
      int res = INT_MAX;
      for (int i = 1; i <= floors; i++)
      {
         int temp = 1 + max(solve(eggs - 1, i - 1), solve(eggs, floors - i));
         res = min(res, temp);
      }
      return t[eggs][floors] = res;
   }

   int eggDrop(int n, int k)
   {
      // your code here
      memset(t, -1, sizeof(t));
      return solve(n, k);
   }
};

void main()
{
   int eggs, floors;
   cin >> eggs >> floors;
   Solution solution = *new Solution();
   solution.eggDrop(eggs, floors);
}