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

class BSTIterator
{
public:
   stack<TreeNode *> st;

   void pushLeft(TreeNode *root)
   {
      while (root)
      {
         st.push(root);
         root = root->left;
      }
   }

   BSTIterator(TreeNode *root)
   {
      pushLeft(root);
   }

   int next()
   {
      auto f = st.top();
      st.pop();
      pushLeft(f->right);
      return f->val;
   }

   bool hasNext()
   {
      return !st.empty();
   }
};