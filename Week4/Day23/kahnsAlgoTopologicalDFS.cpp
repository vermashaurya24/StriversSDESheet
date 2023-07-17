#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
public:
   // Function to return list containing vertices in Topological order.

   void dfs(int node, vector<int> adj[], vector<int> &vis, stack<int> &st)
   {
      if (vis[node])
         return;
      vis[node] = true;
      for (auto &it : adj[node])
      {
         dfs(it, adj, vis, st);
      }
      st.push(node);
   }

   vector<int> topoSort(int n, vector<int> adj[])
   {
      // code here
      stack<int> st;
      vector<int> vis(n, 0);
      for (int i = 0; i < n; i++)
      {
         if (!vis[i])
            dfs(i, adj, vis, st);
      }
      vector<int> res;
      while (!st.empty())
         res.push_back(st.top()), st.pop();
      return res;
   }
};