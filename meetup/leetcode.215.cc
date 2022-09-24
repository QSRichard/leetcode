#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  int findKthLargest(vector<int>& nums, int k)
  {
    k--;
    return Dfs(nums, 0, nums.size() - 1, k);
  }

private:
  int Dfs(vector<int>& nums, int left, int right, int k)
  {
    int index = partation(nums, left, right);
    if (index == k)
    {
      return nums[index];
    }
    if (index < k)
    {
      return Dfs(nums, index + 1, right, k);
    }
    return Dfs(nums, left, index - 1, k);
  }
  int partation(vector<int>& nums, int left, int right)
  {
    std::cout << "left: " << left << " right: " << right << std::endl;
    int pivot = left;
    while (right > left)
    {
      while (left < right && nums[right] <= nums[pivot])
        right--;
      while (left < right && nums[left] >= nums[pivot])
        left++;
      std::cout << "left: " << left << "right: " << right << std::endl;
      swap(nums[left], nums[right]);
      for (int i = 0; i < nums.size(); i++)
      {
        std::cout << nums[i] << " ";
      }
      std::cout<<endl;
    }
    swap(nums[pivot], nums[left]);
    std::cout << "left: " << left << std::endl;
    for (int i = 0; i < nums.size(); i++)
    {
      std::cout << nums[i] << " ";
    }
    std::cout << endl;
    return left;
  }
};

int main()
{
  Solution s;
  vector<int> nums = {1, 2, 3, 4, 5, 6};
  s.findKthLargest(nums, 3);
}