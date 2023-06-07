#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
   int lengthOfLongestSubstring(string s)
   {
      int res = 0, n = s.size(), j = 0;
      unordered_map<char, int> mp;
      for (int i = 0; i < n; i++)
      {
         mp[s[i]]++;
         while (j < i && mp[s[i]] > 1)
         {
            mp[s[j]]--;
            j++;
         }
         res = max(res, i - j + 1);
      }
      return res;
   }
};

void main()
{
   string s;
   cin >> s;
   Solution solution = *new Solution();
   solution.lengthOfLongestSubstring(s);
}