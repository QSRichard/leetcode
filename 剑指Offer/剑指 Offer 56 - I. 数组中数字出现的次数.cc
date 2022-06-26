#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
  vector<int> singleNumbers(vector<int>& nums)
  {
    int tmp = 0;
    for (int i = 0; i < nums.size(); i++)
      tmp ^= nums[i];

    int x = 0, y = 0;
    int div = 1;
    while ((div & tmp) == 0)
      div <<= 1;
    for (int i = 0; i < nums.size(); i++)
    {
      if (div & nums[i])
        x ^= nums[i];
      else
        y ^= nums[i];
    }
    return {x, y};
  }
};