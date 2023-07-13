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
   int index;

   unordered_map<int, int> mp;

   TreeNode *solve(vector<int> &inorder, vector<int> &postorder, int left, int right)
   {
      if (left > right)
         return NULL;
      TreeNode *root = new TreeNode(postorder[index]);
      index--;
      root->right = solve(inorder, postorder, mp[root->val] + 1, right);
      root->left = solve(inorder, postorder, left, mp[root->val] - 1);
      return root;
   }

   TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
   {
      int n = inorder.size();
      for (int i = 0; i < n; i++)
         mp[inorder[i]] = i;
      index = n - 1;
      return solve(inorder, postorder, 0, n - 1);
   }
};