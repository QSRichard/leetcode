#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  int totalNQueens(int n)
  {
    vector<int> vis(n, 0);
    vector<int> index(n, -1);
    int ans = 0;

    auto isValid = [&](int row, int row_index) -> bool {
      for (int i = 0; i < row; i++)
      {
        if (row - i == abs(index[i] - row_index))
          return false;
      }
      return true;
    };

    function<void(int)> backTrack;
    backTrack = [&](int row) {
      if (row >= n)
      {
        ans++;
        return;
      }
      // 遍历每一列
      for (int j = 0; j < n; j++)
      {
        if (vis[j] == 0 && isValid(row, j))
        {
          vis[j] = 1;
          index[row] = j;
          backTrack(row + 1);
          vis[j] = 0;
          index[row] = -1;
        }
      }
    };

    backTrack(0);
    return ans;
  }
};

int main(int argc,char* argv[]){
  Solution solution;
  cout<<solution.totalNQueens(4)<<endl;
  return 0;
}