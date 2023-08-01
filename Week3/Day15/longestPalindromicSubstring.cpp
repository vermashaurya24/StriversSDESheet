#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
   string longestPalindrome(string s)
   {
      int n = s.size(), len = -1, left = -1;
      for (int i = 0; i < n; i++)
      {
         int j = i, k = i;
         while (j >= 0 && k < n && s[j] == s[k])
         {
            j--;
            k++;
         }
         if (len < (k - 1) - (j + 1) + 1)
         {
            len = (k - 1) - (j + 1) + 1;
            left = j + 1;
         }
         k = i;
         j = i - 1;
         while (j >= 0 && k < n && s[j] == s[k])
         {
            j--;
            k++;
         }
         if (len < (k - 1) - (j + 1) + 1)
         {
            len = (k - 1) - (j + 1) + 1;
            left = j + 1;
         }
      }
      return s.substr(left, len);
   }
};

void main()
{
   string s;
   cin >> s;
   Solution solution = *new Solution();
   cout << solution.longestPalindrome(s);
}