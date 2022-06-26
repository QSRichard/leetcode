#include <algorithm>
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
  bool isBalanced(TreeNode* root)
  {
    function<int(TreeNode*)> getHeight;
    getHeight = [&](TreeNode* root) -> int {
      if (root == nullptr)
        return 0;
      int left = getHeight(root->left);
      int right = getHeight(root->right);
      if (left == -1 || right == -1 || abs(left - right) > 1)
        return -1;
      return max(getHeight(root->left), getHeight(root->right)) + 1;
    };
    return getHeight(root) >= 0;
  }
};