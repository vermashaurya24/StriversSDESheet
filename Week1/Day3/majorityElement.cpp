#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
   int majorityElement(vector<int> &nums)
   {
      // Moore voting algorithm. Every vote will be cancelled out by antivote, leaving the winning vote out.
      int count = 0, elem = nums[0];
      for (auto &num : nums)
      {
         if (count == 0)
         {
            count = 1;
            elem = num;
         }
         else if (num == elem)
            count++;
         else
            count--;
      }
      return elem;
   }
};

void main()
{
   int n;
   cin >> n;
   vector<int> res(n);
   for (int i = 0; i < n; i++)
      cin >> res[i];

   Solution solution = *new Solution();
   solution.majorityElement(res);
}