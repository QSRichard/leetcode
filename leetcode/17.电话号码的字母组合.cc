#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <iostream>
#include <functional>

using namespace std;

class Solution
{
public:
  vector<string> letterCombinations(string digits)
  {
    map<char, vector<char>> base{{'2', {'a', 'b', 'c'}}, {'3', {'d', 'e', 'f'}},     {'4', {'g', 'h', 'i'}},
                                 {'5', {'j', 'k', 'l'}}, {'6', {'m', 'n', 'o'}},     {'7', {'p', 'q', 'r', 's'}},
                                 {'8', {'t', 'u', 'v'}}, {'9', {'w', 'x', 'y', 'z'}}};

    vector<string> ans;
    string str;
    // str.append(digits.size(), 'A');
    str.resize(digits.size());
    function<void(string&, int)> dfs;
    dfs = [&](string& digits, int index) {
      cout<<"entry dfs"<<endl;
      if (index >= digits.size())
      {
        ans.push_back(str);
        // cout<<"push_back"<<endl;
        return;
      }
      cout<<base[digits[index]].size()<<endl;
      for (int i = 0; i < base[digits[index]].size(); i++)
      {
        str[index] = base[digits[index]][i];
        dfs(digits,index+1);
      }
    };
    dfs(digits, 0);
    return ans;
  }
};

int main(int argc, char* argv[])
{
  Solution solution;
  solution.letterCombinations("23");
  return 0;
}