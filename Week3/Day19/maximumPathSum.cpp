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
   int res;

   int solve(TreeNode *root)
   {
      if (!root)
         return 0;
      int left = max(0, solve(root->left));
      int right = max(0, solve(root->right));
      res = max(res, left + right + root->val);
      return max(left, right) + root->val;
   }

   int maxPathSum(TreeNode *root)
   {
      res = INT_MIN;
      solve(root);
      return res;
   }
};