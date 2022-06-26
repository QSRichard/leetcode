#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
  int findUnsortedSubarray(vector<int>& nums)
  {
    vector<int> tmp(nums);
    sort(tmp.begin(), tmp.end());
    int left = 0;
    while (left < nums.size() && tmp[left] == nums[left])
      left++;
    int right = nums.size() - 1;
    while (right >= left && tmp[right] == nums[right])
      right--;
    return max(0, right - left + 1);
  }
};