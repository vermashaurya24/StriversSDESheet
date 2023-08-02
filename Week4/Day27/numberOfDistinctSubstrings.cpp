#include <bits/stdc++.h>
using namespace std;

struct Node
{
   Node *links[26];
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
   int insert(string &str)
   {
      Node *node = root;
      int count = 0;
      for (auto &ch : str)
      {
         if (!node->containsKey(ch))
         {
            Node *temp = new Node();
            node->put(ch, temp);
            count++;
         }
         node = node->get(ch);
      }
      return count;
   }
};

int countDistinctSubstring(string s)
{
   // Your code here
   int res = 0, n = s.size();
   Trie trie = *new Trie();
   for (int i = 0; i < n; i++)
   {
      string t = s.substr(i);
      res += trie.insert(t);
   }
   return res + 1;
}