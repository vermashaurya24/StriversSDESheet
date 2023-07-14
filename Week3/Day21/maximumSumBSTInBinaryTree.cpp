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
   vector<int> no_node = {1, 0, INT_MIN, INT_MAX};
   int res = 0;

   vector<int> solve(TreeNode *root)
   {
      if (!root)
         return no_node;
      auto left = solve(root->left), right = solve(root->right);
      bool isLeft = left[0], isRight = right[0];
      int leftsum = left[1], rightsum = right[1];
      int leftmax = left[2], rightmax = right[2];
      int leftmin = left[3], rightmin = right[3];
      int sum = 0;
      if (isLeft && root->val > leftmax)
         sum += leftsum;
      if (isRight && root->val < rightmin)
         sum += rightsum;
      if (isLeft && isRight && root->val > leftmax && root->val < rightmin)
         sum += root->val;
      res = max(res, sum);
      if (isLeft && isRight && root->val > leftmax && root->val < rightmin)
         return {1, leftsum + rightsum + root->val, max({root->val, leftmax, rightmax}), min({root->val, leftmin, rightmin})};
      return {0, 0, INT_MIN, INT_MAX};
   }

   int maxSumBST(TreeNode *root)
   {
      solve(root);
      return res;
   }
};