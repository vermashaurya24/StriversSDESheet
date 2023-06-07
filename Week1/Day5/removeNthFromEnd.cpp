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
   ListNode *removeNthFromEnd(ListNode *head, int n)
   {
      ListNode *fast = head, *slow = head;
      while (n--)
         fast = fast->next;
      if (!fast)
         return head->next;
      while (fast->next)
      {
         fast = fast->next;
         slow = slow->next;
      }
      slow->next = slow->next->next;
      return head;
   }
};

void main()
{
   int n, k;
   cin >> n >> k;
   vector<int> nums(n);
   for (int i = 0; i < n; i++)
      cin >> nums[i];
   ListNode *head1 = new ListNode(nums[0]);
   ListNode *temp = head1;
   for (int i = 1; i < n; i++)
   {
      temp->next = new ListNode(nums[i]);
      temp = temp->next;
   }
   Solution solution = *new Solution();
   solution.removeNthFromEnd(head1, k);
}
