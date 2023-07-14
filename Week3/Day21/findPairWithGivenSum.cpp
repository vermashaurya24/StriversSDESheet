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
   unordered_set<int> st;

   bool solve(TreeNode *root, int k)
   {
      if (!root)
         return false;
      if (solve(root->left, k))
         return true;
      if (st.count(k - root->val))
         return true;
      st.insert(root->val);
      return solve(root->right, k);
   }

   bool findTarget(TreeNode *root, int k)
   {
      return solve(root, k);
   }
};