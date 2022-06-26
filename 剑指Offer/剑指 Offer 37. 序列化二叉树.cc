#include <cctype>
#include <cstdlib>
#include <iostream>
#include <new>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;




 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Codec
{
public:
  // Encodes a tree to a single string.
  string serialize(TreeNode* root)
  {
    string ans = "";
    function<void(TreeNode*)> dfs = [&](TreeNode* cur) {
      if (cur == nullptr)
      {
        ans.append("null,");
        return;
      }
      ans.append(to_string(cur->val) + ",");
      dfs(cur->left);
      dfs(cur->right);
    };
    ans.pop_back();
    cout<<ans<<endl;
    return ans;
  }

  // Decodes your encoded data to tree.
  TreeNode* deserialize(string data)
  {
    if (data.empty())
      return nullptr;
    vector<TreeNode*> nodes;
    for (int i = 0; i < data.size();)
    {
      if (isdigit(data[i]) == false)
      {
        nodes.push_back(nullptr);
        i += 5;
      }
      else
      {
        int j = i;
        while (j < data.size() && data[j] != ',')
          j++;
        nodes.push_back(new TreeNode(stoi(data.substr(i, j))));
        i = j + 1;
      }
    }

    function<TreeNode*(int& index)> dfs = [&](int& index) -> TreeNode* {
      if (index >= nodes.size())
        return nullptr;
      if (nodes[index] == nullptr)
        return nullptr;
      TreeNode* cur = nodes[index];
      index++;
      cur->left = dfs(index);
      cur->right = dfs(index);
      return cur;
    };
    int index = 0;
    return dfs(index);
  }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));