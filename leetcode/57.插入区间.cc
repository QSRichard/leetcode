#include <vector>
#include <iostream>
#include <functional>

using namespace std;

class Solution
{
public:
  vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval)
  {
    vector<vector<int>> ans;
    function<bool(vector<int>&, vector<int>&)> corver;
    corver = [&](vector<int>& v1, vector<int>& v2) -> bool {
      
    };
    int i, j;
    for (i = 0; i < intervals.size(); i++)
    {
      if (corver(intervals[i], newInterval))
        break;
      ans.push_back(intervals[i]);
    }
    for (j = i; j < intervals.size(); j++)
    {
      if (corver(intervals[j], newInterval) == false)
        break;
    }
    ans.push_back({min(intervals[i][0], newInterval[0]), max(intervals[j][1], newInterval[1])});
    for (++j; j < intervals.size(); j++)
      ans.push_back(intervals[j]);
    return ans;
  }
};