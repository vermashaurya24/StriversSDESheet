#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
   vector<int> topoSort(int n, vector<int> adj[])
   {
      // code here
      vector<int> indeg(n, 0);
      for (int i = 0; i < n; i++)
      {
         for (int j = 0; j < adj[i].size(); j++)
         {
            indeg[adj[i][j]]++;
         }
      }
      queue<int> q;
      vector<int> res;
      for (int i = 0; i < n; i++)
      {
         if (indeg[i] == 0)
            q.push(i);
      }
      while (!q.empty())
      {
         auto f = q.front();
         q.pop();
         res.push_back(f);
         for (int i = 0; i < adj[f].size(); i++)
         {
            indeg[adj[f][i]]--;
            if (indeg[adj[f][i]] == 0)
               q.push(adj[f][i]);
         }
      }
      return res;
   }
};