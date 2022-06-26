#include <cctype>
#include <cmath>
#include <vector>
#include <string>
#include <stack>

using namespace std;

class Solution
{
public:
  int evalRPN(vector<string>& tokens)
  {
    stack<int> number;
    stack<char> s;
    for (int i = 0; i < tokens.size(); i++)
    {
      if (tokens[i].size() > 1 || isalnum(tokens[i][0]))
      {
        number.push(stoi(tokens[i]));
      }
      else
      {
        int x = number.top();
        number.pop();
        int y = number.top();
        number.pop();
        if (tokens[i] == "+")
        {
          number.push(x + y);
        }
        else if (tokens[i] == "*")
        {
          number.push(x * y);
        }
        else if (tokens[i] == "-")
        {
          number.push(y - x);
        }
        else if (tokens[i] == "/")
        {
          number.push(y / x);
        }
      }
    }
    return number.top();
  }
};