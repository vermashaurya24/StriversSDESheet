#include <bits/stdc++.h>
using namespace std;
struct Item
{
   int value;
   int weight;
};
class Solution
{
public:
   // Function to get the maximum total value in the knapsack.

   static bool cmp(Item &a, Item &b)
   {
      double unit1 = (double)a.value / a.weight;
      double unit2 = (double)b.value / b.weight;
      return unit1 > unit2;
   }

   double fractionalKnapsack(int W, Item arr[], int n)
   {
      // Your code here
      sort(arr, arr + n, cmp);
      double res = 0;
      for (int i = 0; i < n; i++)
      {
         if (arr[i].weight <= W)
         {
            res += arr[i].value;
            W -= arr[i].weight;
         }
         else
         {
            double unit = (double)arr[i].value / arr[i].weight;
            res += (W * unit);
            W = 0;
            break;
         }
         // if(!W)  break;
      }
      return res;
   }
};