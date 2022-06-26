#include <string>
#include <vector>
#include <unordered_set>
#include <climits>

using namespace std;

class Solution
{
public:
  vector<string> wordBreak(string s, vector<string>& wordDict)
  {

    vector<vector<string>> ddpp(s.size() + 1);
    
    vector<int> dp(s.size() + 1, 0);
    unordered_set<string> base;
    int minLen = INT_MAX, maxLen = INT_MIN;
    for (int i = 0; i < wordDict.size(); i++)
    {
      minLen = min(minLen, (int)wordDict[i].size());
      maxLen = max(maxLen, (int)wordDict[i].size());
      base.insert(wordDict[i]);
    }

    dp[0] = 1;

    for (int i = 0; i < s.size(); i++)
    {
      for (int j = minLen; j <= maxLen; j++)
      {
        int last = i - j;
        if (last < -1)
          break;
        if (dp[last + 1] == 1 && base.find(s.substr(last + 1, j)) != base.end())
          dp[i + 1] = 1;
        if (dp[i + 1] == 1)
          break;
      }
    }
    return dp[s.size()] == 1 ? true : false;
  }
};