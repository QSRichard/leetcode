#include <vector>
#include <unordered_map>

using namespace std;


class Solution
{
public:
  int singleNumber(vector<int>& nums)
  {
    int ans = 0;
    for (int i = 0; i < 32; i++)
    {
      int total = 0;
      for (auto& t : nums)
      {
        total += ((t >> i) & 1);
      }
      if (total % 3)
      {
        ans |= (1<< i);
      }
    }
    return ans;
  }
};