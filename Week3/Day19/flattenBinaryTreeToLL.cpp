#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode() : val(0), left(nullptr), right(nullptr) {}
   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
   TreeNode *prev;

   void solve(TreeNode *root)
   {
      if (!root)
         return;
      solve(root->right);
      solve(root->left);
      root->right = prev;
      root->left = NULL;
      prev = root;
   }

   void flatten(TreeNode *root)
   {
      prev = NULL;
      solve(root);
   }
};