#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
  bool isStraight(vector<int>& nums)
  {

    sort(nums.begin(), nums.end());
    int zero = 0;
    int begin = 0;
    while (begin < nums.size() && nums[begin] == 0)
      begin++;
    zero = begin;
    for (int i = begin; i < nums.size(); i++)
    {
      if (i != begin)
      {
        if (nums[i] == nums[i-1])
          return false;
        zero -= (nums[i] - nums[i - 1] - 1);
      }
    }
    return zero >= 0;
  }
};