#include <bits/stdc++.h>
using namespace std;

struct Node
{
   int data;
   struct Node *next;
   struct Node *bottom;

   Node(int x)
   {
      data = x;
      next = NULL;
      bottom = NULL;
   }
};

Node *flatten(Node *root)
{
   if (!root->next)
      return root;
   Node *rest = flatten(root->next);
   Node *head = new Node(-1), *temp = head;
   while (root && rest)
   {
      if (root->data < rest->data)
      {
         temp->bottom = root;
         root = root->bottom;
      }
      else
      {
         temp->bottom = rest;
         rest = rest->bottom;
      }
      temp = temp->bottom;
   }
   if (root)
      temp->bottom = root;
   if (rest)
      temp->bottom = rest;
   return head->bottom;
}

void main()
{
   int n;
   cin >> n;
   vector<int> nums(n);
   for (int i = 0; i < n; i++)
      cin >> nums[i];
   Node *head = new Node(nums[0]);
   Node *temp = head;
   for (int i = 1; i < n; i++)
   {
      temp->next = new Node(nums[i]);
      temp = temp->next;
   }
   flatten(head);
}