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
   unordered_map<int, int> mp;
   int index = 0;

   TreeNode *solve(vector<int> &preorder, vector<int> &inorder, int left, int right)
   {
      if (left > right)
         return NULL;
      TreeNode *root = new TreeNode(preorder[index]);
      index++;
      root->left = solve(preorder, inorder, left, mp[root->val] - 1);
      root->right = solve(preorder, inorder, mp[root->val] + 1, right);
      return root;
   }

   TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
   {
      int n = preorder.size();
      for (int i = 0; i < n; i++)
         mp[inorder[i]] = i;
      return solve(preorder, inorder, 0, n - 1);
   }
};