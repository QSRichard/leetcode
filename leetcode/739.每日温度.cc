#include <vector>
#include <stack>
#include <map>

using namespace std;

class Solution
{
public:
  vector<int> dailyTemperatures(vector<int>& temperatures)
  {
    stack<int> s;
    vector<int> ans;
    ans.resize(temperatures.size());
    for (int i = temperatures.size() - 1; i >= 0; i--)
    {
      while (!s.empty() && temperatures[s.top()] <= temperatures[i])
        s.pop();
      ans[i] = s.empty() ? 0 : s.top() - i;
      s.push(i);
    }
    return ans;
  }
};