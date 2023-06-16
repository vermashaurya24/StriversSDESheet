#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
   bool isPossible(int limit, int cows, vector<int> &stalls)
   {
      int prev = 0;
      cows--;
      for (int i = 0; i < stalls.size(); i++)
      {
         if (stalls[i] - stalls[prev] >= limit)
         {
            cows--;
            prev = i;
         }
      }
      return cows <= 0;
   }

   int solve(int n, int k, vector<int> &stalls)
   {

      // Write your code here
      sort(stalls.begin(), stalls.end());
      int low = 0, high = 1e9, res;
      while (low <= high)
      {
         int mid = low + (high - low) / 2;
         if (isPossible(mid, k, stalls))
         {
            res = mid;
            low = mid + 1;
         }
         else
         {
            high = mid - 1;
         }
      }
      return res;
   }
};

// Drivers code
int main()
{
   int n, k;
   cin >> n >> k;
   vector<int> res(n);
   for (int i = 0; i < n; i++)
      cin >> res[i];
   Solution solution = *new Solution();
   solution.solve(n, k, res);
}