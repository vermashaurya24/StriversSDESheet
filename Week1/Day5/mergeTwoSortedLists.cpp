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
   ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
   {
      ListNode *nH = new ListNode(-1), *temp = nH;
      while (list1 && list2)
      {
         if (list1->val < list2->val)
         {
            temp->next = list1;
            list1 = list1->next;
         }
         else
         {
            temp->next = list2;
            list2 = list2->next;
         }
         temp = temp->next;
      }
      if (list1)
         temp->next = list1;
      if (list2)
         temp->next = list2;
      return nH->next;
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
   solution.mergeTwoLists(head1, head2);
}
