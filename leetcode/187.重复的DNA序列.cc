#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
#include <set>
#include <map>

using namespace std;

class Solution
{
public:
  vector<string> findRepeatedDnaSequences(string s)
  {
    map<string,int> base;
    if (s.size() <= 10)
      return vector<string>();
    vector<string> ans;
    base[s.substr(0, 10)] = 1;
    int left = 1, right = left + 9;
    for (; left < s.size() - 9; left++)
    {
      string str = s.substr(left, 10);
      base[str]++;
      if (base[str] == 2)
        ans.push_back(str);
    }
    return ans;
  }
};