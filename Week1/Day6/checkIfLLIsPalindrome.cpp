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
   ListNode *findMid(ListNode *head)
   {
      ListNode *slow = head, *fast = head;
      while (fast && fast->next)
      {
         slow = slow->next;
         fast = fast->next->next;
      }
      return slow;
   }

   ListNode *reverseList(ListNode *&node)
   {
      ListNode *prev = NULL, *cur = node, *nxt;
      while (cur)
      {
         nxt = cur->next;
         cur->next = prev;
         prev = cur;
         cur = nxt;
      }
      return prev;
   }

   bool isPalindrome(ListNode *head)
   {
      ListNode *middle = findMid(head);
      middle = reverseList(middle);
      while (head && middle)
      {
         if (head->val != middle->val)
            return false;
         head = head->next;
         middle = middle->next;
      }
      return true;
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
   solution.isPalindrome(head);
}