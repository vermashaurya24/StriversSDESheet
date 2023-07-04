#include <bits/stdc++.h>
using namespace std;

template <typename T = int>
class TreeNode
{
public:
   T data;
   TreeNode<T> *left;
   TreeNode<T> *right;

   TreeNode(T data)
   {
      this->data = data;
      left = NULL;
      right = NULL;
   }

   ~TreeNode()
   {
      if (left != NULL)
      {
         delete left;
      }
      if (right != NULL)
      {
         delete right;
      }
   }
};

bool solve(TreeNode<int> *root, int target, vector<int> &res)
{
   if (!root)
      return false;
   res.push_back(root->data);
   if (root->data == target)
      return true;
   bool left = solve(root->left, target, res);
   if (left)
      return true;
   bool right = solve(root->right, target, res);
   if (right)
      return true;
   res.pop_back();
   return false;
}

vector<int> pathInATree(TreeNode<int> *root, int x)
{
   // Write your code here.
   vector<int> res;
   solve(root, x, res);
   return res;
}