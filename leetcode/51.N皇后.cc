#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution
{
public:
  vector<vector<string>> solveNQueens(int n)
  {
    vector<int> vis(n , 0);
    vector<int> index(n, -1);
    vector<vector<string>> ans;
    int count = 0;
    
    // 对于每一行
    backTrack(0, vis, index, ans);
    // for (auto& item : ans)
    // {
    //   for (auto& i : item)
    //   {
    //     cout<<i<<endl;
    //   }
    //   cout<<"===================="<<endl;
    // }
    return ans;
  }

private:
  
  bool isValid(int row, vector<int> index, int row_index)
  {
    for (int j = 0; j < row; j++)
    {
      if (row - j == abs(index[j] - row_index))
        return false;
    }
    return true;
  }

  void backTrack(int row, vector<int>& vis, vector<int>& index,vector<vector<string>>& ans)
  {
    if (row >= vis.size())
    {
      string base;
      base.append(vis.size(), '.');
      vector<string> item;
      item.reserve(index.size());
      for (int i = 0; i < index.size(); i++)
      {
        string tmp = base;
        tmp[index[i]] = 'Q';
        item.push_back(tmp);
      }
      ans.push_back(item);
      return;
    }

    // 遍历每一列
    for (int j = 0; j < vis.size(); j++)
    {
      // 第row行第j列合法 
      if (vis[j] == 0 && isValid(row, index, j))
      {
        vis[j] = 1;
        index[row] = j;
        backTrack(row + 1, vis, index, ans);
        vis[j] = 0;
        index[row] = -1;
      }
    }
  }
};


int main(int argc,char* argv[]){
  Solution solution;
  solution.solveNQueens(4);
  return 0;
}