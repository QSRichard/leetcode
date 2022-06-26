#include <vector>
#include <string>
#include <queue>

using namespace std;

class Solution
{
public:
  vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites)
  {
    g.resize(numCourses);
    inNum.resize(numCourses);
    vector<int> ans;
    for (auto& it : prerequisites)
    {
      g[it[1]].push_back(it[0]);
      inNum[it[0]]++;
    }
    queue<int> q;
    for (int i = 0; i < numCourses; i++)
      if (inNum[i] == 0)
        q.push(i);
    while (!q.empty())
    {
      int t = q.front();
      ans.push_back(t);
      q.pop();
      for (int i = 0; i < g[t].size(); i++)
      {
        inNum[g[t][i]]--;
        if (inNum[g[t][i]] == 0)
          q.push(g[t][i]);
      }
    }
    if (ans.size() < numCourses)
      ans.clear();
    return ans;
  }

private:
  vector<vector<int>> g;
  vector<int> inNum;
};