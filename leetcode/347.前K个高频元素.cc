#include <utility>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;


class Solution
{
public:
  static bool cmp(pair<int, int>& a, pair<int, int>& b)
  {
    return a.second > b.second;
  }
  vector<int> topKFrequent(vector<int>& nums, int k)
  {
    map<int, int> mp;
    for (int i = 0; i < nums.size(); i++)
      mp[nums[i]]++;

    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&cmp)> q(cmp);
    for (auto& [val, count] : mp)
    {
      if (q.size() == k)
      {
        if (q.top().second < count)
        {
          q.pop();
          q.emplace(val, count);
        }
      }
      else
      {
        q.emplace(val, count);
      }
    }
    vector<int> ret;
    while (!q.empty())
    {
      ret.emplace_back(q.top().first);
      q.pop();
    }
    return ret;
  }
};