#include <bits/stdc++.h>
using namespace std;

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
   // Write your code here.
   vector<int> res;
   stack<int> st;
   for (int i = n - 1; i >= 0; i--)
   {
      while (!st.empty() && st.top() >= arr[i])
         st.pop();
      if (st.empty())
         res.push_back(-1);
      else
         res.push_back(st.top());
      st.push(arr[i]);
   }
   reverse(res.begin(), res.end());
   return res;
}

void main()
{
   int n;
   cin >> n;
   vector<int> arr(n);
   for (int i = 0; i < n; i++)
      cin >> arr[i];
   nextSmallerElement(arr, n);
}