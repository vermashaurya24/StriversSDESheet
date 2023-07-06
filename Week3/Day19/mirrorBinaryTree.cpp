#include <bits/stdc++.h>
using namespace std;

struct Node
{
   int val;
   Node *left;
   Node *right;
   Node() : val(0), left(nullptr), right(nullptr) {}
   Node(int x) : val(x), left(nullptr), right(nullptr) {}
   Node(int x, Node *left, Node *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
   // Function to convert a binary tree into its mirror tree.

   void mirror(Node *node)
   {
      // code here
      if (!node)
         return;
      Node *temp = node->left;
      node->left = node->right;
      node->right = temp;
      mirror(node->left);
      mirror(node->right);
   }
};