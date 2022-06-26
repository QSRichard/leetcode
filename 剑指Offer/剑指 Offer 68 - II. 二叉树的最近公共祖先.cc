#include <vector>
#include <functional>
#include <iostream>

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
    function<void(TreeNode*, TreeNode*, vector<TreeNode*>&)> getpath;
    bool flag = false;
    getpath = [&](TreeNode* rt, TreeNode* target, vector<TreeNode*>& path) {
      if (rt == nullptr || flag)
        return;
      if (rt->val == target->val)
      {
        path.push_back(rt);
        flag = true;
        return;
      }
      path.push_back(rt);
      getpath(rt->left, target, path);
      getpath(rt->right, target, path);
      if (flag == false)
        path.pop_back();
    };

    vector<TreeNode*> path1, path2;
    getpath(root, p, path1);
    flag = false;
    getpath(root, q, path2);
    // cout << path1.size() << path2.size() << endl;
    int i = 0;
    while (i < path1.size() && i < path2.size() && path1[i] == path2[i])
      i++;
    return path1[i - 1];
  }
};