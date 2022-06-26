#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
  vector<int> findAnagrams(string s, string p)
  {
    vector<int> sCount(26);
    vector<int> pCount(26);
    if (s.size() < p.size())
      return vector<int>();
    vector<int> ans;
    int plen = p.size();
    int slen = s.size();
    for (int i = 0; i < plen; i++)
    {
      sCount[s[i] - 'a']++;
      pCount[p[i] - 'a']++;
    }
    if (sCount == pCount)
      ans.push_back(0);
    for (int i = 0; i < slen - plen; i++)
    {
      sCount[s[i] - 'a']--;
      sCount[s[i + plen] - 'a']++;
      if (sCount == pCount)
        ans.push_back(i + 1);
    }
    return ans;
  }
  
};