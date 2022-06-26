#include <vector>
#include <functional>
#include <map>

using namespace std;



class Solution
{
public:
  vector<double> dicesProbability(int n)
  {
    map<int, int> mp;
    int number = 0;
    function<void(int, int)> dfs;
    dfs = [&](int index, int sum) {
      if (index == n)
      {
        mp[sum]++;
        number++;
        return;
      }
      for (int i = 1; i <= 6; i++)
      {
        dfs(index + 1, sum + i);
      }
    };
    dfs(0, 0);
    vector<double> ans(5 * n + 1);
    int t = 0;
    for (auto& it : mp)
    {
      ans[t++] = it.second / (number * 1.0);
    }
    return ans;
  }
};
