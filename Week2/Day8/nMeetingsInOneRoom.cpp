#include <bits/stdc++.h>
using namespace std;

static bool cmp(pair<int, int> &a, pair<int, int> &b)
{
   return a.second < b.second;
}

int maxMeetings(int start[], int end[], int n)
{
   vector<pair<int, int>> v;
   for (int i = 0; i < n; i++)
   {
      v.push_back({start[i], end[i]});
   }
   sort(v.begin(), v.end(), cmp);
   // since we need to attend maximum number of meetings, we will choose ones which end early, thus sorting them acc to end time.
   int res = 1, prev = 0;
   for (int i = 1; i < n; i++)
   {
      if (v[i].first > v[prev].second)
      {
         res++;
         prev = i;
      }
   }
   return res;
}

void main()
{
   int n;
   cin >> n;
   int start[n], end[n];
   vector<int> res(n);
   for (int i = 0; i < n; i++)
      cin >> start[i];
   for (int i = 0; i < n; i++)
      cin >> end[i];
   maxMeetings(start, end, n);
}