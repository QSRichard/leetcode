#include <memory>
#include <vector>
#include <climits>

using namespace std;

class Solution
{
public:
  int minimumTotal(vector<vector<int>>& triangle)
  {
    int len = triangle[triangle.size() - 1].size();
    vector<int> dp(len, 0);
    dp[0] = triangle[0][0];
    for (int i = 1; i < triangle.size(); i++)
    {
      for (int j = triangle[i].size() - 1; j >= 0; j--)
      {
        if (j == triangle[i].size() - 1)
        {
          dp[j] = dp[j - 1] + triangle[i][j];
          continue;
        }
        if (j != 0)
          dp[j] = min(dp[j] + triangle[i][j], dp[j - 1] + triangle[i][j]);
        else
          dp[j] = dp[j] + triangle[i][j];
      }
    }
    int ans = INT_MAX;
    for (int i = 0; i < len; i++)
      ans = min(ans, dp[i]);
    return ans;
  }
};