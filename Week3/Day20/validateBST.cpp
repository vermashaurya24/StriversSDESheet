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
   bool solve(TreeNode *root, TreeNode *minRoot, TreeNode *maxRoot)
   {
      if (!root)
         return true;
      if (minRoot && root->val <= minRoot->val)
         return false;
      if (maxRoot && root->val >= maxRoot->val)
         return false;
      return solve(root->left, minRoot, root) && solve(root->right, root, maxRoot);
   }

   bool isValidBST(TreeNode *root)
   {
      return solve(root, NULL, NULL);
   }
};