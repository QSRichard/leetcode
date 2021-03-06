#include <cstring>
#include <vector>

using namespace std;

class Solution
{
public:
  int maxValue(vector<vector<int>>& grid)
  {
    int dp[grid.size()][grid[0].size()];
    memset(dp, 0, sizeof dp);
    dp[0][0] = grid[0][0];
    int i, j;
    for (int i = 1; i < grid.size(); i++)
      dp[i][0] = grid[i][0] + dp[i - 1][0];
    for (int j = 1; j < grid[0].size(); j++)
      dp[0][j] = grid[0][j] + dp[0][j - 1];
    
    for (int i = 1; i < grid.size(); i++)
    {
      for (int j = 1; j < grid[0].size(); j++)
      {
        dp[i][j] = max(dp[i - 1][j] + grid[i][j], dp[i][j - 1] + grid[i][j]);
      }
    }
    return dp[grid.size() - 1][grid[0].size() - 1];
  }
};