#include <vector>

using namespace std;

class Solution
{
public:
  int removeDuplicates(vector<int>& nums)
  {
    if (nums.size() <= 2)
      return nums.size();

    int next = 2;
    for (int i = 2; i < nums.size(); i++)
    {
      if (nums[i] == nums[next - 1] && nums[i] == nums[next - 2])
      {
        while (i < nums.size() && nums[i] == nums[next - 1])
          i++;
      }
      if (i < nums.size())
      {
        nums[next] = nums[i];
        next++;
      }
    }
    return next;
  }
};