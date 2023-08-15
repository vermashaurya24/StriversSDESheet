#include <bits/stdc++.h>
using namespace std;

class LRUCache
{
public:
   struct node
   {
      int key;
      int value;
      node *next;
      node *prev;
      node(int k, int v)
      {
         key = k;
         value = v;
         next = NULL;
         prev = NULL;
      }
   };

   node *head = new node(-1, -1);
   node *tail = new node(-1, -1);

   int cap;
   unordered_map<int, node *> mp;

   LRUCache(int capacity)
   {
      cap = capacity;
      head->next = tail;
      tail->prev = head;
   }

   void deletenode(node *temp)
   {
      temp->next->prev = temp->prev;
      temp->prev->next = temp->next;
      // delete temp;
   }

   void addnode(node *temp)
   {
      node *t = head->next;
      temp->next = t;
      temp->prev = head;
      head->next = temp;
      t->prev = temp;
   }

   int get(int key)
   {
      if (!mp.count(key))
         return -1;
      node *res = mp[key];
      int ans = res->value;
      mp.erase(res->key);
      deletenode(res);
      addnode(res);
      mp[key] = head->next;
      return ans;
   }

   void put(int key, int value)
   {
      if (mp.count(key))
      {
         node *existing = mp[key];
         mp.erase(key);
         deletenode(existing);
      }
      if (mp.size() == cap)
      {
         mp.erase(tail->prev->key);
         deletenode(tail->prev);
      }
      addnode(new node(key, value));
      mp[key] = head->next;
   }
};