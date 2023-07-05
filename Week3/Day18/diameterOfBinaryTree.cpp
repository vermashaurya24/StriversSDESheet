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
   int res = 0;

   int solve(TreeNode *root)
   {
      if (!root)
         return 0;
      int left = solve(root->left);
      int right = solve(root->right);
      res = max(res, left + right);
      return max(left, right) + 1;
   }

   int diameterOfBinaryTree(TreeNode *root)
   {
      solve(root);
      return res;
   }
};