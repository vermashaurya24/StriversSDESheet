#include <bits/stdc++.h>
using namespace std;

struct Node
{
   int data;
   Node *left, *right;
};

class Solution
{
public:
   void boundary_left(Node *root, vector<int> &res)
   {
      if (!root || !root->left && !root->right)
         return;
      res.push_back(root->data);
      if (root->left)
         boundary_left(root->left, res);
      else
         boundary_left(root->right, res);
   }

   void leaf(Node *root, vector<int> &res)
   {
      if (!root)
         return;
      if (!root->left && !root->right)
         res.push_back(root->data);
      leaf(root->left, res);
      leaf(root->right, res);
   }

   void boundary_right(Node *root, vector<int> &res)
   {
      if (!root || !root->left && !root->right)
         return;
      res.push_back(root->data);
      if (root->right)
         boundary_right(root->right, res);
      else
         boundary_right(root->left, res);
   }

   vector<int> boundary(Node *root)
   {
      // Your code here
      vector<int> res, right;
      res.push_back(root->data);
      boundary_left(root->left, res);
      leaf(root->left, res);
      leaf(root->right, res);
      boundary_right(root->right, right);
      reverse(right.begin(), right.end());
      for (auto &it : right)
         res.push_back(it);
      return res;
   }
};