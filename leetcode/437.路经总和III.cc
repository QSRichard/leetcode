#include <algorithm>
#include <exception>
#include <initializer_list>
#include <iostream>
#include <vector>

using namespace std;

struct TreeNode
{
  int val;
  int index;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x, int index_) : val(x), index(index_), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
  int rootSum(TreeNode* root, int targetSum)
  {
    if (!root)
    {
      return 0;
    }

    int ret = 0;
    if (root->val == targetSum)
    {
      ret++;
    }

    ret += rootSum(root->left, targetSum - root->val);
    ret += rootSum(root->right, targetSum - root->val);
    return ret;
  }

  int pathSum(TreeNode* root, int targetSum)
  {
    if (!root)
    {
      return 0;
    }

    int ret = rootSum(root, targetSum);
    ret += pathSum(root->left, targetSum);
    ret += pathSum(root->right, targetSum);
    return ret;
  }
};

int main(int argc, char* argv[])
{

  TreeNode* root = new TreeNode(1, 1);
  root->right = new TreeNode(2, 2);
  root->right->right = new TreeNode(3, 3);
  root->right->right->right = new TreeNode(4, 4);
  root->right->right->right->right = new TreeNode(5, 5);
  Solution solution;
  solution.pathSum(root, 3);
  return 0;
}