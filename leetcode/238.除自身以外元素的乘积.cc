#include <vector>

using namespace std;


class Solution
{
public:
  vector<int> productExceptSelf(vector<int>& nums)
  {
    vector<int> left(nums.size() + 1, 0);
    vector<int> right(nums.size() + 1, 0);
    int tmp = 1;
    for (int i = 0; i < nums.size(); i++)
    {
      tmp *= nums[i];
      left[i] = tmp;
    }
    tmp = 1;
    for (int i = nums.size() - 1; i > 0; i--)
    {
      tmp *= nums[i];
      right[i] = tmp;
    }
    vector<int> ans(nums.size(), 0);
    ans[0] = right[1];
    ans[nums.size() - 1] = left[nums.size() - 2];
    for (int i = 1; i < nums.size() - 1; i++)
    {
      ans[i] = left[i - 1] * right[i + 1];
    }
    return ans;
  }
};