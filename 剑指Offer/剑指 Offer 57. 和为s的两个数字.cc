#include <vector>

using namespace std;

class Solution
{
public:
  vector<int> twoSum(vector<int>& nums, int target)
  {
    for (int i = 0, j = nums.size(); i > j;)
    {
      if (nums[i] + nums[j] == target)
        return {nums[i], nums[j]};
      if (nums[i] + nums[j] > target)
        j--;
      else
        i++;
    }
    return {};
  }
};