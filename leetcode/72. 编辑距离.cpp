#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  int minDistance(string word1, string word2)
  {
    vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));

    for (int i = 1; i <= word1.size(); i++)
    {
      dp[i][0] = i;
    }

    for (int i = 1; i <= word2.size(); i++)
    {
      dp[0][i] = i;
    }

    for (int i = 1; i <= word1.size(); i++)
    {
      for (int j = 1; j <= word2.size(); j++)
      {
        if (word1[i - 1] == word2[j - 1])
        {
          dp[i][j] = dp[i - 1][j - 1];
        }
        else
        {
          dp[i][j] = min(dp[i - 1][j - 1] + 1, min(dp[i - 1][j] + 1, dp[i][j - 1] + 1));
        }
      }
    }
    return dp[word1.size()][word2.size()];
  }

private:
  int dp(string& str1, string& str2, int i, int j)
  {
    if (i == -1)
    {
      return j + 1;
    }
    if (j == -1)
    {
      return i + 1;
    }

    if (str1[i] == str2[j])
    {
      return dp(str1, str2, i - 1, j - 1);
    }

    return min(dp(str1, str2, i, j - 1) + 1, min(dp(str1, str2, i - 1, j) + 1, dp(str1, str2, i - 1, j - 1) + 1));
  }
};