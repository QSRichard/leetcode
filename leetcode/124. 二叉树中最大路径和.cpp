#include <cmath>
#include <ios>
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

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
    Dfs(root);
    return ans;
  }

private:
    int ans = INT_MIN;
    int Dfs(TreeNode* root)
    {
        if(root->left == nullptr && root->right == nullptr)
        {
            ans = max(ans, root->val);
            return root->val;
        }
        int left = 0;
        int right = 0;
        if(root->left)
        {
          left = Dfs(root->left);
        }
        if(root->right)
        {
            right = Dfs(root->right);
        }

        if(left > 0 && right > 0)
        {
            ans = max(ans, left + right + root->val);
        }
        ans = max(ans, max(root->val + left + right,max(root->val + right, root->val + left)));
        
        return max(root->val + max(left, right), root->val);
    }
};