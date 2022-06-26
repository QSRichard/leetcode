#include <pthread.h>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
  int maxProfit(vector<int>& prices)
  {
    int dp[prices.size()][2];
    dp[0][0] = 0;
    dp[0][1] = -prices[0];
    for (int i = 1; i < prices.size(); i++)
    {
      dp[i][0] = max(dp[i - 1][1] + prices[i], dp[i - 1][0]);
      dp[i][1] = max(dp[i - 1][1],- prices[i]);
    }
    return dp[prices.size() - 1][0];
  }
};

unordered_map<char, int> mp;
for (int i = 0; i < s.size(); i++)

