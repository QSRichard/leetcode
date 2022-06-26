#include <algorithm>
#include <vector>
#include <functional>

using namespace std;

class Node
{
public:
  int val;
  Node* left;
  Node* right;

  Node() {}

  Node(int _val)
  {
    val = _val;
    left = NULL;
    right = NULL;
  }

  Node(int _val, Node* _left, Node* _right)
  {
    val = _val;
    left = _left;
    right = _right;
  }
};
class Solution
{
public:
  Node* treeToDoublyList(Node* root)
  {
    if (root == nullptr)
      return nullptr;
    Node* pre = nullptr;
    Node* head = nullptr;
    function<void(Node*)> dfs = [&](Node* cur) {
      if (cur == nullptr)
        return;
      dfs(cur->left);
      if (pre == nullptr)
        head = cur;
      else
        pre->right = cur;
      cur->left = pre;
      pre = cur;
      dfs(cur->right);
    };
    dfs(root);
    head->left = pre;
    pre->right = head;
    return head;
  }
};