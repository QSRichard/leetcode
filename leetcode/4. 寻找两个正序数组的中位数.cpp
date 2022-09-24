#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution
{
public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
  {
    int index1 = (nums1.size() + nums2.size() + 1) / 2;

    int index2 = (nums1.size() + nums2.size() + 2) / 2; 
    int x = findK(nums1, nums2, 0, nums1.size() - 1, 0, nums2.size() - 1, index1);
    int y = findK(nums1, nums2, 0, nums1.size() - 1, 0, nums2.size() - 1, index2);

    return (x + y) / 2.0;
  }

private:
    // 从两个数组中找到第K个数
    int findK(vector<int>& nums1, vector<int>& nums2, int left1, int right1, int left2, int right2, int k)
    {
        if(left1 > right1)
        {
            return nums2[left2 + k - 1];
        }
        if(left2 > right2)
        {
            return nums1[left1 + k - 1];
        }

        if(k == 1)
        {
            return min(nums2[left2], nums1[left1]);
        }

        int index1 = min(right1, left1 + k / 2 - 1);
        int index2 = min(right2, left2 + k / 2 - 1);
        if(nums1[index1] < nums2[index2])
        {
            return findK(nums1, nums2, index1 + 1, right1, left2, right2, k - (index1 - left1 + 1));
        }
        return findK(nums1, nums2, left1, right1, index2 + 1, right2, k - (index2 - left2 + 1));
    }
};