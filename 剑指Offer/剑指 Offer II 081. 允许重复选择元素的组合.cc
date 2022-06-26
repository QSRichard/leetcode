#include <algorithm>
#include <functional>
#include <vector>

using namespace std;

class Solution
{
public:
  vector<vector<int>> combinationSum(vector<int>& candidates, int target)
  {
    vector<vector<int>> ans;
    vector<int> prem;
    sort(candidates.begin(), candidates.end());
    function<void(int, int)> dfs;

    dfs = [&](int index, int sum) {
      if (sum == target)
      {
        ans.push_back(prem);
        return;
      }
      if (sum > target)
        return;
      if (index >= candidates.size() || candidates[index] > target - sum)
        return;
      prem.push_back(candidates[index]);
      dfs(index, sum += candidates[index]);
      prem.pop_back();

      dfs(index + 1, sum);
    };
    dfs(0, 0);
    return ans;
  }
};