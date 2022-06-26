#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
  vector<int> sortArray(vector<int>& nums)
  {
    sort(nums, 0, nums.size());
    return nums;
  }

private:
  void merge(vector<int>& v, int left, int mid, int right)
  {
    vector<int> tmp = v;
    int i = left, j = mid + 1, k = left;
    while (i <= mid && j <= right)
      v[k++] = tmp[i] < tmp[j] ? tmp[i++] : tmp[j++];
    while (i <= mid)
      v[k++] = tmp[i++];
    while (j <= right)
      v[k++] = tmp[j++];
  }

  void merge_sort(vector<int>& v, int left, int right)
  {
    if (left < right)
    {
      int mid = (left + right) / 2;
      merge_sort(v, left, mid);
      merge_sort(v, mid + 1, right);
      merge(v, left, mid, right);
    }
  }
  void sort(vector<int>& nums,int left,int right)
  {
    if (left < right)
    {
      int t = partition(left, right, nums);
      sort(nums, left, t - 1);
      sort(nums, t + 1, right);
    }
  }
  int partition(int left, int right,vector<int>& nums)
  {
    int i = left, j = right;
    int t = rand() % (right - left + 1);
    swap(nums[t + left], nums[left]);
    int pivot = nums[left];
    while (i < j)
    {
      while (i < j && nums[j] >= pivot)
        j--;
      swap(nums[i], nums[j]);
      while (i < j && nums[i] <= pivot)
        i++;
      swap(nums[i], nums[j]);
    }
    nums[i] = pivot;
    return i;
  }
};