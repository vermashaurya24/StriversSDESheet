#include <bits/stdc++.h>
using namespace std;

struct Node
{
   Node *links[26];
   bool flag = false;
   bool containsKey(char ch)
   {
      return links[ch - 'a'] != NULL;
   }
   void put(char ch, Node *node)
   {
      links[ch - 'a'] = node;
   }
   Node *get(char ch)
   {
      return links[ch - 'a'];
   }
};

class Trie
{
   Node *root;

public:
   Trie()
   {
      root = new Node();
   }

   void insert(string &s)
   {
      Node *node = root;
      for (auto &ch : s)
      {
         if (!node->containsKey(ch))
         {
            Node *temp = new Node();
            node->put(ch, temp);
         }
         node = node->get(ch);
      }
      node->flag = true;
   }

   bool contains(string &s)
   {
      Node *node = root;
      for (auto &ch : s)
      {
         if (!node->containsKey(ch))
            return false;
         node = node->get(ch);
         if (!node->flag)
            return false;
      }
      return node->flag;
   }
};

string completeString(int n, vector<string> &a)
{
   // Write your code here.
   string res = "";
   Trie trie = *new Trie();
   for (auto &str : a)
   {
      trie.insert(str);
   }
   for (auto &str : a)
   {
      if (trie.contains(str))
      {
         if (res.size() < str.size())
            res = str;
         else if (str.size() == res.size() && str < res)
            res = str;
      }
   }
   return res.empty() ? "None" : res;
}