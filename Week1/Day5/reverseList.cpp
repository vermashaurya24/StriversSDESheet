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
   ListNode *solve(ListNode *head, ListNode *prev)
   {
      if (!head)
         return head;
      if (!head->next)
      {
         head->next = prev;
         return head;
      }
      ListNode *newHead = solve(head->next, head);
      head->next = prev;
      return newHead;
   }

   ListNode *reverseList(ListNode *head)
   {
      return solve(head, NULL);
   }
};

void main()
{
   int n;
   cin >> n;
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
   solution.reverseList(head);
}
