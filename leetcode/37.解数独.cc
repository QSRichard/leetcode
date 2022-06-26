#include <ios>
#include <utility>
#include <vector>
#include <algorithm>
#include <cstring>
#include <functional>

using namespace std;

class Solution
{
public:
  void solveSudoku(vector<vector<char>>& board)
  {

    bool end = false;
    bool line[9][9];
    bool clown[9][9];
    bool block[3][3][9];
    memset(line, false, sizeof line);
    memset(clown, false, sizeof clown);
    memset(block, false, sizeof block);
    vector<pair<int, int>> space;

    for (int i = 0; i < board.size(); i++)
    {
      for (int j = 0; j < board[i].size(); j++)
      {
        if (board[i][j] == '.')
          space.push_back({i, j});
        else
        {
          int t = board[i][j] - '1';
          line[i][t] = true;
          clown[j][t] = true;
          block[i / 3][j / 3][t] = true;
        }
      }
    }

    function<void(int)> dfs;
    dfs = [&](int index) {
      if (index == space.size())
      {
        end = true;
        return;
      }

      int i = space[index].first;
      int j = space[index].second;
      for (int t = 0; t < 9 && !end; t++)
      {
        if (!line[i][t] && !clown[j][t] && !block[i / 3][j / 3][t])
        {
          line[i][t] = clown[j][t] = block[i / 3][j / 3][t] = true;
          board[i][j] = '1' + t;
          dfs(index + 1);
          line[i][t] = clown[j][t] = block[i / 3][j / 3][t] = false;
        }
      }
    };
    dfs(0);
  }
};