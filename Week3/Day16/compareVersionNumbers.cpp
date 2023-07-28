#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
   int compareVersion(string s, string t)
   {
      int i = 0, n = s.size(), j = 0, m = t.size();
      while (i < n || j < m)
      {
         int r1 = 0, r2 = 0;
         while (i < n && s[i] != '.')
         {
            r1 = r1 * 10;
            r1 += s[i] - '0';
            i++;
         }
         i++;
         while (j < m && t[j] != '.')
         {
            r2 = r2 * 10;
            r2 += t[j] - '0';
            j++;
         }
         j++;
         if (r1 < r2)
            return -1;
         if (r1 > r2)
            return 1;
      }
      return 0;
   }
};

void main()
{
   string s, t;
   cin >> s >> t;
   Solution solution = *new Solution();
   solution.compareVersion(s, t);
}