#include <vector>

using namespace std;

class Node
{
public:
  int val;
  Node* left;
  Node* right;
  Node* next;

  Node() : val(0), left(NULL), right(NULL), next(NULL) {}

  Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

  Node(int _val, Node* _left, Node* _right, Node* _next) : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution
{
public:
  Node* connect(Node* root)
  {
    if (root == nullptr)
      return nullptr;
    Node* cur = root;
    Node* pre;

    while (cur != nullptr)
    {
      Node* dumy = new Node;
      pre = dumy;
      while (cur != nullptr)
      {
        if (cur->left)
        {
          pre->next = cur->left;
          pre = pre->next;
        }
        if (cur->right)
        {
          pre->next = cur->right;
          pre = pre->next;
        }
        cur = cur->next;
      }
      cur = dumy->next;
    }
    return root;
  }
};