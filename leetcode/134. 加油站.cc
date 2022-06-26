#include <cmath>
#include <vector>
#include <climits>

using namespace std;


class Solution
{
public:
  int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
  {
    int minGas = 0, id = 0;
    int cur = 0;
    for (int i = 0; i < gas.size(); i++)
    {
      cur = cur + gas[i] - cost[i];
      if (cur < minGas)
      {
        minGas = cur;
        id = i;
      }
    }
    return cur < 0 ? -1 : id + 1;
  }
};