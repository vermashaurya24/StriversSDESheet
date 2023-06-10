#include <bits/stdc++.h>
using namespace std;

int findPlatform(int arr[], int dep[], int n)
{
   // Your code here
   sort(arr, arr + n);
   sort(dep, dep + n);
   int platforms = 1, ans = 1, i = 1, j = 0;
   while (i < n && j < n)
   {
      if (arr[i] <= dep[j])
      {
         platforms++;
         i++;
      }
      else
      {
         platforms--;
         j++;
      }
      ans = max(ans, platforms);
   }
   return ans;
}