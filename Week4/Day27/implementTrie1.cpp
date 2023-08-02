#include <bits/stdc++.h>
using namespace std;

struct Node
{
   bool flag = false;
   Node *links[26];
   bool containsKey(char c)
   {
      return (links[c - 'a'] != NULL);
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

   void insert(string word)
   {
      Node *node = root;
      for (auto &ch : word)
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

   bool search(string word)
   {
      Node *node = root;
      for (int i = 0; i < word.size(); i++)
      {
         if (!node->containsKey(word[i]))
            return false;
         node = node->get(word[i]);
      }
      return (node->flag);
   }

   bool startsWith(string prefix)
   {
      Node *node = root;
      for (int i = 0; i < prefix.size(); i++)
      {
         if (!node->containsKey(prefix[i]))
         {
            return false;
         }
         node = node->get(prefix[i]);
      }
      return true;
   }
};
