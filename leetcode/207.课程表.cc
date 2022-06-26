#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

class Solution
{
private:
  vector<vector<int>> g;
  vector<int> inNum;
public:
  bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
  {
    g.resize(numCourses);
    inNum.resize(numCourses);
    for (auto& it : prerequisites)
    {
      g[it[1]].push_back(it[0]);
      inNum[it[0]]++;
    }
    queue<int> q;
    int visit = 0;
    for (int i = 0; i < numCourses; i++)
    {
      if (inNum[i] == 0)
        q.push(i);
    }

    while (!q.empty())
    {
      int t = q.front();
      q.pop();
      visit++;
      for (int i = 0; i < g[t].size(); i++)
      {
        inNum[g[t][i]]--;
        if (inNum[g[t][i]] == 0)
          q.push(g[t][i]);
      }
    }
    if (visit == numCourses)
      return true;
    return false;
  }
};