#include <bits/stdc++.h>
using namespace std;

struct Node
{
   int data;
   struct Node *left;
   struct Node *right;

   Node(int x)
   {
      data = x;
      left = right = NULL;
   }
};

void solve(Node *root, vector<vector<int>> &res)
{
   if (!root)
      return;
   res[1].push_back(root->data);
   solve(root->left, res);
   res[0].push_back(root->data);
   solve(root->right, res);
   res[2].push_back(root->data);
}

vector<vector<int>> getTreeTraversal(Node *root)
{
   // Write your code here.
   vector<vector<int>> res(3);
   solve(root, res);
   return res;
}