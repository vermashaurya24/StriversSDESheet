#include <bits/stdc++.h>
using namespace std;

struct Node
{
   int data;
   struct Node *left;
   struct Node *right;

   Node(int x)
   {
      data = x;
      left = right = NULL;
   }
};

class Solution
{
public:
   vector<int> bottomView(Node *root)
   {
      // Your Code Here
      vector<int> res;
      queue<pair<Node *, int>> q;
      q.push({root, 0});
      map<int, int> mp;
      while (!q.empty())
      {
         auto f = q.front();
         q.pop();
         Node *node = f.first;
         int level = f.second;
         mp[level] = node->data;
         if (node->left)
         {
            q.push({node->left, level - 1});
         }
         if (node->right)
         {
            q.push({node->right, level + 1});
         }
      }
      for (auto &it : mp)
         res.push_back(it.second);
      return res;
   }
};