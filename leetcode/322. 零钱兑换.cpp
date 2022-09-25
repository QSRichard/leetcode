#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class Solution
{
public:
  int coinChange(vector<int>& coins, int amount)
  {
    vector<int> dp(amount + 1);

    set<int> s;
    for(int i = 0; i < coins.size(); i++)
    {
        if(coins[i] <= amount)
        {
            dp[coins[i]] = 1;
            s.insert(coins[i]);
        }
    }
    int begin = *s.begin();
    for(int i = begin; i <= amount; i++)
    {
        for(auto it = s.begin(); it != s.end(); it++)
        {
            if(i - *it <= 0)
            {
                break;
            }
            if(dp[i - *it] != 0)
            {
                dp[i] = min(dp[i], dp[i - *it] + 1);
            }
        }  
    }
    return dp[amount] == 0 ? -1 : dp[amount];
  }
};