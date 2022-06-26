#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
  int lengthOfLastWord(string s)
  {
    int ans = 0;
    for (int i = s.size() - 1; i >= 0;)
    {
      while (i>=0 && s[i] == ' ')
        i--;
      while (i >= 0 && isalpha(s[i]))
      {
        ans++;
        i--;
      }
      if (i < 0 || s[i] == ' ')
        break;
      ans = 0;
      while (s[i] != ' ')
        i--;
    }
    return ans;
  }
};