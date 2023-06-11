#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
   vector<int> res;
   // simple take / not take
   void solve(vector<int> &arr, int n, int index, int sum)
   {
      if (index >= n)
         return;
      sum += arr[index];
      res.push_back(sum);
      solve(arr, n, index + 1, sum);
      sum -= arr[index];
      solve(arr, n, index + 1, sum);
   }

   vector<int> subsetSums(vector<int> arr, int N)
   {
      // Write Your Code here
      res.push_back(0);
      solve(arr, N, 0, 0);
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
   solution.subsetSums(res, n);
}