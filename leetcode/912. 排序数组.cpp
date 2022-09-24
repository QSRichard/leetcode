#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
  vector<int> sortArray(vector<int>& nums)
  {
    QuickSort(nums);
    return nums;
  }

private:

    void QuickSort(vector<int>& nums)
    {
        shufft(nums);
        QuickSortHelp(nums, 0, nums.size() - 1);
    }
    void shufft(vector<int>& nums)
    {
        int n = nums.size();

        for(int i = 0; i < nums.size(); i++)
        {
            int index = rand() % (nums.size() - i);
            swap(nums[index], nums[nums.size() - i - 1]);
        }
    }

    void QuickSortHelp(vector<int>& nums, int left, int right)
    {
        if(left >= right)
        {
            return;
        }
        int index = parition(nums, left, right);

        QuickSortHelp(nums, left, index - 1);
        QuickSortHelp(nums, index + 1, right);
    }

    int parition(vector<int>& nums, int left, int right)
    {
        int pivotVal = nums[left];

        int i = left;
        int j = right;

        while(j > i)
        {
          while (j > i && nums[j] >= pivotVal)
          {
            j--;
          }

          swap(nums[j], nums[i]);

          while (j > i && nums[i] <= pivotVal)
          {
            i++;
          }
          swap(nums[i], nums[j]);
        }
        nums[i] = pivotVal;
        return i;
    }
};