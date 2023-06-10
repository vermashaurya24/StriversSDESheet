#include <bits/stdc++.h>
using namespace std;
struct Job
{
   int id;     // Job Id
   int dead;   // Deadline of job
   int profit; // Profit if job is over before or on deadline
};
static bool cmp(Job &a, Job &b)
{
   return a.profit > b.profit;
}
// Function to find the maximum profit and the number of jobs done.
vector<int> JobScheduling(Job arr[], int n)
{
   // your code here
   sort(arr, arr + n, cmp);
   int res = 0, cnt = 0, maxdead = 0;
   for (int i = 0; i < n; i++)
      maxdead = max(maxdead, arr[i].dead);
   vector<int> vis(maxdead + 1, 0);
   for (int i = 0; i < n; i++)
   {
      for (int j = arr[i].dead; j > 0; j--)
      {
         if (!vis[j])
         {
            res += arr[i].profit;
            vis[j] = 1;
            cnt++;
            break;
         }
      }
   }
   return {cnt, res};
}