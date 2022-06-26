#include <functional>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
  vector<string> restoreIpAddresses(string s)
  {
    vector<string> ans;
    function<void(int, vector<string>&)> dfs;
    dfs = [&](int index, vector<string>& cur) {
      if (s.size() - index < 4 - cur.size() || s.size() - index > 3 * (4 - cur.size()))
        return;
      if (cur.size() == 4)
      {
        string str = "";
        for (int i = 0; i < 3; i++)
          str += (cur[i] + ".");
        str += cur[3];
        ans.push_back(str);
        return;
      }
      if (index >= s.size())
        return;
      // 截取一位
      cur.push_back(s.substr(index, 1));
      dfs(index + 1, cur);
      cur.pop_back();

      // 截取两位
      if (index + 2 <= s.size())
      {
        int num = stoi(s.substr(index, 2));
        if (num > 9)
        {
          cur.push_back(s.substr(index, 2));
          dfs(index + 2, cur);
          cur.pop_back();
        }
      }

      // 截取三位
      if (index + 3 <= s.size())
      {
        int num = stoi(s.substr(index, 3));
        if (num <= 255 && num > 99)
        {
          cur.push_back(s.substr(index, 3));
          dfs(index + 3, cur);
          cur.pop_back();
        }
      }
    };
    vector<string> cur;
    dfs(0, cur);
    return ans;
  }
};

int main(int argc,char* argv[]){

  Solution solution;
  string s = "101023";
  auto ans = solution.restoreIpAddresses(s);
  for (auto& it : ans)
  {
    cout << it << endl;
  }
  return 0;
}