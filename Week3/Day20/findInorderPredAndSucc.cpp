#include <bits/stdc++.h>
using namespace std;

struct Node
{
   int key;
   struct Node *left;
   struct Node *right;

   Node(int x)
   {
      key = x;
      left = NULL;
      right = NULL;
   }
};

class Solution
{
public:
   void findNode(Node *root, Node *&to_set, int key, bool smaller)
   {
      if (!root)
         return;
      if (smaller)
      {
         if (root->key < key)
         {
            to_set = root;
            findNode(root->right, to_set, key, smaller);
         }
         else
         {
            findNode(root->left, to_set, key, smaller);
         }
      }
      else
      {
         if (root->key > key)
         {
            to_set = root;
            findNode(root->left, to_set, key, smaller);
         }
         else
         {
            findNode(root->right, to_set, key, smaller);
         }
      }
   }

   void findPreSuc(Node *root, Node *&pre, Node *&suc, int key)
   {
      // Your code goes here
      findNode(root, pre, key, true);
      findNode(root, suc, key, false);
   }
};