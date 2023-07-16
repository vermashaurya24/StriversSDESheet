#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
   int val;
   vector<Node *> neighbors;
   Node()
   {
      val = 0;
      neighbors = vector<Node *>();
   }
   Node(int _val)
   {
      val = _val;
      neighbors = vector<Node *>();
   }
   Node(int _val, vector<Node *> _neighbors)
   {
      val = _val;
      neighbors = _neighbors;
   }
};

class Solution
{
public:
   Node *cloneGraph(Node *node)
   {
      if (!node)
         return NULL;
      unordered_map<Node *, Node *> mp;
      mp[node] = new Node(node->val);
      queue<Node *> q;
      q.push(node);
      while (!q.empty())
      {
         auto f = q.front();
         q.pop();
         for (auto &neighbor : f->neighbors)
         {
            if (!mp.count(neighbor))
            {
               mp[neighbor] = new Node(neighbor->val);
               q.push(neighbor);
            }
            mp[f]->neighbors.push_back(mp[neighbor]);
         }
      }
      return mp[node];
   }
};