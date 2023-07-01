#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
   vector<int> arr;
   int ptr;
   void myStack(int n)
   {
      arr.resize(n);
      ptr = -1;
   }
   int push(int element)
   {
      // returns 1 if element successfully pushed, else returns 0
      if (ptr >= arr.size())
         return 0;
      ptr++;
      arr[ptr] = element;
      return 1;
   }
   void pop()
   {
      if (ptr == -1)
         return;
      ptr--;
   }
   int top()
   {
      // return -1 if stack empty, else return top element
      if (ptr == -1)
         return -1;
      return arr[ptr];
   }
   bool empty()
   {
      return ptr == -1;
   }
};