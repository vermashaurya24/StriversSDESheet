#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
   bool isClosed(char ch)
   {
      return ch == ')' || ch == ']' || ch == '}';
   }

   bool matches(char c, char s)
   {
      if (c == '(')
         return s == ')';
      else if (c == '[')
         return s == ']';
      else if (c == '{')
         s == '}';
      return false;
   }

   bool isValid(string s)
   {
      stack<char> st;
      for (auto &ch : s)
      {
         if (isClosed(ch) && !st.empty() && matches(st.top(), ch))
            st.pop();
         else
            st.push(ch);
      }
      return st.empty();
   }
};

void main()
{
   string s;
   cin >> s;
   Solution solution = *new Solution();
   solution.isValid(s);
}