#include <deque>
#include <functional>
#include <vector>
#include <map>
#include <climits>
#include <math.h>
#include <queue>

using namespace std;

class Solution
{
public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k)
  {
    if (nums.empty())
      return {};
    priority_queue<int, deque<int>, less<int>> q;

    for (int i = 0; i < k; i++)
      q.push(nums[i]);
    vector<int> ans(nums.size() - k + 1);
    int left = 0;
    int right = k - 1;
    int t = 0;
    while (right < nums.size())
    {
      ans[t++] = q.top();
      if (nums[left] == q.top())
        q.pop();
      
      q.push(nums[cur++]);
    }
    return ans;
  }
};