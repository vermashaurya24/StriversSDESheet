#include <bits/stdc++.h>
using namespace std;

struct Node
{
   Node *links[2]{};
   bool contains(int bit)
   {
      return links[bit] != NULL;
   }
   void set(int bit, Node *node)
   {
      links[bit] = node;
   }
   Node *get(int bit)
   {
      return links[bit];
   }
};

class Trie
{
public:
   Node *root;
   Trie()
   {
      root = new Node();
   }
   void insert(int num)
   {
      Node *node = root;
      for (int i = 31; i >= 0; i--)
      {
         int bit = (num >> i) & 1;
         if (!node->contains(bit))
         {
            Node *temp = new Node();
            node->set(bit, temp);
         }
         node = node->get(bit);
      }
   }

   int getMax(int num)
   {
      Node *node = root;
      int res = 0;
      for (int i = 31; i >= 0; i--)
      {
         int bit = (num >> i) & 1;
         if (node->contains(1 - bit))
         {
            res |= (1 << i);
            node = node->get(1 - bit);
         }
         else
         {
            node = node->get(bit);
         }
      }
      return res;
   }
};

class Solution
{
public:
   int findMaximumXOR(vector<int> &nums)
   {
      Trie trie = *new Trie();
      for (auto &num : nums)
      {
         trie.insert(num);
      }
      int res = 0;
      for (auto &num : nums)
      {
         res = max(res, trie.getMax(num));
      }
      return res;
   }
};