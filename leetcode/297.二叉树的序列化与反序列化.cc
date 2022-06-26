#include <cstdlib>
#include <vector>
#include <string>
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
  void help_ser(TreeNode* root, string& str)
  {
    if (root == nullptr)
    {
      str += "None,";
      return;
    }
    str += to_string(root->val) + ",";
    help_ser(root->left, str);
    help_ser(root->right, str);
  }
  // Encodes a tree to a single string.
  string serialize(TreeNode* root)
  {
    string ans;
    help_ser(root, ans);
    return ans;
  }

  TreeNode* construct_tree(vector<string> item)
  {
    if (item.front() == "None")
    {
      item.erase(item.begin());
      return nullptr;
    }
    TreeNode* root = new TreeNode(stoi(item.front()));
    item.erase(item.begin());
    root->left = construct_tree(item);
    root->left = construct_tree(item);
    return root;
  }
  // Decodes your encoded data to tree.
  TreeNode* deserialize(string data)
  {
    vector<string> items;
    string str;
    for (int i = 0; i < data.size(); i++)
    {
      if (data[i] == ',')
      {
        items.push_back(str);
        str.clear();
      }
      else
      {
        str.push_back(data[i]);
      }
    }
    if (str.empty() == false)
      items.push_back(str);
    return construct_tree(items);
    
  }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));