#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution
{
public:
  int maxProfit(vector<int>& prices)
  {

    int days = prices.size();

    int dp[days][2][3];
    for (int i = 0; i < days; i++)
    {
      for (int j = 0; j < 2; j++)
      {
        dp[i][j][0] = dp[i][j][1] = dp[i][j][2] = 0;
      }
    }
    dp[0][0][2] = 0, dp[0][1][1] = -prices[0];
    dp[0][0][1] = 0, dp[0][1][2] = -prices[0];
    
    for (int i = 1; i < days; i++)
    {
      for (int k = 2; k >= 1; k--)
      {
        dp[i][0][k] = max(dp[i - 1][1][k] + prices[i], dp[i - 1][0][k]);
        dp[i][1][k] = max(dp[i - 1][0][k - 1] - prices[i], dp[i - 1][1][k]);
      }
    }
    return dp[days - 1][0][2];
  }
};
