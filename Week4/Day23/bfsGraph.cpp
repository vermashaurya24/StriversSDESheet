#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
   vector<int> bfsOfGraph(int n, vector<int> adj[])
   {
      // Code here
      vector<int> res, vis(n, 0);
      queue<int> q;
      q.push(0);
      vis[0] = 1;
      while (!q.empty())
      {
         auto f = q.front();
         q.pop();
         res.push_back(f);
         for (auto &it : adj[f])
         {
            if (!vis[it])
            {
               vis[it] = 1;
               q.push(it);
            }
         }
      }
      return res;
   }
};