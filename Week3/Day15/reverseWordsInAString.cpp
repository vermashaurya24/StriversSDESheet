#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
   string reverseWords(string s)
   {
      reverse(s.begin(), s.end());
      string res = "", word = "";
      for (auto &ch : s)
      {
         if (ch == ' ')
         {
            if (word.empty())
               continue;
            else
            {
               reverse(word.begin(), word.end());
               res += word;
               res += ' ';
               word = "";
            }
         }
         else
         {
            word += ch;
         }
      }
      if (!word.empty())
      {
         reverse(word.begin(), word.end());
         res += word;
      }
      if (res.back() == ' ')
         res.pop_back();
      return res;
   }
};

void main()
{
   string s;
   cin >> s;
   Solution solution = *new Solution();
   solution.reverseWords(s);
}