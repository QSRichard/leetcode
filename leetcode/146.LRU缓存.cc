#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

struct Node
{
  int key, value;
  struct Node* pre;
  struct Node* next;
  Node() : key(-1), value(-1), pre(nullptr), next(nullptr){};
  Node(int key_, int value_) : key(key_), value(value_), pre(nullptr), next(nullptr) {}
};

class LRUCache
{
private:
  void moveToHead(Node* cur)
  {
    cur->pre->next = cur->next;
    cur->next->pre = cur->pre;
    cur->next = head->next;
    head->next->pre = cur;
    head->next = cur;
    cur->pre=head;
  }

  Node* deleteLast()
  {
    Node* cur = tail->pre;
    cur->pre->next = cur->next;
    cur->next->pre = cur->pre;
    return cur;
  }

  void insertHead(Node* cur)
  {
    cur->next = head->next;
    cur->pre = head;
    head->next->pre = cur;
    head->next = cur;
  }
public:
  LRUCache(int capacity):capacity_(capacity)
  {
    size_ = 0;
    head = new Node();
    tail = new Node();
    head->next = tail;
    tail->pre = head;
  }

  int get(int key)
  {
    if (!mp.count(key))
      return -1;
    Node* tmp = mp[key];
    moveToHead(tmp);
    return tmp->value;
  }

  void put(int key, int value)
  {
    if (mp.count(key) == 1)
    {
      mp[key]->value = value;
      moveToHead(mp[key]);
    }
    else
    {
      Node* cur = new Node(key, value);
      insertHead(cur);
      mp[key] = cur;
      size_++;
      if (size_ > capacity_)
      {
        Node* tmp = deleteLast();
        mp.erase(tmp->key);
        delete tmp;
        size_--;
      }
    }
  }

private:
  unordered_map<int, Node*> mp;
  Node* head;
  Node* tail;
  int capacity_;
  int size_;
};