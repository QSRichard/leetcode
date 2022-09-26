#include <vector>
#include <string>
#include <stack>

using namespace std;

class Solution
{
public:
  int longestValidParentheses(string s)
  {
    if(s.empty())
    {
      return 0;
    }

    vector<int> dp(s.size() + 1, 0);

    for(int i = 0; i < s.size(); i++)
    {
      if(s[i] == '(')
      {
        
      }
    }
  }
};