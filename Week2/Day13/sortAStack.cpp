#include <bits/stdc++.h>
using namespace std;
class SortedStack
{
public:
   stack<int> s;
   void sort();
};
void insert(int elem, stack<int> &st)
{
   if (st.empty() || st.top() <= elem)
   {
      st.push(elem);
      return;
   }
   int top = st.top();
   st.pop();
   insert(elem, st);
   st.push(top);
}

void mySort(stack<int> &s)
{
   if (s.empty())
      return;
   int top = s.top();
   s.pop();
   mySort(s);
   insert(top, s);
}

void SortedStack ::sort()
{
   // Your code here
   mySort(s);
}