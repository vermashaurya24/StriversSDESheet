#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
   string reverseWords(string s)
   {
      while (s.back() == ' ')
         s.pop_back();
      reverse(s.begin(), s.end());
      while (s.back() == ' ')
         s.pop_back();
      // reverse(s.begin(), s.end());
      int n = s.size();
      string word = "";
      for (int i = 0; i < n; i++)
      {
         if (s[i] == ' ')
         {
            if (word == "")
               continue;
            reverse(word.begin(), word.end());
            s += word;
            s += ' ';
            word = "";
         }
         else
         {
            word += s[i];
         }
      }
      reverse(word.begin(), word.end());
      s += word;
      return s.substr(n);
   }
};

void main()
{
   string s;
   cin >> s;
   Solution solution = *new Solution();
   solution.reverseWords(s);
}