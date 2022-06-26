#include <vector>
#include <algorithm>
#include <string>
#include <functional>

using namespace std;

class Solution {
public:
  vector<vector<int>> permuteUnique(vector<int>& nums)
  {
    vector<int> vis(nums.size(), 0);
    vector<int> prem;
    vector<vector<int>> ans;
    function<void(int)> backTrack;
    backTrack = [&](int index) {
      if (index == nums.size())
      {
        ans.push_back(prem);
        return;
      }
      for (int i = 0; i < nums.size(); i++)
      {
        if (vis[i] == 1 || i > 0 && nums[i] == nums[i - 1] && vis[i - 1] == 0)
        {
          continue;
        }
        prem.push_back(nums[i]);
        vis[i] = 1;
        backTrack(index + 1);
        vis[i] = 0;
        prem.pop_back();
      }
    };
    sort(nums.begin(), nums.end());
    backTrack(0);
    return ans;
  }
};