#include <vector>
#include <string>
#include <map>

using namespace std;

class Solution
{
public:
  vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values,
                              vector<vector<string>>& queries)
  {
    map<string, int> mp;
    int number = 0;
    vector<int> father(100, 0);
    vector<double> base(100, 1.0);
    for (int i = 0; i < father.size(); i++)
      father[i] = i;
    
    for (int i=0;i<equations.size();i++)
    {
      auto t = equations[i];
      if (mp.find(t[0]) == mp.end())
        mp[t[0]] = number++;
      if (mp.find(t[1]) == mp.end())
        mp[t[1]] = number++;
      int x = mp[t[1]];
      base[x] = values[i];
      father[x] = mp[t[0]];
      while (father[x] != x)
      {
        int tmp = father[x];
        base[x]=
        father[x] = father[tmp];
        x = tmp;
      }

    }
  }
};