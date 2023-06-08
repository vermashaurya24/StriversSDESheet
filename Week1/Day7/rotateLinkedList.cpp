#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
   int val;
   ListNode *next;
   ListNode() : val(0), next(nullptr) {}
   ListNode(int x) : val(x), next(nullptr) {}
   ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
   int len(ListNode *head)
   {
      if (!head)
         return 0;
      return 1 + len(head->next);
   }

   ListNode *rotateRight(ListNode *head, int k)
   {
      int length = len(head);
      if (!length)
         return head;
      k = k % length;
      if (!head || !k)
         return head;
      ListNode *fast = head, *slow = head;
      for (int i = 0; i < (length - k); i++)
      {
         slow = fast;
         fast = fast->next;
      }
      ListNode *tail = fast;
      while (tail->next)
         tail = tail->next;
      tail->next = head;
      slow->next = NULL;
      return fast;
   }
};

void main()
{
   int n, k;
   cin >> n >> k;
   vector<int> nums(n);
   for (int i = 0; i < n; i++)
      cin >> nums[i];
   ListNode *head = new ListNode(nums[0]);
   ListNode *temp = head;
   for (int i = 1; i < n; i++)
   {
      temp->next = new ListNode(nums[i]);
      temp = temp->next;
   }
   Solution solution = *new Solution();
   solution.rotateRight(head, k);
}