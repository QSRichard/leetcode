#include <vector>
#include <algorithm>
#include <string>
#include <functional>

using namespace std;

class Solution
{
public:
  string longestPalindrome(string s)
  {

    function<string(int, int)> help = [&](int left, int right) -> string {
      while (left >= 0 && right < s.size() && s[left]==s[right])
      {
        left--;
        right++;
      }
      return s.substr(left, right - left + 1);
    };
    string ans;
    for (int i = 0; i < s.size(); i++)
    {
      string str1 = help(i, i);
      string str2 = help(i, i + 1);
      if (str1.size() > str2.size() && str1.size() > ans.size())
        ans = str1;
      else if (str2.size() > ans.size())
        ans = str2;
    }
    return ans;
  }

};