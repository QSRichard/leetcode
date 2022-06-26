#include <algorithm>
#include <functional>

using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution
{
public:
  int kthLargest(TreeNode* root, int k)
  {
    function<void(TreeNode*)> dfs;
    int ans = -1;
    int count = 0;
    dfs = [&](TreeNode* root) {
      if (root == nullptr)
        return;
      if (count > k)
        return;
      dfs(root->left);
      count++;
      if (count == k)
        ans = root->val;
      dfs(root->right);
    };
    dfs(root);
    return ans;
  }
};