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

void solve(Node *root, int level, map<int, int> &mp)
{
   if (!root)
      return;
   if (!mp.count(level))
   {
      mp[level] = root->data;
   }
   solve(root->left, level + 1, mp);
   solve(root->right, level + 1, mp);
}

vector<int> leftView(Node *root)
{
   // Your code here
   map<int, int> mp;
   solve(root, 0, mp);
   vector<int> res;
   for (auto &it : mp)
      res.push_back(it.second);
   return res;
}