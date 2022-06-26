#include <cmath>
#include <vector>
#include <string>
#include <iostream>
#include <functional>

using namespace std;

class Solution
{
public:
  string countAndSay(int n)
  {
    
    function<string(string)> dfs;
    dfs = [&](string n) -> string{
      if (n == "1")
        return "1";
      int num = stoi(n);
      string child = dfs(to_string(num - 1));
      string ret = "";
      for (int i = 0; i < child.size();)
      {
        // cout<<"i"<<i<<endl;
        char ti = child[i];
        int count=0;
        while (i<child.size() && child[i] == ti)
        {
          i++;
          count++;
        }
        ret += (to_string(count).append(1, ti));
      }
      return ret;
    };
    return dfs(to_string(n));
  }
};

int main(int argc,char* argv[]){
  Solution solution;
  for (int i = 1; i <= 5; i++)
  {
    cout<<solution.countAndSay(i)<<endl;
  }
  return 0;
}