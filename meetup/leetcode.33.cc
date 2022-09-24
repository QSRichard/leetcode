#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
  int search(vector<int>& nums, int target) { return findTarget(nums, 0, nums.size() - 1, target); }

private:
  int findTarget(vector<int>& nums, int left, int right, int target)
  {
    if (left > right)
    {
      return -1;
    }
    int mid = (left + right) / 2;
    if (nums[mid] == target)
    {
      return mid;
    }
    if (nums[mid] > target)
    {
      // 去小处找
      if (nums[mid] >= nums[left])
      {
        int index = findTarget(nums, mid + 1, right, target);
        if (index == -1)
        {
          index = findTarget(nums, left, mid - 1, target);
        }
        return index;
      }
      return findTarget(nums, left, mid - 1, target);
    }
    // 去大处找
    if (nums[mid] > nums[left])
    {
      return findTarget(nums, mid + 1, right, target);
    }
    int index = findTarget(nums, left, mid - 1, target);
    if (index == -1)
    {
      index = findTarget(nums, mid + 1, right, target);
    }
    return index;
  }
};

int main()
{
  Solution s;
  stack<int> sta;
  sta.pop()
  vector<int> nums = {3, 1};
  s.search(nums, 1);
}