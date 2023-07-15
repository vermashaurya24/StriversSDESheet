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

class Solution
{
public:
   // Function to convert binary tree to doubly linked list and return it.
   Node *prev = NULL;
   Node *newHead;

   void solve(Node *root)
   {
      if (!root)
         return;
      solve(root->left);
      if (!prev)
      {
         newHead = root;
      }
      root->left = prev;
      if (prev)
         prev->right = root;
      prev = root;
      solve(root->right);
   }

   Node *bToDLL(Node *root)
   {
      // your code here
      solve(root);
      return newHead;
   }
};