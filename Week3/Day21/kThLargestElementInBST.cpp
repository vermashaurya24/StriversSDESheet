#include <bits/stdc++.h>
using namespace std;

struct Node
{
   int data;
   Node *left;
   Node *right;

   Node(int val)
   {
      data = val;
      left = right = NULL;
   }
};

class Solution
{
public:
   void solve(Node *root, int &k, int &res)
   {
      if (!root)
         return;
      solve(root->right, k, res);
      k--;
      if (!k)
         res = root->data;
      if (k > 0)
         solve(root->left, k, res);
   }

   int kthLargest(Node *root, int K)
   {
      // Your code here
      int res;
      solve(root, K, res);
      return res;
   }
};