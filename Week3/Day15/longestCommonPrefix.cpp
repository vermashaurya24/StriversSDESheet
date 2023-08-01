#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
   string longestCommonPrefix(vector<string> &strs)
   {
      sort(strs.begin(), strs.end());
      string smallest = strs[0];
      string res = "";
      for (int i = 0; i < smallest.size(); i++)
      {
         for (auto &str : strs)
         {
            if (str[i] != smallest[i])
               return res;
         }
         res += smallest[i];
      }
      return res;
   }
};

void main()
{
   int n;
   cin >> n;
   vector<string> v;
   for (int i = 0; i < n; i++)
      cin >> v[i];
   Solution solution = *new Solution();
   cout << solution.longestCommonPrefix(v);
}