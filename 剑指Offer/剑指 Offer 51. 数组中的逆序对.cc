#include <vector>
#include <iostream>


using namespace std;

class Solution
{
public:
  /* 合并有序数组 */
  int merge(vector<int>& nums, int left, int mid, int right)
  {
    int idx = 0;
    int i = left;
    int j = mid + 1;
    int ans = 0;
    while (i <= mid && j <= right)
    {
      if (nums[i] > nums[j])
      {
        ans += mid - i + 1; /* 统计逆序对 */
        tmp[idx++] = nums[j++];
      }
      else
      {
        tmp[idx++] = nums[i++];
      }
    }

    /* 处理剩余数组 */
    while (i <= mid)
    {
      tmp[idx++] = nums[i++];
    }
    while (j <= right)
    {
      tmp[idx++] = nums[j++];
    }

    /* 写到原数组中 */
    for (int k = 0; k < idx; k++)
    {
      nums[left + k] = tmp[k];
    }
    return ans;
  }

  /* 归并排序 */
  int mergeSort(vector<int>& nums, int l, int r)
  {
    if (l >= r)
    {
      return 0;
    }
    int m = l + (r - l) / 2;
    int revCnt = mergeSort(nums, l, m) + mergeSort(nums, m + 1, r);
    return revCnt + merge(nums, l, m, r);
  }

  int reversePairs(vector<int>& nums)
  {
    int n = nums.size();
    tmp = vector<int>(n);
    return mergeSort(nums, 0, n - 1);
  }
  vector<int> tmp;
};