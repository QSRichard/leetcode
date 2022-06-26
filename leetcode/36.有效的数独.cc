#include <algorithm>
#include <cctype>
#include <iterator>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
  bool isValidSudoku(vector<vector<char>>& board)
  {
    vector<int> base(10, 0);

    // 判断行
    for (int i = 0; i < board.size(); i++)
    {
      for (int j = 0; j < board[i].size(); j++)
      {
        if (isalnum(board[i][j]))
        {
          if (base[board[i][j] - '0'])
            return false;
          base[board[i][j] - '0'] = 1;
        }
      }
      fill(base.begin(), base.end(), 0);
    }

    // 判断列
    for (int i = 0; i < board[0].size(); i++)
    {
      for (int j = 0; j < board.size(); j++)
      {
        if (isalnum(board[j][i]))
        {
          if (base[board[j][i] - '0'])
            return false;
          base[board[j][i]-'0'] = 1;
        }
      }
      fill(base.begin(), base.end(), 0);
    }

    vector<int> x_step = {0, 0, 0, 1, -1, 1, 1, -1, -1};
    vector<int> y_step = {0, 1, -1, 0, 0, 1, -1, 1, -1};

    vector<int> center_x_step = {0, 0, 0, 3, -3, -3, -3, 3, 3};
    vector<int> center_y_step = {0, 3, -3, 0, 0, -3, 3, -3, 3};

    int len = 9;

    auto help = [&board, &x_step, &y_step, len, &base](int center_x, int center_y) -> bool {
      char tmp;
      for (int i = 0; i < len; i++)
      {
        tmp = board[center_x + x_step[i]][center_y + y_step[i]];
        if (tmp != '.')
        {
          if (base[tmp - '0'])
            return false;
          base[tmp - '0'] = 1;
        }
      }
      fill(base.begin(), base.end(), 0);
      return true;
    };

    for (int i = 0; i < len; i++)
    {
      if (help(4 + center_x_step[i], 4 + center_y_step[i]) == false)
        return false;
    }
    return true;
  }
};

int main(int argc, char* argv[])
{
  Solution solution;
  return 0;
}