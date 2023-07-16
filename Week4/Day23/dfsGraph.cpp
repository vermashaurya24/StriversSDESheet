#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
   void solve(int node, vector<int> adj[], vector<int> &vis, vector<int> &res)
   {
      if (vis[node])
         return;
      vis[node] = 1;
      res.push_back(node);
      for (auto &it : adj[node])
         solve(it, adj, vis, res);
   }

   vector<int> dfsOfGraph(int V, vector<int> adj[])
   {
      // Code here
      vector<int> res;
      vector<int> vis(V, 0);
      solve(0, adj, vis, res);
      return res;
   }
};