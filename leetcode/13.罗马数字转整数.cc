#include <algorithm>
#include <map>
#include <string>
#include <utility>
#include <vector>

using namespace std;

class Solution
{
public:
  int romanToInt(string s)
  {
    int ans = 0;
    map<char, int> base = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
    int len = s.size();
    for (int i = 0; i < len;)
    {
      if (i<len && s[i] < s[i + 1])
      {
        ans += (base[s[i + 1]] - base[s[i]]);
        i += 2;
      }
      else
      {
        ans += base[s[i]];
        i++;
      }
    }
    return ans;
  }
};