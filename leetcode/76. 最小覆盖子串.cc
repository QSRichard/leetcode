#include <string>
#include <vector>
#include <climits>

using namespace std;

class Solution
{
public:
  string minWindow(string s, string t)
  {

    if (t.size() > s.size())
      return "";
    int left = 0, right = 0;
    int need = t.size();
    int size = INT_MAX;
    int begin;
    vector<int> tmp(289, 0);
    for (int i = 0; i < t.size(); i++)
      tmp[t[i]]++;

    for (; right < s.size();)
    {
      --tmp[s[right]];
      if (tmp[s[right]] >= 0)
        need--;
      if (need == 0)
      {
        while (need==0)
        {
          tmp[s[left]]++;
          if (tmp[s[left]] > 0)
            need++;
          left++;
        }
        if (right - left < size)
        {
          size = right - left + 1;
          begin = left - 1;
        }
      }
      right++;
    }
    if (size == INT_MAX)
      return "";
    return s.substr(begin, size + 1);
    
  }
};