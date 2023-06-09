#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
   int removeDuplicates(vector<int> &nums)
   {
      int n = nums.size(), i = 0, j = 1;
      while (j < n)
      {
         if (nums[j] != nums[j - 1])
         {
            i++;
            nums[i] = nums[j];
            j++;
            while (j < n && nums[j] == nums[j - 1])
               j++;
         }
         else
         {
            j++;
         }
      }
      return i + 1;
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
   solution.removeDuplicates(res);
}