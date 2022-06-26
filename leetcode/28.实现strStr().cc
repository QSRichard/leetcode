#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
  int strStr(string haystack, string needle)
  {
    // 求解next数组

    return getFirstVis(haystack, needle);
  }

  int getFirstVis(string& str, string& patten)
  {
    vector<int> next(patten.size() + 1);
    getNextArray(next, patten);
    int i = 0, j = 0;
    if (str.size() < patten.size())
      return -1;
    for (; i < str.size() && j < patten.size();)
    {
      if (str[i] == patten[j])
      {
        i++,j++;
      }
      else
      {
        j = next[j];
        if (j == -1)
        {
          i++;j++;
        }
      }
    }
    if (j == patten.size())
      return i - j;
    return -1;
  }

private:
  void getNextArray(vector<int>& next, string& patten)
  {
    int k = -1;
    int j = 0;
    next[0] = -1;
    while (j < patten.size())
    {
      if (k == -1 || patten[j] == patten[k])
      {
        next[++j] = ++k;
      }
      else
      {
        k = next[k];
      }
    }
  }
};