#include <bits/stdc++.h>
using namespace std;

int multiply(int times, int n, int m)
{
   long long ans = 1;
   for (int i = 1; i <= times; i++)
   {
      ans *= n;
      if (ans > m)
         return 2;
   }
   return ans == m;
}

int NthRoot(int n, int m)
{
   // Write your code here.
   int low = 1, high = m;
   while (low <= high)
   {
      int mid = low + (high - low) / 2;
      int temp = multiply(n, mid, m);
      if (temp == 1)
         return mid;
      else if (temp == 0)
         low = mid + 1;
      else
         high = mid - 1;
   }
   return -1;
}

void main()
{
   int n, m;
   cin >> n >> m;
   NthRoot(n, m);
}