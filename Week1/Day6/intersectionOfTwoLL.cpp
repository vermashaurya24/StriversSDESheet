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
   ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
   {
      ListNode *temp1 = headA, *temp2 = headB;
      while (temp1 && temp2)
      {
         temp1 = temp1->next;
         temp2 = temp2->next;
      }
      if (!temp1)
      {
         temp1 = headB;
         while (temp2)
         {
            temp2 = temp2->next;
            temp1 = temp1->next;
         }
         temp2 = headA;
      }
      else
      {
         temp2 = headA;
         while (temp1)
         {
            temp1 = temp1->next;
            temp2 = temp2->next;
         }
         temp1 = headB;
      }
      while (temp1 != temp2)
      {
         temp1 = temp1->next;
         temp2 = temp2->next;
      }
      return temp1;
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
   solution.getIntersectionNode(head1, head2);
}
