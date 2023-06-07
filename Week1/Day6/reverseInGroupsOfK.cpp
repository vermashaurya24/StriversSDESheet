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

   ListNode *solve(ListNode *head, int length, int k)
   {
      if (length < k)
         return head;
      length -= k;
      ListNode *prev = NULL, *cur = head, *nxt;
      for (int i = 0; i < k; i++)
      {
         nxt = cur->next;
         cur->next = prev;
         prev = cur;
         cur = nxt;
      }
      head->next = solve(cur, length, k);
      return prev;
   }

   ListNode *reverseKGroup(ListNode *head, int k)
   {
      int length = len(head);
      return solve(head, length, k);
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
   solution.reverseKGroup(head, k);
}