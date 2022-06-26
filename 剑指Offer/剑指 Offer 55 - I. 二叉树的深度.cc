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
  int maxDepth(TreeNode* root)
  {
    function<int(TreeNode*)> dfs;
    dfs = [&](TreeNode* root) -> int {
      if (root == nullptr)
        return 0;
      int left = dfs(root->left);
      int right = dfs(root->right);
      return max(left, right) + 1;
    };
    return dfs(root);

  }
};