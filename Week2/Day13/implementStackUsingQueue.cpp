#include <bits/stdc++.h>
using namespace std;

class MyStack
{
public:
   queue<int> q;
   MyStack()
   {
   }

   void push(int x)
   {
      q.push(x);
   }

   int pop()
   {
      int sz = q.size();
      sz--;
      while (sz--)
      {
         q.push(q.front());
         q.pop();
      }
      int x = q.front();
      q.pop();
      return x;
   }

   int top()
   {
      return q.back();
   }

   bool empty()
   {
      return q.empty();
   }
};