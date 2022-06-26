#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  int threeSumClosest(vector<int>& nums, int target)
  {
    sort(nums.begin(), nums.end());
    int ans = 1e9;
    for (int i = 0; i < nums.size() - 2; i++)
    {
      int k = target - nums[i];
      int pb = i + 1, pc = nums.size() - 1;
      while (pb < pc)
      {
        int sum = nums[pb] + nums[pc];
        ans = abs(sum + nums[i] - target) < abs(ans - target) ? sum + nums[i] : ans;
        if (sum < k)
        {
          while (nums[pb + 1] == nums[pb])
            pb++;
        }
        else if (sum > k)
        {
          while (nums[pc - 1] == nums[pc])
            pc--;
        }
        else
        {
          return ans;
        }
      }
    }
    return ans;
  }
};