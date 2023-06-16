#include <bits/stdc++.h>
using namespace std;

class MyQueue
{
public:
   stack<int> ip, op;
   MyQueue() {}

   void push(int x)
   {
      ip.emplace(x);
   }

   int pop()
   {
      peek();
      int x = op.top();
      op.pop();
      return x;
   }

   int peek()
   {
      int x;
      if (op.empty())
         while (!ip.empty())
            op.emplace(ip.top()), ip.pop();
      return op.top();
   }

   bool empty()
   {
      return ip.empty() and op.empty();
   }
};