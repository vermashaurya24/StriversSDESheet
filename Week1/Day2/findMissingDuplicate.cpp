#include <bits/stdc++.h>
using namespace std;
pair<int, int> missingAndRepeating(vector<int> &nums, int n)
{
   // Write your code here
   int i = 0;
   while (i < n)
   {
      int correct = nums[i] - 1;
      if (nums[correct] == nums[i])
         i++;
      else
      {
         swap(nums[correct], nums[i]);
      }
   }
   for (int i = 0; i < n; i++)
   {
      if (nums[i] != i + 1)
         return {i + 1, nums[i]};
   }
   return {-1, -1};
}

void main()
{
   int n;
   cin >> n;
   vector<int> res(n);
   for (int i = 0; i < n; i++)
      cin >> res[i];
   missingAndRepeating(res, n);
}