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
   int maxDepth(TreeNode *root)
   {
      if (!root)
         return 0;
      // dfs
      //  return 1 + max(maxDepth(root->left), maxDepth(root->right));
      // bfs
      int level = 0;
      queue<TreeNode *> q;
      q.push(root);
      while (!q.empty())
      {
         int sz = q.size();
         while (sz--)
         {
            auto f = q.front();
            q.pop();
            if (f->left)
               q.push(f->left);
            if (f->right)
               q.push(f->right);
         }
         level++;
      }
      return level;
   }
};