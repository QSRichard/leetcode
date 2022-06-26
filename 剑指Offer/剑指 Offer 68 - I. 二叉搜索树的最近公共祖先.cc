#include <stack>
#include <vector>
#include <functional>

using namespace std;

struct TreeNode
{
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
  {
    stack<TreeNode*> s1;
    stack<TreeNode*> s2;

    function<void(stack<TreeNode*>&, TreeNode*)> find;
    find = [&](stack<TreeNode*>& s, TreeNode* target) {
      TreeNode* cur = root;
      while (true)
      {
        if (cur->val < target->val)
        {
          s.push(cur);
          cur = cur->right;
        }
        else if (cur->val > target->val)
        {
          s.push(cur);
          cur = cur->left;
        }
        else
        {
          s.push(cur);
          break;
        }
      }
    };
    find(s1, p);
    find(s2, q);
    auto fast = s1.size() > s2.size() ? s1 : s2;
    auto slow = s1.size() > s2.size() ? s2 : s1;
    int num = fast.size() - slow.size();
    while (num--)
      fast.pop();
    while (!fast.empty())
    {
      if (fast.top() == slow.top())
        return fast.top();
      fast.pop();
      slow.pop();
    }
    return nullptr;
  }
};