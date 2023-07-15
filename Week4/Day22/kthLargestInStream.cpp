#include <bits/stdc++.h>
using namespace std;

class KthLargest
{
public:
   priority_queue<int, vector<int>, greater<int>> pq;
   int k;
   KthLargest(int K, vector<int> &nums)
   {
      k = K;
      for (auto &num : nums)
      {
         pq.push(num);
         if (pq.size() > k)
            pq.pop();
      }
   }

   int add(int val)
   {
      pq.push(val);
      if (pq.size() > k)
         pq.pop();
      return pq.top();
   }
};

void main()
{
   int n, k, t;
   cin >> n >> k;
   vector<int> res(n);
   for (int i = 0; i < n; i++)
   {
      cin >> res[i];
   }
   KthLargest solution = *new KthLargest(k, res);
   int temp;
   while (t--)
   {
      cin >> temp;
      solution.add(temp);
   }
}