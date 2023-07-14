#include <bits/stdc++.h>
using namespace std;

template <typename T>
class TreeNode
{
public:
   T val;
   TreeNode<T> *left;
   TreeNode<T> *right;

   TreeNode(T val)
   {
      this->val = val;
      left = NULL;
      right = NULL;
   }
};

void solve(TreeNode<int> *root, int x, int &res)
{
   if (!root)
      return;
   if (root->val <= x)
      res = max(res, root->val), solve(root->right, x, res);
   else
      solve(root->left, x, res);
}

int floorInBST(TreeNode<int> *root, int X)
{
   // Write your code here.
   int res = 0;
   solve(root, X, res);
   return res;
}