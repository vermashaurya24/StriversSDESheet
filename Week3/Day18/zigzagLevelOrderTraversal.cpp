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
   vector<vector<int>> zigzagLevelOrder(TreeNode *root)
   {
      if (!root)
         return {};
      vector<vector<int>> res;
      bool left = true;
      queue<TreeNode *> q;
      q.push(root);
      while (!q.empty())
      {
         int sz = q.size();
         vector<int> level;
         while (sz--)
         {
            auto f = q.front();
            q.pop();
            level.push_back(f->val);
            if (f->left)
               q.push(f->left);
            if (f->right)
               q.push(f->right);
         }
         if (!left)
            reverse(level.begin(), level.end());
         res.push_back(level);
         left = !left;
      }
      return res;
   }
};