#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode() : val(0), left(nullptr), right(nullptr) {}
   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
   void solve(TreeNode *root, int x, int y, map<int, map<int, multiset<int>>> &mp)
   {
      if (!root)
         return;
      mp[x][y].insert(root->val);
      solve(root->left, x + 1, y - 1, mp);
      solve(root->right, x + 1, y + 1, mp);
   }

   vector<vector<int>> verticalTraversal(TreeNode *root)
   {
      map<int, map<int, multiset<int>>> mp;
      solve(root, 0, 0, mp);
      vector<vector<int>> res;
      map<int, vector<int>> temp;
      for (auto &it : mp)
      {
         for (auto &itr : it.second)
         {
            int level = itr.first;
            for (auto &iter : itr.second)
               temp[level].push_back(iter);
         }
      }
      for (auto &it : temp)
         res.push_back(it.second);
      return res;
   }
};