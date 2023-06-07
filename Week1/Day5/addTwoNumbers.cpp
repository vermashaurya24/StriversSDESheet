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
   ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
   {
      ListNode *head = new ListNode(-1), *temp = head;
      int carry = 0;
      while (l1 || l2 || carry)
      {
         int sum = 0;
         if (l1)
         {
            sum += l1->val;
            l1 = l1->next;
         }
         if (l2)
         {
            sum += l2->val;
            l2 = l2->next;
         }
         sum += carry;
         temp->next = new ListNode(sum % 10);
         carry = sum / 10;
         temp = temp->next;
      }

      return head->next;
   }
};

void main()
{
   int n;
   cin >> n;
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
   int m;
   cin >> m;
   vector<int> nums2(m);
   for (int i = 0; i < m; i++)
      cin >> nums2[i];
   ListNode *head2 = new ListNode(nums2[0]);
   temp = head2;
   for (int i = 1; i < m; i++)
   {
      temp->next = new ListNode(nums2[i]);
      temp = temp->next;
   }
   Solution solution = *new Solution();
   solution.addTwoNumbers(head1, head2);
}
