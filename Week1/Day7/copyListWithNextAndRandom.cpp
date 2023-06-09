#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
   int val;
   Node *next;
   Node *random;
   Node(int _val)
   {
      val = _val;
      next = NULL;
      random = NULL;
   }
};

class Solution
{
public:
   Node *copyRandomList(Node *head)
   {
      if (!head)
         return NULL;
      Node *temp = head;
      while (temp)
      {
         Node *rest = temp->next;
         temp->next = new Node(temp->val);
         temp->next->next = rest;
         temp = rest;
      }
      temp = head;
      while (temp)
      {
         if (temp->random)
            temp->next->random = temp->random->next;
         temp = temp->next->next;
      }
      Node *newHead = new Node(-1), *original = head, *copy = head->next;
      temp = newHead;
      while (original && copy)
      {
         original->next = copy->next;
         temp->next = copy;
         temp = temp->next;
         original = original->next;
         if (copy->next)
            copy = copy->next->next;
      }
      return newHead->next;
   }
};

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
   Solution solution = *new Solution();
   solution.copyRandomList(head);
}