
#include <queue>
#include <vector>

using namespace std;

struct TreeNode
{
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
  vector<vector<int>> zigzagLevelOrder(TreeNode* root)
  {
    vector<TreeNode*> tmp;
    vector<vector<int>> ans;
    if (root == nullptr)
      return ans;

    queue<TreeNode*> node;

    bool isLeft = true;
    node.push(root);
    while (!node.empty())
    {
      deque<int> dq;
      int size = node.size();
      while (size--)
      {
        auto cur = node.front();
        node.pop();
        if (isLeft)
        {
          dq.push_front(cur->val);
        }
        else
        {
          dq.push_back(cur->val);
        }
        if (cur->left)
          node.push(cur->left);
        if (cur->right)
          node.push(cur->right);
      }
      ans.push_back({dq.begin(), dq.end()});
      dq.clear();
      isLeft = !isLeft;
    }
    return ans;
  }
};