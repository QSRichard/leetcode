#include <functional>
#include <utility>
#include <vector>
#include <algorithm>
#include <algorithm>
#include <map>

using namespace std;

class Solution
{
public:
  vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
  {
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> ans;
    vector<int> cur;
    if (candidates.empty() || candidates[0] > target)
      return ans;
    vector<pair<int, int>> base;
    map<int,int> mp;
    for (auto& i : candidates)
      mp[i]++;
    for (auto& it : mp)
      base.push_back({it.first, it.second});
    function<void(int, int)> dfs;
    dfs = [&](int index, int sum) {
      if (sum == target)
      {
        ans.push_back(cur);
        return;
      }
      if (index >= base.size() || target - sum < base[index].first)
        return;

      dfs(index + 1, sum);

      for (int i = 1; i <= base[index].second; i++)
      {
        for (int j = 0; j < i; j++)
          cur.push_back(base[index].first);
        dfs(index + 1, sum + i * base[index].first);
        for (int j = 0; j < i; j++)
          cur.pop_back();
      }
    };
    dfs(0, 0);
    return ans;
  }
};