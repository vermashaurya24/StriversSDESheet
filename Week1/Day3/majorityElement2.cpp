#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
   vector<int> majorityElement(vector<int> &nums)
   {

      // advanced version of Moore voting algorithm, since every array can have only 2 possible majority elements, we take a vote count. every antivote will reduce the vote of both candidates. at last we do a manual check and verify.
      int c1 = 0, elem1, c2 = 0, elem2, n = nums.size();
      for (auto &num : nums)
      {
         if (c1 == 0 && num != elem2)
         {
            c1 = 1;
            elem1 = num;
         }
         else if (c2 == 0 && num != elem1)
         {
            c2 = 1;
            elem2 = num;
         }
         else if (num == elem1)
            c1++;
         else if (num == elem2)
            c2++;
         else
            c1--, c2--;
      }
      vector<int> res;
      int count = 0;
      for (auto &num : nums)
         count += (num == elem1);
      if (count > n / 3)
         res.push_back(elem1);
      count = 0;
      for (auto &num : nums)
         count += (num == elem2);
      if (count > n / 3)
         res.push_back(elem2);
      return res;
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