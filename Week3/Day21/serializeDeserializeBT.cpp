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

class Codec
{
public:
   string get(string s, int &index)
   {
      string t = "";
      int n = s.size();
      while (index < n && s[index] != '#')
         t += s[index++];
      index++;
      return (t.empty() ? "#" : t);
   }

   // Encodes a tree to a single string.
   string serialize(TreeNode *root)
   {
      // if(!root)   return "#";
      string s = "";
      queue<TreeNode *> q;
      q.push(root);
      while (!q.empty())
      {
         auto f = q.front();
         q.pop();
         if (!f)
            s += 'N';
         else
            s += to_string(f->val);
         s += '#';
         if (f)
            q.push(f->left);
         if (f)
            q.push(f->right);
      }
      return s;
   }

   // Decodes your encoded data to tree.
   TreeNode *deserialize(string data)
   {
      int index = 0;
      string first = get(data, index);
      if (first == "N")
         return NULL;
      TreeNode *root = new TreeNode(stoi(first));
      queue<TreeNode *> q;
      q.push(root);
      while (!q.empty())
      {
         auto f = q.front();
         q.pop();
         first = get(data, index);
         if (first == "N")
            f->left = NULL;
         else
         {
            f->left = new TreeNode(stoi(first));
            q.push(f->left);
         }
         first = get(data, index);
         if (first == "N")
         {
            f->right = NULL;
         }
         else
         {
            f->right = new TreeNode(stoi(first));
            q.push(f->right);
         }
      }
      return root;
   }
};