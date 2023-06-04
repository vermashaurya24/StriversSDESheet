#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
   vector<vector<int>> generate(int n)
   {
      if (n == 1)
         return {{1}};
      vector<vector<int>> ans;
      vector<int> res = {1};
      ans.push_back(res);
      for (int i = 2; i <= n; i++)
      {
         vector<int> cur;
         cur.push_back(1);
         for (int j = 1; j < res.size(); j++)
         {
            cur.push_back(res[j] + res[j - 1]);
         }
         cur.push_back(1);
         res = cur;
         ans.push_back(res);
      }
      return ans;
   }
};

void main()
{
   int n;
   cin >> n;
   Solution solution = *new Solution();
   solution.generate(n);
}