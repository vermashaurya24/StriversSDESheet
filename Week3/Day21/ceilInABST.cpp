#include <bits/stdc++.h>
using namespace std;

template <typename T>
class BinaryTreeNode
{
public:
   T data;
   BinaryTreeNode<T> *left;
   BinaryTreeNode<T> *right;

   BinaryTreeNode(T data)
   {
      this->data = data;
      left = NULL;
      right = NULL;
   }

   ~BinaryTreeNode()
   {
      if (left)
      {
         delete left;
      }
      if (right)
      {
         delete right;
      }
   }
};

void solve(BinaryTreeNode<int> *root, int &res, int x)
{
   if (!root)
      return;
   if (root->data >= x)
      res = min(res, root->data), solve(root->left, res, x);
   else
      solve(root->right, res, x);
}

int findCeil(BinaryTreeNode<int> *node, int x)
{
   // Write your code here.
   int res = INT_MAX;
   solve(node, res, x);
   return res == INT_MAX ? -1 : res;
}