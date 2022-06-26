#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
public:
  string reverseWords(string s)
  {
    vector<string> base;
    int start = 0, end = s.size() - 1;
    while (start < s.size() && s[start] == ' ')
      start++;
    while (end >= start && s[end] == ' ')
      end--;
    vector<char> str;
    for (int i = start; i <= end;)
    {
      if (s[i] == ' ')
      {
        base.push_back(string(str.begin(), str.end()));
        str.clear();
        while (i <= end && s[i] == ' ')
          i++;
      }
      else
      {
        str.push_back(s[i]);
        i++;
      }
    }
    if (str.empty() == false)
      base.push_back(string(str.begin(), str.end()));
    reverse(base.begin(), base.end());
    string ans;
    for (int i = 0; i < base.size(); i++)
    {
      ans += base[i];
      if (i != base.size() - 1)
        ans += " ";
    }
    return ans;
  }
};