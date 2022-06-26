#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
  int lengthOfLongestSubstring(string s)
  {
    if (s.empty())
      return 0;
    vector<int> base(257, -1);
    vector<int> dp(s.size(), 0);
    base[s[0]] = 0;
    dp[0] = 1;
    int ans = 1;
    for (int i = 1; i < s.size(); i++)
    {
      if (base[s[i]] == -1)
      {
        base[s[i]] = i;
        dp[i] = dp[i - 1] + 1;
        ans = max(ans, dp[i]);
      }
      else
      {
        int t = base[s[i]];
        dp[i] = (i - t);
        for (int x = 0; x < base.size(); x++)
          base[x] = -1;
        for (int y = t + 1; y <= i; y++)
          base[s[y]] = y;
      }
    }
    return ans;
  }
};