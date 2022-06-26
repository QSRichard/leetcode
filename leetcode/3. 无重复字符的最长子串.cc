#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
  int lengthOfLongestSubstring(string s)
  {
    int left = 0, right = 0;
    int ans = 0;
    vector<int> vis(300, 0);
    while (right < s.size())
    {
      vis[s[right]]++;
      if (vis[s[right]] == 2)
      {
        while (vis[s[right]] == 2)
        {
          vis[s[left]]--;
          left++;
        }
        right++;
      }
      else
      {
        right++;
        ans = max(ans, (right - left));
      }
    }
    return ans;
  }
};