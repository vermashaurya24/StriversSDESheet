#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
public:
   // Function to detect cycle in an undirected graph.
   bool dfs(int node, int parent, vector<int> adj[], vector<int> &vis)
   {
      vis[node] = 1;
      for (auto &it : adj[node])
      {
         if (vis[it] && it != parent)
            return true;
         if (it != parent)
         {
            if (dfs(it, node, adj, vis))
               return true;
         }
      }
      return false;
   }

   bool isCycle(int n, vector<int> adj[])
   {
      // Code here
      vector<int> vis(n, 0);
      for (int i = 0; i < n; i++)
      {
         if (!vis[i] && dfs(i, -1, adj, vis))
            return true;
      }
      return false;
   }
};