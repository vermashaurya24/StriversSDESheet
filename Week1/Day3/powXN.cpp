#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
   double myPow(double x, int n)
   {
      if (n == 0)
         return 1;
      if (n < 0)
      {
         n = abs(n);
         x = 1 / x;
      }
      // double the base and halve the power. recursion
      return (n % 2) ? x * myPow(x * x, n / 2) : myPow(x * x, n / 2);
   }
};

void main()
{
   double x;
   int n;
   cin >> x >> n;
   Solution solution = *new Solution();
   solution.myPow(x, n);
}