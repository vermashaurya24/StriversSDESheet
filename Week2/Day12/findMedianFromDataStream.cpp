#include <bits/stdc++.h>
using namespace std;

class MedianFinder
{
public:
   priority_queue<int> mxH;
   priority_queue<int, vector<int>, greater<int>> mnH;
   MedianFinder()
   {
   }

   void addNum(int num)
   {
      if (mxH.empty() || num <= mxH.top())
      {
         mxH.push(num);
      }
      else
      {
         mnH.push(num);
      }
      if (mxH.size() > mnH.size() + 1)
      {
         mnH.push(mxH.top());
         mxH.pop();
      }
      else if (mnH.size() > mxH.size())
      {
         mxH.push(mnH.top());
         mnH.pop();
      }
   }

   double findMedian()
   {
      int size = mnH.size() + mxH.size();
      return (size % 2) ? (double)mxH.top() : ((double)mnH.top() + (double)mxH.top()) / 2;
   }
};