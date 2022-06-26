#include <vector>

using namespace std;


class Solution
{
public:
  int singleNumber(vector<int>& nums)
  {
    int x = 0;

    int num = 0;
    for (int i = 0; i < 32; i++)
    {
      num = 0;
      for (int j = 0; j < nums.size(); j++)
      {
        num = num + ((nums[j] >> i) & 1);
      }
      num = num % 3;
      if (num)
        x |= (1 << i);
    }
    return x;
  }
};