#include <vector>
#include <iostream>
#include <map>
#include <stack>

using namespace std;

class Solution
{
public:
  vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2)
  {
    stack<int> s;
    map<int, int> mp;
    vector<int> ans;
    ans.resize(nums1.size());
    for (int i = nums2.size(); i >= 0; i--)
    {
      while (!s.empty() && s.top() <= nums2[i])
      {
        s.pop();
      }
      mp[nums2[i]] = s.empty() ? -1 : s.top();
      s.push(nums2[i]);
    }
    for (int i = 0; i < nums1.size(); i++)
    {
      ans[i] = mp[nums1[i]];
    }
    return ans;
  }
};