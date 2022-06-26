#include <vector>
#include <string>

using namespace std;


class Solution
{
public:
  vector<vector<int>> generateMatrix(int n)
  {
    int number = 1, len = n * n;
    vector<vector<int>> ans(n, vector<int>(n, 0));
    vector<int> r_step = {0, 1, 0, -1};
    vector<int> c_step = {1, 0, -1, 0};
    int row = n, clown = n;
    int r = 0, c = -1, loop = 0;
    while (number <= len)
    {
      for (int i = 0; i < clown; i++)
      {
        ans[r += r_step[loop]][c += c_step[loop]] = number++;
      }
      loop = (loop + 1) % 4;
      row--;
      if (number > len)
        break;
      for (int i = 0; i < row; i++)
      {
        ans[r += r_step[loop]][c += c_step[loop]] = number++;
      }
      loop = (loop + 1) % 4;
      clown--;
    }
    return ans;
  }
};