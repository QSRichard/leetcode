#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// 固定左上角
// class Solution
// {
// public:
//   int maximalSquare(vector<vector<char>>& matrix)
//   {

//     for(int i = 0; i < matrix.size(); i++)
//     {
//         for(int j = 0; j < matrix[0].size(); j++)
//         {
//             isValid(matrix, i, j);
//         }
//     }
//     return maxLen * maxLen;
//   }

// private:
//     int maxLen = 0;
//     void isValid(vector<vector<char>>& matrix, int x, int y)
//     {
//         if(x + maxLen > matrix.size() || y + maxLen > matrix[0].size())
//         {
//             return;
//         }

//         for(int len = maxLen + 1; len <= matrix.size(); len++)
//         {
//             if(!isAllOne(matrix, x, y, len))
//             {
//                 break;
//             }
//             maxLen = max(maxLen, len);
//         }
//     }

//     bool isAllOne(vector<vector<char>>& matrix, int x, int y, int Len)
//     {
//         if(x + Len > matrix.size() || y + Len > matrix[0].size())
//         {
//             return false;
//         }
//         for(int i = 0; i < Len; i++)
//         {
//             for(int j = 0; j < Len; j++)
//             {
//                 if(matrix[x + i][y + j] != '1')
//                 {
//                     return false;
//                 }
//             }
//         }
//         return true;
//     }
// };

// 固定右下角

class Solution
{
public:
  int maximalSquare(vector<vector<char>>& matrix)
  {
    vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), 0));
    int ans = 0;
    for(int i = 0; i < matrix[0].size(); i++)
    {
        dp[0][i] = matrix[0][i] - '0';
        ans = max(ans, dp[0][i]);
    }
    for(int i = 0; i < matrix.size(); i++)
    {
        dp[i][0] = matrix[i][0] - '0';
        ans = max(ans, dp[i][0]);
    }

    for(int i = 1; i < matrix.size(); i++)
    {
        for(int j = 1; j < matrix[0].size(); j++)
        {
            if(matrix[i][j] == '0')
            {
                dp[i][j] = 0;
            }
            else
            {
                dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
            }

            ans = max(ans, dp[i][j]);
        }
    }

    return ans * ans;
  }
};