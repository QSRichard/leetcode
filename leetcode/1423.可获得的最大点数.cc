#include <vector>

using namespace std;

class Solution
{
public:
  void dfs(int left, int right, vector<int>& points, int k, int sum,int& ans)
  {
    if (left >= points.size())
      return;
    if (right < 0)
      return;
    if (left + right == k)
    {
      ans = max(ans, sum);
      return;
    }
    sum += points[left];
    left++;
    dfs(left, right, points, k, sum, ans);
    left--;
    sum -= points[left];
    sum += points[points.size() - 1 - right];
    right++;
    dfs(left, right, points, k, sum, ans);
    right--;
    sum -= points[points.size() - 1 - right];
  }
  int maxScore(vector<int>& cardPoints, int k)
  {
    int ans = -1;
    int sum = 0;
    dfs(0, 0, cardPoints, k, sum, ans);
    return ans;
  }
};