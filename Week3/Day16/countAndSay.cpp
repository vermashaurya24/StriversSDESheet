#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
   string countAndSay(int n)
   {
      if (n == 1)
         return "1";
      string prev = countAndSay(n - 1);
      int m = prev.size(), count = 1;
      string cur = "";
      for (int i = 1; i < m; i++)
      {
         if (prev[i] == prev[i - 1])
         {
            count++;
         }
         else
         {
            cur += to_string(count) + prev[i - 1];
            count = 1;
         }
      }
      cur += to_string(count) + prev.back();
      return cur;
   }
};

void main()
{
   int n;
   cin >> n;
   Solution solution = *new Solution();
   solution.countAndSay(n);
}