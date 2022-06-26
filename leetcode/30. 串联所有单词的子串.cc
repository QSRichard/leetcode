#include <algorithm>
#include <ostream>
#include <vector>
#include <string>
#include <map>
#include <iostream>

using namespace std;

class Solution
{
public:
  vector<int> findSubstring(string s, vector<string>& words)
  {
    int t = words[0].size();
    map<string, int> mp;

    for (int i = 0; i < words.size(); i++)
      mp[words[i]]++;
    int begin = 0;
    int cur = 0;
    map<string, int> sp;
    vector<int> ans;
    int need = words.size();
    for (; cur < s.size();)
    {
      string str = s.substr(cur, t);
      sp[str]++;
      if (mp.find(str) != mp.end() && mp[str] >= sp[str])
      {
        // cout << "str " << str << " mp[str] " << mp[str] << " sp[str] " << sp[str] << endl;
        // cout << "cur " << cur << endl;
        cur += t;
        // cout << "cur " << cur << endl;
        need--;
        // cout << "need " << need << endl;
        // cout << "---------------------------" << endl;
      }
      else
      {
        begin++;
        cur = begin;
        need = words.size();
        sp.erase(sp.begin(), sp.end());
      }
      if (need == 0)
      {
        ans.push_back(begin);
        begin++;
        cur = begin;
        need = words.size();
        sp.erase(sp.begin(), sp.end());
      }
    }
    return ans;
  }
};

int main(int argc,char* argv[]){
  Solution solution;

  string s = "wordgoodgoodgoodbestword";
  vector<string> v = {"word", "good", "best", "word"};
  solution.findSubstring(s, v);

  return 0;
}