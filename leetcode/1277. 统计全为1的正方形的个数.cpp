#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
  int countSquares(vector<vector<int>>& matrix)
  {
    vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), 0));
    int ans = 0;
    for(int i = 0; i < matrix.size(); i++)
    {
        for(int j = 0; j < matrix[0].size(); j++)
        {
            if(i == 0 || j == 0)
            {
                dp[i][j] = matrix[i][j];
            }
            else if(matrix[i][j] == 1)  // 右下角为 1
            {
                dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
            }
            // 以 i, j为右下角的正方形个数
            ans += dp[i][j];
        }
    }
    return ans;
  }
};