#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
  double findMaxAverage(vector<int>& nums, int k)
  {
    int ans = 0;
    for (int i = 0; i < k; i++)
    {
      ans += nums[i];
    }

    int left = 1;
    for (; left < nums.size() - k + 1; left++)
    {
      max(ans, ans - nums[left - 1] + nums[left + k - 1]);
    }
    double ret = (double)ans / k;
    return ret;
  }
};