#include <bits/stdc++.h>
using namespace std;
struct Job
{
   int id;     // Job Id
   int dead;   // Deadline of job
   int profit; // Profit if job is over before or on deadline
};

class Solution
{
public:
   // Function to find the maximum profit and the number of jobs done.

   static bool cmp(Job &a, Job &b)
   {
      if (a.profit == b.profit)
         return a.dead > b.dead;
      return a.profit > b.profit;
   }

   vector<int> JobScheduling(Job arr[], int n)
   {
      // your code here
      sort(arr, arr + n, cmp);
      int maxdead = 0;
      for (int i = 0; i < n; i++)
      {
         maxdead = max(maxdead, arr[i].dead);
      }
      vector<int> t(maxdead, -1);
      int total_profit = 0, count = 0;
      for (int i = 0; i < n; i++)
      {
         int profit = arr[i].profit, deadline = arr[i].dead;
         for (int j = deadline - 1; j >= 0; j--)
         {
            if (t[j] == -1)
            {
               t[j] = arr[i].id;
               total_profit += profit;
               count++;
               break;
            }
         }
      }
      return {count, total_profit};
   }
};