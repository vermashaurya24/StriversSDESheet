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
   int index = 0;

   int find(vector<int> &inorder, int target)
   {
      int left = 0, right = inorder.size() - 1;
      while (left <= right)
      {
         int mid = left + (right - left) / 2;
         if (inorder[mid] == target)
            return mid;
         else if (inorder[mid] > target)
            right = mid - 1;
         else
            left = mid + 1;
      }
      return -1;
   }

   TreeNode *solve(vector<int> &preorder, vector<int> &inorder, int left, int right)
   {
      if (left > right)
         return NULL;
      TreeNode *root = new TreeNode(preorder[index]);
      index++;
      int in = find(inorder, root->val);
      root->left = solve(preorder, inorder, left, in - 1);
      root->right = solve(preorder, inorder, in + 1, right);
      return root;
   }

   TreeNode *bstFromPreorder(vector<int> &preorder)
   {
      vector<int> inorder = preorder;
      sort(inorder.begin(), inorder.end());
      int n = preorder.size();
      return solve(preorder, inorder, 0, n - 1);
   }
};