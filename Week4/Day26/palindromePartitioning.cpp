#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
   int t[501];
   bool isPal(string s, int left, int right)
   {
      while (left < right)
      {
         if (s[left++] != s[right--])
            return false;
      }
      return true;
   }

   int solve(string s, int index)
   {
      if (index >= s.size())
         return -1;
      if (t[index] != -1)
         return t[index];
      int res = INT_MAX;
      for (int i = index; i < s.size(); i++)
      {
         if (isPal(s, index, i))
         {
            res = min(res, 1 + solve(s, i + 1));
         }
      }
      return t[index] = res;
   }

   int palindromicPartition(string str)
   {
      // code here
      memset(t, -1, sizeof(t));
      return solve(str, 0);
   }
};

void main()
{
   string s;
   cin >> s;
   Solution solution = *new Solution();
   solution.palindromicPartition(s);
}