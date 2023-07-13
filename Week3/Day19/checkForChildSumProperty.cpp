#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
   int data;
   Node *left, *right;
   Node()
   {
      this->data = 0;
      left = NULL;
   }
   Node(int data)
   {
      this->data = data;
      this->left = NULL;
      this->right = NULL;
   }
   Node(int data, Node *left, Node *right)
   {
      this->data = data;
      this->left = left;
      this->right = right;
   }
};

int solve(Node *root)
{
   if (!root)
      return 0;
   if (!root->left && !root->right)
      return root->data;
   int left = solve(root->left);
   if (left == -1)
      return -1;
   int right = solve(root->right);
   if (right == -1)
      return -1;
   return root->data == left + right ? root->data : -1;
}

bool isParentSum(Node *root)
{
   // Write your code here.
   return solve(root) == -1 ? false : true;
}