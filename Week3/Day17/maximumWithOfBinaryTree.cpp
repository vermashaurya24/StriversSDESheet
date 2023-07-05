#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
   int data;
   struct TreeNode *left;
   struct TreeNode *right;

   TreeNode(int x)
   {
      data = x;
      left = right = NULL;
   }
};

class Solution
{
public:
   // Function to return a list of nodes visible from the top view
   // from left to right in Binary Tree.
   int widthOfBinaryTree(TreeNode *root)
   {
      long res = 0;
      queue<pair<TreeNode *, long>> q;
      q.push({root, 1});
      while (!q.empty())
      {
         int sz = q.size();
         int first = -1;
         while (sz--)
         {
            auto f = q.front();
            q.pop();
            TreeNode *node = f.first;
            long number = f.second;
            if (first == -1)
               first = number;
            else
               res = max(res, number - first);
            number -= first;
            if (node->left)
               q.push({node->left, number * 2});
            if (node->right)
               q.push({node->right, (number * 2) + 1});
         }
      }
      return res + 1;
   }
};