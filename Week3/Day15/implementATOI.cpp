#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
   int myAtoi(string s)
   {
      reverse(s.begin(), s.end());
      while (!s.empty() && s.back() == ' ')
         s.pop_back();
      reverse(s.begin(), s.end());
      int i = 0, n = s.size(), res = 0;
      bool negative = false;
      if (s[0] == '-')
      {
         negative = true;
         i++;
      }
      else if (s[0] == '+')
      {
         i++;
      }
      while (i < n && s[i] >= '0' && s[i] <= '9')
      {
         if ((long)res * 10 + s[i] - '0' > INT_MAX)
         {
            return (negative) ? INT_MIN : INT_MAX;
         }
         else
         {
            res = res * 10;
            res += s[i] - '0';
         }
         i++;
      }
      return ((negative) ? -1 : 1) * res;
   }
};

void main()
{
   string s;
   cin >> s;
   Solution solution = *new Solution();
   cout << solution.myAtoi(s);
}