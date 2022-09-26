#include <cctype>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution
{
public:
  string decodeString(string s)
  {
    int index = 0;
    return Dfs(s, index);
  }

  string Dfs(string& s, int& index)
  {
    int num = 0;
    string tmp = "";
    while(index < s.size())
    {
        if(isdigit(s[index]))
        {
            num = num * 10 + s[index] - '0';
        }
        else if(isalpha(s[index]))
        {
            tmp.push_back(s[index]);
        }
        else if(s[index] == '[')
        {
            string ret = Dfs(s, ++index);
            for(int i = 0; i < num; i++)
            {
                tmp += ret;
            }
            num = 0;
        }
        else if(s[index] == ']')
        {
            return tmp;
        }
        index++;
    }
    return tmp;
  }
};