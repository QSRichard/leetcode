#include <algorithm>
#include <vector>
#include <functional>
#include <iostream>

using namespace std;

class Solution
{
public:
  int search(vector<int>& nums, int target)
  {
    if (nums.empty())
      return 0;
    // 在非递减数组中找到第一个小于等于的index不存在返回-1
    function<int()> low_bound;

    low_bound = [&]() -> int {
      // [left,right]
      int left = 0, right = nums.size() - 1;

      while (left <= right)
      {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target)
        {
          right = mid - 1;
        }
        else if (nums[mid] > target)
        {
          right = mid - 1;
        }
        else if (nums[mid] < target)
        {
          left = mid + 1;
        }
      }
      // 退出while时是 left=right+1;
      return right;
    };

    function<int()> up_bound;
    up_bound = [&]() -> int {
      int left = 0, right = nums.size() - 1;
      while (left <= right)
      {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target)
        {
          left = mid + 1;
        }
        else if (nums[mid] < target)
        {
          left = mid + 1;
        }
        else if (nums[mid] > target)
        {
          right = mid - 1;
        }
      }
      return left;
    };

    int left = low_bound();
    int right = up_bound();
    int ans = right - left - 1;
    if (nums[left] == target)
      ans++;
    if (nums[right] == target)
      ans++;
    return ans;
  }
};

int main(int argc,char* argv[]){
  Solution solution;
  vector<int> v = {5, 7, 7, 8, 8, 10};
  solution.search(v, 8);
  return 0;
}