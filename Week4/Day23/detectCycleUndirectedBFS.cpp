#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
public:
   // Function to detect cycle in an undirected graph.
   bool bfs(int node, vector<int> adj[], vector<int> &vis)
   {
      vis[node] = 1;
      queue<pair<int, int>> q;
      q.push({node, -1});
      while (!q.empty())
      {
         auto f = q.front();
         q.pop();
         for (auto &it : adj[f.first])
         {
            // if node is visited, and it not its parent, then there is a cycle
            if (vis[it] && it != f.second)
               return true;
            if (it != f.second)
               vis[it] = 1, q.push({it, f.first});
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
         if (!vis[i] && bfs(i, adj, vis))
            return true;
      }
      return false;
   }
};