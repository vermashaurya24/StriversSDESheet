#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
   vector<int> arr;
   int front, rear, size, cap;
   void myQueue(int sz)
   {
      arr.resize(sz, 0);
      size = sz;
      front = 0;
      rear = 0;
      cap = 0;
   }
   void push(int x)
   {
      if (cap == size)
         return;
      rear = rear % size;
      cap++;
      arr[rear] = x;
      rear++;
   }
   void pop()
   {
      if (cap == 0)
         return;
      front = front % size;
      cap--;
      front++;
   }
   int front()
   {
      front = front % size;
      return arr[front];
   }
   int back()
   {
      rear = rear % size;
      return arr[rear];
   }
   int size()
   {
      return cap;
   }
   bool empty()
   {
      return cap == 0;
   }
};