#include <vector>
#include <map>
#include <stack>

using namespace std;

class Solution
{
public:
  vector<int> nextGreaterElements(vector<int>& nums)
  {
    int len = nums.size();
    vector<int> ans;
    ans.resize(nums.size());
    stack<int> s;
    for (int i = len * 2 - 1; i >= 0; i--)
    {
      while (!s.empty() && s.top() <= nums[i % len])
      {
        s.pop();
      }
      ans[i % len] = s.empty() ? -1 : s.top();
      s.push(nums[i % len]);
    }
    return ans;
  }
};