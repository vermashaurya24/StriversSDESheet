#include <bits/stdc++.h>
using namespace std;

bool canColor(bool graph[101][101], int node, int col, vector<int> &color)
{
   for (int i = 0; i < 101; i++)
   {
      if (i != node && graph[node][i] && color[i] == col)
         return false;
   }
   return true;
}

bool solve(bool graph[101][101], int node, int m, int n, vector<int> &color)
{
   if (node == n)
      return 1;
   for (int i = 0; i < m; i++)
   {
      if (canColor(graph, node, i, color))
      {
         color[node] = i;
         if (solve(graph, node + 1, m, n, color))
            return true;
         color[node] = -1;
      }
   }
   return false;
}

bool graphColoring(bool graph[101][101], int m, int n)
{
   // your code here
   vector<int> color(n, -1);
   return solve(graph, 0, m, n, color);
}