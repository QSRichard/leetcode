#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
  int firstMissingPositive(vector<int>& nums)
  {
    int n = nums.size();

    for(int i = 0; i < nums.size(); i++)
    {
        if(nums[i] <= 0 || nums[i] > n || nums[i] - 1 == i)
        {
            continue;
        }
        int index1 = i;
        int index2 = nums[index1] - 1;

        if(nums[i] == nums[index2])
        {
            continue;
        }
        swap(nums[index1], nums[index2]);

        while(nums[index1] > 0 && nums[index1] < n && nums[index1] - 1 != index1)
        {

            int t = nums[index1] - 1;
            if(nums[index1] == nums[t])
            {
                break;
            }
            swap(nums[index1], nums[t]);
        }
    }

    for(int i = 0; i < nums.size(); i++)
    {
        if(nums[i] != i + 1)
        {
            return i + 1;
        }
    }
    return n + 1;
  }
};