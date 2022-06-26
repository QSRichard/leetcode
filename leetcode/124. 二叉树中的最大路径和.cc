#include <vector>
#include <string>

using namespace std;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };


class Solution
{
public:
  int maxPathSum(TreeNode* root)
  {
    
  }

  int dfs(TreeNode* root)
  {
    int left = getMaxPathSum(root->left);
    int right = getMaxPathSum(root->right);
    return 
  }
  int getMaxPathSum(TreeNode* root)
  {
    if (root == nullptr)
      return 0;
    int left = getMaxPathSum(root);
    int right = getMaxPathSum(root);
    return root->val + max(0, max(left, right));
  }
};