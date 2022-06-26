#include <string>
#include <utility>
#include <vector>
#include <map>
#include <functional>
#include <algorithm>

using namespace std;

class Solution
{
public:
  vector<string> permutation(string s)
  {
    vector<char> base;
    for (int i = 0; i < s.size(); i++)
      base.push_back(s[i]);
    
    sort(base.begin(), base.end());

    vector<int> vis(s.size(), 0);
    vector<string> ans;
    vector<char> cur;
    function<void(int)> dfs;

    dfs = [&](int index) {
      
      if (cur.size() == base.size())
      {
        ans.push_back(string(cur.begin(), cur.end()));
        return;
      }

      for (int i = 0; i < base.size(); i++)
      {
        if (vis[i] == 0)
        {
          if (i > 0 && base[i] == base[i - 1] && vis[i - 1] == 0)
            continue;
          vis[i] = 1;
          cur.push_back(base[i]);
          dfs(index++);
          vis[i] = 0;
          cur.pop_back();
        } 
      }
    };

    dfs(0);
    return ans;
  }
};