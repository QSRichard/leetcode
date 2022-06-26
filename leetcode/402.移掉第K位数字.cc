#include <ios>
#include <vector>
#include <stack>
#include <map>
#include <string>
#include <iostream>

using namespace std;

class Solution
{
public:
  string removeKdigits(string num, int k)
  {
    if (num.size() == k)
      return "0";
    stack<int> s;
    vector<int> nextLess;
    nextLess.resize(num.size());
    for (int i = num.size() - 1; i >= 0; i--)
    {
      while (!s.empty() && num[s.top()] - '0' >= num[i] - '0')
      {
        s.pop();
      }
      nextLess[i] = s.empty() ? -1 : s.top();
      s.push(i);
    }
    // for (int i = 0; i < nextLess.size(); i++)
    // {
    //   cout << nextLess[i] << " ";
    // }
    // cout << endl;
    vector<char> index;
    int Count = k;
    int i;
    for (i = 0; i < num.size() && Count>0;)
    {
      int nextLessIndex = nextLess[i];
      if (nextLessIndex == -1)
      {
        // cout << "if 添加 " << num[i] << endl;
        index.push_back(num[i]);
        i++;
      }
      else if (nextLessIndex-i > Count)
      {
        // cout << "else if 添加 " << num[i] << endl;
        index.push_back(num[i]);
        i++;
      }
      else
      {
        Count = Count - (nextLessIndex - i);
        i = nextLessIndex;
        // cout << "Count " << Count << endl;
      }
    }

    string ans = string(index.begin(), index.end()) + num.substr(i, num.size() - i);

    int t = 0;
    while (t < ans.size() && ans[t] == '0')
      t++;
    if (t == ans.size())
      return "0";
    return ans.substr(t, num.size() - k);
  }
};

int main(int argc,char* argv[]){

  Solution solution;
  string num = "1432219";
  int k = 3;
  cout << solution.removeKdigits(num, k) << endl;
  return 0;
}

