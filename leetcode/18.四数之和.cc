#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
  vector<vector<int>> fourSum(vector<int>& nums, int target)
  {
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size() - 3; i++)
    {
      if (i > 0 && nums[i] == nums[i - 1])
        continue;
      for (int j = i + 1; j < nums.size() - 2; j++)
      {
        if (j > i + 1 && nums[j] == nums[j - 1])
          continue;
        int k = target - nums[i] - nums[j];
        int pc = j + 1, pd = nums.size() - 1;
        while (pc < pd)
        {
          int sum = nums[pc] + nums[pd];
          if (sum == k)
          {
            ans.push_back(vector<int>{nums[i], nums[j], nums[pc], nums[pd]});
            int tc = nums[pc];
            int td = nums[pd];
            while (pc < pd && nums[pc] == tc)
              pc++;
            while (pc < pd && nums[pd] == td)
              pd--;
          }
          else if (sum < k)
          {
            int tc = nums[pc];
            while (pc<pd && nums[pc] == tc)
              pc++;
          }
          else if (sum > k)
          {
            int td = nums[pd];
            while (pc < pd && nums[pd] == td)
              pd--;
          }
        }
      }
    }
    return ans;
  }
};

