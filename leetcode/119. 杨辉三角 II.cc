#include <vector>

using namespace std;

class Solution
{
public:
  vector<int> getRow(int rowIndex)
  {
    if (rowIndex == 0)
      return {1};
    if (rowIndex == 1)
      return {1, 1};
    vector<int> ret(rowIndex);

    vector<int> pre = {1, 1};
    for (int i = 2; i <= rowIndex; i++)
    {
      vector<int> cur(i + 1);
      cur[0] = 1;
      cur[i] = 1;
      for (int j = 1; j < cur.size()-1; j++)
      {
        cur[j] = pre[j] + pre[j - 1];
      }
      pre = cur;
    }
    return pre;
  }
};