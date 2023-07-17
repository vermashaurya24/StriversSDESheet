#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
   bool dfs(int node, vector<int> adj[], vector<int> &vis, vector<int> &curvis)
   {
      vis[node] = 1;
      curvis[node] = 1;
      for (auto &it : adj[node])
      {
         if (vis[it] && curvis[it])
            return true;
         if (!vis[it] && dfs(it, adj, vis, curvis))
            return true;
         ;
      }
      curvis[node] = 0;
      return false;
   }

   bool isCyclic(int n, vector<int> adj[])
   {
      // code here
      vector<int> vis(n, 0);
      vector<int> curvis(n);
      for (int i = 0; i < n; i++)
      {
         if (!vis[i] && dfs(i, adj, vis, curvis))
            return true;
      }
      return false;
   }
};