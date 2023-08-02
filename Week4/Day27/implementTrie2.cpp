#include <bits/stdc++.h>
using namespace std;

struct Node
{
   int count = 0;
   int ends = 0;
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
      // Write your code here.
      root = new Node();
   }

   void insert(string &word)
   {
      // Write your code here.
      Node *node = root;
      for (auto &ch : word)
      {
         if (!node->containsKey(ch))
         {
            Node *temp = new Node();
            node->put(ch, temp);
         }
         node = node->get(ch);
         node->count++;
      }
      node->ends++;
   }

   int countWordsEqualTo(string &word)
   {
      // Write your code here.
      Node *node = root;
      for (auto &ch : word)
      {
         if (!node->containsKey(ch))
            return 0;
         node = node->get(ch);
      }
      return node->ends;
   }

   int countWordsStartingWith(string &word)
   {
      // Write your code here.
      Node *node = root;
      for (auto &ch : word)
      {
         if (!node->containsKey(ch))
            return 0;
         node = node->get(ch);
      }
      return node->count;
   }

   void erase(string &word)
   {
      // Write your code here.
      Node *node = root;
      for (auto &ch : word)
      {
         node = node->get(ch);
         node->count--;
      }
      node->ends--;
   }
};
