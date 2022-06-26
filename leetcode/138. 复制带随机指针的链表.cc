#include <map>
#include <vector>

using namespace std;

class Node
{
public:
  int val;
  Node* next;
  Node* random;

  Node(int _val)
  {
    val = _val;
    next = NULL;
    random = NULL;
  }
};

class Solution
{
public:
  Node* copyRandomList(Node* head)
  {
    if (head == nullptr)
      return nullptr;
    map<Node*, Node*> mp;
    Node* cur = head;
    Node* newHead = nullptr;
    Node* pre = nullptr;
    while (cur)
    {
      Node* node = new Node(cur->val);
      mp[cur] = node;
      if (pre)
      {
        pre->next = node;
        newHead = node;
      }
      pre = node;
      cur = cur->next;
    }
    cur = head;
    Node* newcur = newHead;
    while (cur)
    {
      if (cur->random != nullptr)
      {
        newcur->random = mp[cur->random];
      }
      cur = cur->next;
      newcur = newcur->next;
    }
    return newHead;
  }
};