#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
class Solution
{
public:
queue<int> q;
  vector<vector<int>> threeSum(vector<int>& nums)
  {
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    if (nums[0] > 0)
    {
      return ans;
    }
    for (int i = 0; i < nums.size(); i++)
    {
      if (i > 0 && nums[i - 1] == nums[i])
      {
        continue;
      }
      int left = i + 1;
      int right = nums.size() - 1;
      while (left < right)
      {
        int sum = nums[left] + nums[right];
        if (sum == -nums[i])
        {
          ans.push_back({nums[i], nums[left], nums[right]});
          while (left < right && nums[left + 1] == nums[left])
            left++;
          left++;

          while (left < right && nums[right - 1] == nums[right])
            right--;
          right--;
        }
        else if (sum < -nums[i])
        {
          left++;
        }
        else
        {
          right--;
        }
      }
    }
    return ans;
  }
};

int main()
{
  Solution s;
  vector<int> nums = {0, 0, 0, 0};
  auto ans = s.threeSum(nums);
}