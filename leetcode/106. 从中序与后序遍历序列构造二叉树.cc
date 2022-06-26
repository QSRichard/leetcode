#include <new>
#include <vector>

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
  TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
  {
    return help(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
  }

private:
  TreeNode* help(vector<int>& inorder, vector<int>& postorder, int inLeft, int inRight, int postLeft, int postRight)
  {
    if (postLeft == postRight)
    {
      TreeNode* root = new TreeNode(postorder[postLeft]);
      return root;
    }
    if (postLeft > postRight)
      return nullptr;
    int rootIndex = inLeft;
    while (inorder[rootIndex] != postorder[postRight])
      rootIndex++;
    int leftNum = rootIndex - inLeft;
    int rightNum = inRight - rootIndex;
    TreeNode* root = new TreeNode(postorder[postRight]);
    root->left = help(inorder, postorder, inLeft, rootIndex - 1, postLeft, postLeft + leftNum - 1);
    root->right = help(inorder, postorder, rootIndex + 1, inRight, postLeft + leftNum, postRight - 1);
    return root;
  }
};