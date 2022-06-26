#include <deque>
#include <utility>
#include <vector>
#include <string>
#include <queue>

using namespace std;

class Solution
{
public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k)
  {
    deque<int> q;
    for (int i = 0; i < k; i++)
    {
      while (!q.empty() && nums[q.back()] <= nums[i])
      {
        q.pop_back();
      }
      q.push_back(i);
    }
    vector<int> ans = {nums[q.front()]};
    for (int i = k; i < nums.size(); i++)
    {
      while (!q.empty() && nums[q.back()] <= nums[i])
        q.pop_back();
      q.push_back(i);
      while (q.front() <= i - k)
        q.pop_front();
      ans.push_back(nums[q.front()]);
    }
    return ans;
  }
};