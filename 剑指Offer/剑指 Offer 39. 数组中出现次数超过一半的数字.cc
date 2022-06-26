#include <vector>

using namespace std;

class Solution
{
public:
  int majorityElement(vector<int>& nums)
  {
    int ans = nums[0];
    int number = 1;
    for (int i = 1; i < nums.size(); i++)
    {
      if (ans == nums[i])
      {
        number++;
      }
      else
      {
        number--;
        if (number == 0)
          ans = nums[i + 1];
      }
    }
    return ans;
  }
};