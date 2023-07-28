#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
   bool isAnagram(string s, string t)
   {
      vector<int> v(26);
      for (auto &ch : s)
         v[ch - 'a']++;
      for (auto &ch : t)
         v[ch - 'a']--;
      for (auto &it : v)
         if (it != 0)
            return false;
      return true;
   }
};

void main()
{
   string s, t;
   cin >> s >> t;
   Solution solution = *new Solution();
   solution.isAnagram(s, t);
}